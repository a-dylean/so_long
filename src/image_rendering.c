/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:27:50 by atonkopi          #+#    #+#             */
/*   Updated: 2024/02/25 16:02:01 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	render_image(t_vars *game, void *img)
{
	mlx_put_image_to_window(game->mlx, game->win, img, game->pos_x * SIZE,
		game->pos_y * SIZE);
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
				render_image(game, game->wall);
			else if (game->map[game->pos_y][game->pos_x] == FREE)
				render_image(game, game->free);
			else if (game->map[game->pos_y][game->pos_x] == PLAYER)
				render_image(game, game->player);
			else if (game->map[game->pos_y][game->pos_x] == END)
				render_image(game, game->end);
			else if (game->map[game->pos_y][game->pos_x] == KEY)
				render_image(game, game->key);
			game->pos_x++;
		}
		game->pos_y++;
	}
	return (0);
}

static int	next_tile_check(t_vars *game, int *current_position)
{
	char	tile;

	tile = game->map[game->player_pos_x][game->player_pos_y];
	if (tile != WALL && tile != END)
	{
		game->steps++;
		game->map[game->player_pos_x][game->player_pos_y] = PLAYER;
		game->map[current_position[0]][current_position[1]] = FREE;
		ft_printf("Steps: %d\n", game->steps);
	}
	else if (tile == WALL || (tile == END
			&& game->keys_collected != game->keys_count))
	{
		game->player_pos_x = current_position[0];
		game->player_pos_y = current_position[1];
	}
	if (tile == KEY)
		game->keys_collected++;
	else if (tile == END && game->keys_collected == game->keys_count)
	{
		game->steps++;
		ft_printf("You won in %d steps. Can you do better?\n", game->steps);
		close_game(game);
	}
	return (0);
}

static int	handle_keys(int keycode, t_vars *game)
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

int	key_hook(int keycode, t_vars *game)
{
	int	current_position[2];

	current_position[0] = game->player_pos_x;
	current_position[1] = game->player_pos_y;
	if (!handle_keys(keycode, game))
		return (0);
	next_tile_check(game, current_position);
	return (0);
}
