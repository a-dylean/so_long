/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:31 by atonkopi          #+#    #+#             */
/*   Updated: 2024/02/28 16:53:41 by atonkopi         ###   ########.fr       */
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

static void	populate_map(t_vars *game, int fd)
{
    char	*new_line;
    char *clean_new_line;
    int		i;

    i = 0;
    game->map = malloc(sizeof(char *) * (game->map_height + 1));
    //Change to new func
	for (int i = 0; i <= game->map_height; i++)
        game->map[i] = NULL;
    if (!game->map)
    {
        free(game->map);
        exit_with_error("Memory allocation failed");
    }
    while (1)
    {
        new_line = get_next_line(fd);
        if (!new_line)
            break ;
        clean_new_line = ft_strtrim(new_line, "\n");
        free(new_line);
        if (!clean_new_line)
        {
            ft_printf("Error\nEmpty line found\n");
            free_2d_array(game->map);
            exit(0);
        }
        if (i < game->map_height)
        {
            game->map[i] = ft_strdup(clean_new_line);
            if (!game->map[i])
            {
                free(clean_new_line);
                free_2d_array(game->map);
                exit_with_error("Memory allocation failed");
            }
            game->map_weight = (int)ft_strlen(clean_new_line);
            free(clean_new_line);
			i++;
        }
    }
}

void	parse_input(char *path_to_map, t_vars *game)
{
	int fd;

	fd = open(path_to_map, O_RDONLY);
	if (fd == -1)
		exit_with_error("No such file or directory");
	populate_map(game, fd);
	close(fd);
	if (!valid_tiles(game) || !valid_num_of_tiles(game)
		|| !valid_rectangular(game) || !valid_walls(game) || !valid_path(game))
	{
		free_2d_array(game->map);
		if (game->msg_error)
			ft_printf("Error\n%s", game->msg_error);
		exit(0);
	}
	game->keys_collected = 0;
}
