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

int	key_hook(int keycode, t_vars *game)
{
	// (void) keycode;
	// (void)game;
	if (keycode == 1)
	{
		printf("1");
		game->map[game->player_pos_x][game->player_pos_y] = FREE;
		game->map[game->player_pos_x + 1][game->player_pos_y] = PLAYER;
		game->player_pos_x++;
	}
	if (keycode == 13)
		printf("13");
	if (keycode == 0)
		printf("0");
	if (keycode == 2)
		printf("2");
	//render_images(game);
	return (0);
}

int	exit_hook(t_vars *game)
{
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	return(0);
}