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

int	valid_tiles(char **map)
{
	int	i;
	int	j;

	i = 0;
	if (!map[i])
		return (0);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] != END && map[i][j] != WALL && map[i][j] != FREE
					&& map[i][j] != PLAYER) && map[i][j] != ITEM)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// int contains_only_end_or_wall(char **array)
// {
//     if (array == NULL)
//         return (0);

//     for (int i = 0; array[i] != NULL; i++)
//     {
//         for (int j = 0; array[i][j] != '\0'; j++)
//         {
//             if (array[i][j] != END && array[i][j] != WALL
//	&& array[i][j] != FREE && array[i][j] != PLAYER && array[i][j] != ITEM)
//                 return (0); // Found a character that is not END or WALL
//         }
//     }

//     return (1); // All characters are either END or WALL
// }

int	valid_num_of_tiles(char **map)
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
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == PLAYER)
				player++;
			else if (map[i][j] == END)
				end++;
			else if (map[i][j] == ITEM)
				item++;
			j++;
		}
		i++;
	}
	if (end == 1 && item >= 1 && player == 1)
		return (1);
	return (0);
}

int	valid_rectangular(char **map)
{
	int i;
	size_t len;
    
    i = 0;
	len = ft_strlen(map[0]);
	i++;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int valid_walls(char **map)
{
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
    return 1;
}