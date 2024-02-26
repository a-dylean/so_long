/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:47:04 by atonkopi          #+#    #+#             */
/*   Updated: 2024/02/26 15:17:30 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	flood_fill(t_vars *game, int x, int y, int flag)
{
	if (flag == 1)
	{
		if (x < 0 || y < 0 || x >= game->map_weight || y >= game->map_height
			|| game->map_copy[y][x] == 'V' || game->map_copy[y][x] == 'X')
			return ;
		game->map_copy[y][x] = 'X';
	}
	else
	{
		if (x < 0 || y < 0 || x >= game->map_weight || y >= game->map_height
			|| game->map_copy[y][x] == WALL || game->map_copy[y][x] == 'V')
			return ;
		game->map_copy[y][x] = 'V';
	}
	flood_fill(game, x + 1, y, flag);
	flood_fill(game, x - 1, y, flag);
	flood_fill(game, x, y + 1, flag);
	flood_fill(game, x, y - 1, flag);
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
	flood_fill(game, game->player_pos_y, game->player_pos_x, 0);
	flood_fill(game, game->player_pos_y, game->player_pos_x, 1);
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_weight)
		{
			printf("%c\n", game->map_copy[i][j]);
			if (game->map_copy[i][j] == KEY || game->map_copy[i][j] == END)
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
