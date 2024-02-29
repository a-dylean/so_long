/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:31 by atonkopi          #+#    #+#             */
/*   Updated: 2024/02/29 14:17:18 by atonkopi         ###   ########.fr       */
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

static void	init_empty_map(t_vars *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
	{
		free(game->map);
		exit_with_error("Memory allocation failed");
	}
	while (i <= game->map_height)
	{
		game->map[i] = NULL;
		i++;
	}
}

static void	free_and_exit(char *msg, t_vars *game, char *new_line)
{
	if (ft_strlen(new_line) > 0)
		free(new_line);
	free_map(game->map);
	exit_with_error(msg);
}

static void	populate_map(t_vars *game, int fd)
{
	char	*new_line;
	char	*clean_new_line;
	int		i;

	i = 0;
	init_empty_map(game);
	while (1)
	{
		new_line = get_next_line(fd);
		if (!new_line)
			break ;
		clean_new_line = ft_strtrim(new_line, "\n");
		free(new_line);
		if (!clean_new_line)
			free_and_exit("Empty line in map", game, "");
		if (i < game->map_height)
		{
			game->map[i] = ft_strdup(clean_new_line);
			if (!game->map[i])
				free_and_exit("Memory allocation failed", game, new_line);
			game->map_weight = (int)ft_strlen(clean_new_line);
			free(clean_new_line);
			i++;
		}
	}
}

void	parse_input(char *path_to_map, t_vars *game)
{
	int	fd;

	fd = open(path_to_map, O_RDONLY);
	if (fd == -1)
		exit_with_error("No such file or directory");
	populate_map(game, fd);
	close(fd);
	if (!valid_tiles(game) || !valid_num_of_tiles(game)
		|| !valid_rectangular(game) || !valid_walls(game) || !valid_path(game))
		free_and_exit(game->msg_error, game, "");
	game->keys_collected = 0;
}
