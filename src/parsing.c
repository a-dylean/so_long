/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:31 by atonkopi          #+#    #+#             */
/*   Updated: 2024/02/21 14:47:12 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/so_long.h"

void parse_map(char *path_to_map)
{
    int count = 0;
    int fd = open(path_to_map, O_RDONLY);
    ft_printf("%s\n", path_to_map);
    while (1)
	{
		char *next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		count++;
		printf("[%d]:%s\n", count, next_line);
		free(next_line);
		next_line = NULL;
	}
}