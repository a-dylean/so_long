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
			printf("map[%d][%d]: %c\n", i, j, game->map[i][j]);
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
		printf("[%d] len map: %ld\n", i, ft_strlen(game->map[i]));
		// if ((int)ft_strlen(game->map[i++]) != game->map_weight)
		// 	return (0);
		i++;
	}
	return (1);
}


int valid_walls(char **map)
{
    (void)map;
	// if (map == NULL || map[0] == NULL)
    //     return 0; // The map is NULL or empty

    // // Check the first and last strings
    // for (int i = 0; i < 2; i++)
    // {
    //     int index = i == 0 ? 0 : strlen(map) - 1;
    //     for (int j = 0; map[index][j] != '\0'; j++)
    //     {
    //         if (map[index][j] != '1')
    //             return 0; // Found a character that is not '1'
    //     }
    // }

    // // Check the first and last character of each string
    // for (int i = 0; map[i] != NULL; i++)
    // {
    //     if (map[i][0] != '1' || map[i][strlen(map[i]) - 1] != '1')
    //         return 0; // Found a string that does not start or end with '1'
    // }

    return 1; // All checks passed
}

int valid_path(char **map)
{
	(void)map;
    return 1;
}