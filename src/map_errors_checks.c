/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:43:55 by atonkopi          #+#    #+#             */
/*   Updated: 2024/02/23 15:38:00 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid_format(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	return (ft_strncmp(filename + len - 4, ".ber", ft_strlen(filename)) == 0);
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
			if ((game->map[i][j] != END && game->map[i][j] != WALL && game->map[i][j] != FREE
					&& game->map[i][j] != PLAYER && game->map[i][j] != KEY))
					{
						game->msg_error = "Invalid component in the map or map is not rectangular\n";
						return (0);
					}
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

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_weight)
		{
			if (game->map[i][j] == PLAYER)
				game->player_count++;
			else if (game->map[i][j] == END)
				game->end_count++;
			else if (game->map[i][j] == KEY)
				game->keys_count++;
			j++;
		}
		i++;
	}
	if (game->end_count == 1 && game->keys_count >= 1 && game->player_count == 1)
		return (1);
	game->msg_error = "Invalid number of required components in the map\n";
	return (0);
}

int	valid_rectangular(t_vars *game)
{
	int i;
    
    i = 1;
	while (i < game->map_height)
	{
		if ((int)ft_strlen(game->map[i]) != game->map_weight)
		{
			game->msg_error = "Map is not rectangular\n";
			return (0);
		}
		i++;
	}
	return (1);
}

int	valid_top_and_bottom(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == WALL)
		i++;
	return (line[i] == '\0');
}

int	valid_left_and_right(char *line)
{
	int	i;

	if (line[0] != WALL)
		return (0);
	i = 0;
	while (line[i])
		i++;
	if (line[i - 1] == WALL)
		return (1);
	return (0);
}

int valid_walls(t_vars *game)
{
	int i;
   	
	i = 0;
  	while(game->map[i])
	{
		if (i == 0 || i == game->map_height - 1)
		{
			if (!valid_top_and_bottom(game->map[i]))
			{
				game->msg_error = "Invalid top or bottom wall\n";
				return (0);
			}
		}
		else if (!valid_left_and_right(game->map[i]))
		{
			game->msg_error = "Invalid left or right wall\n";
			return (0);
		}
		i++;
	}
	return (1);
}
