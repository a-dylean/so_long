#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <../mlx/mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"
# include "fcntl.h"

# define SIZE 24
# define WINDOW_NAME "so_long"

# define PATH_KEY "xpm/key.xpm"
# define PATH_WALL "xpm/wall.xpm"
# define PATH_PLAYER "xpm/player.xpm"
# define PATH_FREE "xpm/free.xpm"
# define PATH_END "xpm/end.xpm"

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

typedef struct s_tiles
{
	int		player;
	int		end;
	int		keys;
}			t_tiles;

typedef struct s_vars
{
	void	*mlx;
	void	*window;
	int		map_height;
	int		map_weight;
	int		pos_x;
	int		pos_y;
	int		keys;
	int		keys_collected;
	int		steps;
	char	**map;
	int		player_pos_x;
	int		player_pos_y;
	char	**map_copy;
	void	*player;
	void	*wall;
	void	*free;
	void	*end;
	void	*key;
}			t_vars;

void		parse_input(char *path_to_map, t_vars *game);
void		**get_map(char *path_to_map, t_vars *game);
void		free_2d_array(char **arr);
int			count_input_lines(char *path_to_map);
void		populate_map(char *path_to_map, char **map);
int			valid_format(char *filename);
int			valid_tiles(t_vars *game);
int			valid_num_of_tiles(t_vars *game, t_tiles tiles);
int			valid_rectangular(t_vars *game);
int			valid_walls(t_vars *game);
int			valid_path(t_vars *game);
void		create_images(t_vars *game);
int			render_images(t_vars *game);
int			key_hook(int keycode, t_vars *game);
int			close_game(t_vars *game);
void		print_error(char *error);
int			next_tile_check(t_vars *game, int *current_position);

#endif