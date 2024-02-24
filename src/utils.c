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
	if (fd == -1)
		exit_with_error("No such file or directory");
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
void exit_with_error(char *error)
{
    ft_printf("Error\n");
    ft_printf("%s\n", error);
	exit(0);
}
int	close_game(t_vars *game)
{
	mlx_destroy_image(game->mlx, game->end);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->free);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->key);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_2d_array(game->map);
	free_2d_array(game->map_copy);
	exit(0);
	return (0);
}