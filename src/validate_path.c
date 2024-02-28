/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:47:04 by atonkopi          #+#    #+#             */
/*   Updated: 2024/02/28 14:21:36 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	flood_fill(t_vars *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map_weight || y >= game->map_height
		|| game->map_copy[y][x] == WALL)
		return ;
	if (game->map_copy[y][x] == KEY)
		game->keys_collected++;
	if (game->map_copy[y][x] == END)
	{
		game->exit_found = 1;
		if (game->keys_count == game->keys_collected)
			game->map_copy[y][x] = WALL;
		return ;
	}
	if (game->map_copy[y][x] == KEY || game->map_copy[y][x] == FREE)
		game->map_copy[y][x] = WALL;
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

static void	player_position(t_vars *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_weight)
		{
			if (game->map[i][j] == PLAYER)
			{
				game->player_pos_y = j;
				game->player_pos_x = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	valid_path(t_vars *game)
{
	int	i;
	int	j;

	i = 0;
	player_position(game);
	flood_fill(game, game->player_pos_y, game->player_pos_x);
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_weight)
		{
			if (game->map_copy[i][j] == KEY || game->exit_found == 0)
			{
				game->msg_error = "Invalid path detected\n";
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_tiles(t_vars *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_weight)
		{
			if ((game->map[i][j] != END && game->map[i][j] != WALL
					&& game->map[i][j] != FREE && game->map[i][j] != PLAYER
					&& game->map[i][j] != KEY))
			{
				game->msg_error = "Invalid component in the map\n";
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
