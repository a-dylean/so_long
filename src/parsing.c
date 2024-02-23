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
	t_tiles	tiles;

	game->keys = 0;
	tiles.player = 0;
	tiles.end = 0;
	tiles.keys = game->keys;
	if (!valid_format(path_to_map))
		//leak here
		print_error("Invalid map format!");
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
	game->map_weight = ft_strlen(game->map[0]); //segfault here
	if (!valid_tiles(game) 
	|| !valid_num_of_tiles(game, tiles)	|| !valid_rectangular(game) || !valid_walls(game) )
	//|| !valid_path(game)
	 	//proper free missing
		print_error("Invalid map!");
		exit(0);
	// free_2d_array(game->map);
	// free_2d_array(game->map_copy);

}

// void	**get_map(char *path_to_map, t_vars *game)
// {
	
// }
