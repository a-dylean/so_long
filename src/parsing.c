/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:31 by atonkopi          #+#    #+#             */
/*   Updated: 2024/02/21 19:28:37 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parse_input(char *path_to_map)
{
	char	**map;

	if (!valid_format(path_to_map))
		print_error("Invalid map format!");
	map = get_map(path_to_map);
	// int i = 0;
	// while (map[i])
	// {
	//     printf("%s", map[i]);
	//     i++;
	// }
	// printf("%d\n", valid_tiles(map));
	if (!valid_tiles(map) || !valid_num_of_tiles(map) || !valid_rectangular(map)
		|| !valid_walls(map) || !valid_path(map))
		print_error("Invalid map!");
	free_2d_array(map);
}

char	**get_map(char *path_to_map)
{
	int		lines_count;
	char	**map;

	lines_count = count_input_lines(path_to_map);
	map = malloc(sizeof(char *) * (lines_count + 1));
	if (!map)
		return (NULL);
	populate_map(path_to_map, map);
	map[lines_count] = NULL;
	return (map);
}
