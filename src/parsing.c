/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:31 by atonkopi          #+#    #+#             */
/*   Updated: 2024/02/21 17:30:18 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parse_map(char *path_to_map)
{
	char	**map;

	map = get_map(path_to_map);
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
