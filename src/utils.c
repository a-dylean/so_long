/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:17:26 by atonkopi          #+#    #+#             */
/*   Updated: 2024/02/23 15:41:50 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_2d_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	count_input_lines(char *path_to_map)
{
	int fd;
	char *new_line;
	int count;

	count = 0;
	fd = open(path_to_map, O_RDONLY);
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
	return (count);
}

void populate_map(char *path_to_map, char **map)
{
    int fd;
    char *new_line;
	char *clean_new_line;
    int i;

    i = 0;
    fd = open(path_to_map, O_RDONLY);
	if (fd == -1)
		//add free statement, there's a leak if quits here
		print_error("No such file or directory");
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
void print_error(char *error)
{
    ft_printf("Error\n");
    ft_printf("%s\n", error);
}
