/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:31 by atonkopi          #+#    #+#             */
/*   Updated: 2024/02/21 17:14:30 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void free_2d_array(char **array)
{
    if (array == NULL)
        return;

    for (int i = 0; array[i] != NULL; i++)
    {
        free(array[i]);
    }

    free(array);
}

void	parse_map(char *path_to_map)
{
	char	**map;

	map = get_map(path_to_map);
	ft_printf("%s\n", map[0]);
	// ft_printf("%s\n", map[1]);
	// ft_printf("%s\n", map[2]);
	// ft_printf("%s\n", map[3]);
	// ft_printf("%s\n", map[4]);
    free_2d_array(map);
}

char	**get_map(char *path_to_file)
{
	int		count;
	char	*new_line;
	int		i;
	int		fd;
	char	**map;

	count = 0;
	i = 0;
	fd = open(path_to_file, O_RDONLY);
	while (1)
    {
        new_line = get_next_line(fd);
		if (!new_line)
            break ;
        count++;
        free(new_line);
		new_line = NULL;
    }
	close(fd);
	map = malloc(sizeof(char *) * (count + 1));
	if (!map)
		return (NULL);
	fd = open(path_to_file, O_RDONLY);
	while (1)
	{
		new_line = get_next_line(fd);
		if (!new_line)
            break ;
		map[i] = malloc((int)ft_strlen(new_line) + 1);
		if (!map[i])
			return (NULL);
		ft_strlcpy(map[i], new_line, ft_strlen(new_line) + 1);
		free(new_line);
		new_line = NULL;
		i++;
	}
	map[count] = NULL;
	close(fd);
	return (map);
}
