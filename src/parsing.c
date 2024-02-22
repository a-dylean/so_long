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

void	parse_input(char *path_to_map, t_vars *game)
{
	if (!valid_format(path_to_map))
		print_error("Invalid map format!");
	game->map = get_map(path_to_map);
	game->map_height = count_input_lines(path_to_map);
	// game->map = malloc(game->map_height * sizeof(char *) + 1);
	// if (!game->map)
	// 	print_error("Malloc failed");
	// populate_map(path_to_map, game->map);
	// int i = 0;
	// while (game->map[i])
	// {
	//     printf("%s", game->map[i]);
	//     i++;
	// }
	game->map_weight = ft_strlen(game->map[0]);
	//valid_num_of_tiles(game);
	printf("Valid tiles result: %d\n", valid_rectangular(game));
	// if (!valid_tiles(game->map) || !valid_num_of_tiles(game->map) || !valid_rectangular(game->map)
	// 	|| !valid_walls(game->map) || !valid_path(game->map))
	// 	print_error("Invalid map!");
	//printf("valid tiles: %d\n", valid_tiles(game->map));
	free_2d_array(game->map);
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
