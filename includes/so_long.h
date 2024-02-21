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

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_map_data
{
	int		height;
	int		weight;
	int		pos_x;
	int		pos_y;
	int		score;
	int		current_score;
	char	**map_data;
	void	*player;
	void	*wall;
	void	*free;
	void	*end;
	void	*item;
	int		game_over;

}			t_map_data;

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
void		parse_map(char *path_to_map);
char **get_map(char *path_to_map);
void free_2d_array(char **arr);
int count_input_lines(char *path_to_map);
void populate_map(char *path_to_map, char **map);
#endif