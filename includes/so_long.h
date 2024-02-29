/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:40:22 by atonkopi          #+#    #+#             */
/*   Updated: 2024/02/29 13:48:01 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include <../mlx/mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# define SIZE 24
# define WINDOW_NAME "so_long"
# define PATH_KEY "textures/key.xpm"
# define PATH_WALL "textures/wall.xpm"
# define PATH_PLAYER "textures/player.xpm"
# define PATH_FREE "textures/free.xpm"
# define PATH_END "textures/end.xpm"
# define WALL '1'
# define FREE '0'
# define PLAYER 'P'
# define END 'E'
# define KEY 'C'
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESC 65307

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**map_copy;
	int		map_height;
	int		map_weight;
	int		pos_x;
	int		pos_y;
	int		player_pos_x;
	int		player_pos_y;
	int		player_count;
	int		end_count;
	int		keys_count;
	int		keys_collected;
	int		steps;
	void	*player;
	void	*wall;
	void	*free;
	void	*end;
	void	*key;
	int		exit_found;
	char	*msg_error;
}			t_vars;

void		parse_input(char *path_to_map, t_vars *game);
int			count_input_lines(char *path_to_map);
int			valid_format(char *filename);
int			valid_tiles(t_vars *game);
int			valid_num_of_tiles(t_vars *game);
int			valid_rectangular(t_vars *game);
int			valid_walls(t_vars *game);
int			valid_path(t_vars *game);
void		create_images(t_vars *game);
int			render_images(t_vars *game);
int			key_hook(int keycode, t_vars *game);
int			close_game(t_vars *game);
void		free_map(char **map);
void		exit_with_error(char *error);

#endif