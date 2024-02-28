/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:31 by atonkopi          #+#    #+#             */
/*   Updated: 2024/02/28 14:33:49 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	valid_format(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strncmp(filename + len - 4, ".ber", ft_strlen(filename)) == 0);
}

static void	populate_map(char *path_to_map, char **map)
{
	int		fd;
	char	*new_line;
	char	*clean_new_line;
	int		i;

	i = 0;
	fd = open(path_to_map, O_RDONLY);
	if (fd == -1)
		exit_with_error("No such file or directory");
	while (1)
	{
		new_line = get_next_line(fd);
		if (!new_line)
			break ;
		clean_new_line = ft_strtrim(new_line, "\n");
		free(new_line);
		map[i] = malloc(ft_strlen(clean_new_line) + 1);
		if (!map[i])
			return (free(clean_new_line));
		ft_strlcpy(map[i], clean_new_line, ft_strlen(clean_new_line) + 1);
		free(clean_new_line);
		i++;
	}
	close(fd);
}

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
	if (!valid_tiles(game) || !valid_num_of_tiles(game)
		|| !valid_rectangular(game) || !valid_walls(game) || !valid_path(game))
	{
		free_2d_array(game->map);
		free_2d_array(game->map_copy);
		if (game->msg_error)
			ft_printf("Error\n%s", game->msg_error);
		exit(0);
	}
	game->keys_collected = 0;
}
