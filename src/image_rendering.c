/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:27:50 by atonkopi          #+#    #+#             */
/*   Updated: 2024/02/23 15:38:25 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	create_images(t_vars *game)
{
	int	pos[2];

	game->player = mlx_xpm_file_to_image(game->mlx, PATH_PLAYER, &pos[0],
			&pos[1]);
	game->end = mlx_xpm_file_to_image(game->mlx, PATH_END, &pos[0], &pos[1]);
	game->wall = mlx_xpm_file_to_image(game->mlx, PATH_WALL, &pos[0], &pos[1]);
	game->free = mlx_xpm_file_to_image(game->mlx, PATH_FREE, &pos[0], &pos[1]);
	game->key = mlx_xpm_file_to_image(game->mlx, PATH_KEY, &pos[0], &pos[1]);
}

int	render_images(t_vars *game)
{
	game->pos_y = 0;
	while (game->pos_y < game->map_height)
	{
		game->pos_x = 0;
		while (game->pos_x < game->map_weight)
		{
			if (game->map[game->pos_y][game->pos_x] == WALL)
				mlx_put_image_to_window(game->mlx, game->window, game->wall,
					game->pos_x * SIZE, game->pos_y * SIZE);
			else if (game->map[game->pos_y][game->pos_x] == FREE)
				mlx_put_image_to_window(game->mlx, game->window, game->free,
					game->pos_x * SIZE, game->pos_y * SIZE);
			else if (game->map[game->pos_y][game->pos_x] == PLAYER)
				mlx_put_image_to_window(game->mlx, game->window, game->player,
					game->pos_x * SIZE, game->pos_y * SIZE);
			else if (game->map[game->pos_y][game->pos_x] == END)
				mlx_put_image_to_window(game->mlx, game->window, game->end,
					game->pos_x * SIZE, game->pos_y * SIZE);
			else if (game->map[game->pos_y][game->pos_x] == KEY)
				mlx_put_image_to_window(game->mlx, game->window, game->key,
					game->pos_x * SIZE, game->pos_y * SIZE);
			game->pos_x++;
		}
		game->pos_y++;
	}
	return (0);
}

int next_tile_check(t_vars *game, int *current_position)
{
	char tile;

	tile = game->map[game->player_pos_x][game->player_pos_y];
	if (tile != WALL && tile != END)
	{
		game->steps++;
		game->map[game->player_pos_x][game->player_pos_y] = PLAYER;
		game->map[current_position[0]][current_position[1]] = FREE;
		ft_printf("Steps: %d\n", game->steps);
	}
	else if (tile == WALL || (tile == END && game->keys_collected != game->keys))
	{
		game->player_pos_x = current_position[0];
		game->player_pos_y = current_position[1];
	}
	if (tile == KEY)
		game->keys_collected++;
	else if (tile == END && game->keys_collected == game->keys)
	{
		game->steps++;
		game->map[game->player_pos_x][game->player_pos_y] = PLAYER;
		game->map[current_position[0]][current_position[1]] = FREE;
		ft_printf("You won in %d steps. Can you do better next time?\n", game->steps);
		close_game(game);
	}
	return (0);
}

int	handle_keys(int keycode, t_vars *game)
{
	if (keycode == UP)
		game->player_pos_x--;
	else if (keycode == DOWN)
		game->player_pos_x++;
	else if (keycode == LEFT)
		game->player_pos_y--;
	else if (keycode == RIGHT)
		game->player_pos_y++;
	else if (keycode == ESC)
		close_game(game);
	else 
		return (0);
	return (1);
}

int key_hook(int keycode, t_vars *game)
{
	int current_position[2];

	current_position[0] = game->player_pos_x;
	current_position[1] = game->player_pos_y;
	if (!handle_keys(keycode, game))
		return (0);
	next_tile_check(game, current_position);
	render_images(game);
	return (0);
}

int	close_game(t_vars *game)
{
	mlx_destroy_image(game->mlx, game->end);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->free);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->key);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_2d_array(game->map);
	free_2d_array(game->map_copy);
	exit(0);
	return (0);
}
