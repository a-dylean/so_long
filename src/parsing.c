/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:31 by atonkopi          #+#    #+#             */
/*   Updated: 2024/02/23 15:45:06 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parse_input(char *path_to_map, t_vars *game)
{
	if (!valid_format(path_to_map))
		exit_with_error("Invalid map format");
	game->map_height = count_input_lines(path_to_map);
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return ;
	game->map_copy = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map_copy)
		return ;
	populate_map(path_to_map, game->map);
	game->map[game->map_height] = NULL;
	populate_map(path_to_map, game->map_copy);
	game->map_copy[game->map_height] = NULL;
	if (game->map[0])
		game->map_weight = ft_strlen(game->map[0]);
	if (!valid_tiles(game) || !valid_num_of_tiles(game)|| !valid_rectangular(game) || !valid_walls(game) || !valid_path(game))
	{
		free_2d_array(game->map);
		free_2d_array(game->map_copy);
		exit_with_error("Invalid map");
	}
}

