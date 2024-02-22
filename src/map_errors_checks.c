/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:43:55 by atonkopi          #+#    #+#             */
/*   Updated: 2024/02/21 19:29:10 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid_format(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strncmp(filename + len - 4, ".ber", ft_strlen(filename)) == 0);
}

int	valid_tiles(t_vars *game)
{
	int	i;
	int	j;

	i = 0;
	if (!game->map[i])
		return (0);
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_weight)
		{
			if ((game->map[i][j] != END && game->map[i][j] != WALL && game->map[i][j] != FREE
					&& game->map[i][j] != PLAYER) && game->map[i][j] != ITEM)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_num_of_tiles(t_vars *game)
{
	int	i;
	int	j;
	int	player;
	int	end;
	int	item;

	i = 0;
	player = 0;
	end = 0;
	item = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_weight)
		{
			if (game->map[i][j] == PLAYER)
				player++;
			else if (game->map[i][j] == END)
				end++;
			else if (game->map[i][j] == ITEM)
				item++;
			j++;
		}
		i++;
	}
	if (end == 1 && item >= 1 && player == 1)
		return (1);
	return (0);
}

int	valid_rectangular(t_vars *game)
{
	int i;
    
    i = 0;
	while (i < game->map_height)
	{
		if ((int)ft_strlen(game->map[i++]) != game->map_weight)
			return (0);
		i++;
	}
	return (1);
}

int	valid_top_and_bottom(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == '1')
		i++;
	return (line[i] == '\0');
}

int	valid_left_and_right(char *line)
{
	int	i;

	if (line[0] != '1')
		return (0);
	i = 0;
	while (line[i])
		i++;
	if (line[i - 1] == '1')
		return (1);
	return (0);
}

int valid_walls(t_vars *game)
{
	int i;
   	
	i = 0;
  	while(game->map[i])
	{
		if (i == 0 || i == game->map_height)
		{
			if (!valid_top_and_bottom(game->map[i]))
				return (0);
		}
		else if (!valid_left_and_right(game->map[i]))
			return (0);
		i++;
	}
	return (1);
}

int valid_path(t_vars *game)
{
	(void)game;
    return 1;
}