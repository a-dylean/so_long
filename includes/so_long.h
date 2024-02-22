#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <../mlx/mlx.h>

# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT 500
# define WINDOW_NAME "so_long"

# define PATH_ITEM "xpm/grass.xpm"
# define PATH_WALL "xpm/stone.xpm"
# define PATH_PLAYER "xpm/cow.xpm"
# define PATH_FREE "xpm/soil.xpm"
# define PATH_END "xpm/end.xpm"

# define WALL '1'
# define FREE '0'
# define PLAYER 'P'
# define END 'E'
# define ITEM 'C'

typedef struct s_mlx
{
	void *mlx_ptr; // MLX pointer
	void *win_ptr; // MLX window pointer
					// t_map		*map;
}			t_mls;

typedef struct s_tiles
{
	int player;
	int end;
	int items;
}			t_tiles;

typedef struct s_vars
{
	void *mlx;
	void *window;
	int		map_height;
	int		map_weight;
	int		pos_x;
	int		pos_y;
	int		items;
	int		items_collected;
	int		steps;
	char	**map;
	char	**map_copy;
	void	*player;
	void	*wall;
	void	*free;
	void	*end;
	void	*item;
	int		game_over;
}			t_vars;

typedef struct t_img
{
	void	*img;
	char	*path;
	int		width;
	int		height;
}			t_img;

t_img		*init_img(char *path, int height, int width);
void		render_image(void *mlx_ptr, void *win_ptr, t_img *img,
				int position_x, int position_y);
void	parse_input(char *path_to_map, t_vars *game);
char		**get_map(char *path_to_map);
void		free_2d_array(char **arr);
int			count_input_lines(char *path_to_map);
void		populate_map(char *path_to_map, char **map);
int			valid_format(char *filename);
int			valid_tiles(t_vars *game);
int			valid_num_of_tiles(t_vars *game, t_tiles tiles);
int			valid_rectangular(t_vars *game);
int			valid_walls(t_vars *game);
int			valid_path(t_vars *game);
// int contains_only_end_or_wall(char **array);
void		print_error(char *error);

#endif