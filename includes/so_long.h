#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
#include <../mlx/mlx.h>

# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT 500
# define WINDOW_NAME "so_long"

# define PATH_GRASS "xpm/grass.xpm"
# define PATH_STONE "xpm/stone.xpm"
# define PATH_COW "xpm/cow.xpm"
# define PATH_SOIL "xpm/soil.xpm"
# define PATH_END "xpm/end.xpm"


# define STONE '1'
# define SOIL '0'
# define COW 'P'
# define END 'E'
# define GRASS 'C'

typedef struct s_data
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	void		*textures[5]; // MLX image pointers (on the stack)
	//t_map		*map; // Map pointer (contains map details - preferably kept on the stack)
}	t_data;

typedef struct t_map
{
	void *start;
}	t_map;

typedef struct t_img
{
	void *img;
	char *path;
	int width;
	int height;
} t_img;

t_img *init_img(char *path, int height, int width);
void render_image(void	*mlx_ptr, void	*win_ptr, t_img *img, int position_x, int position_y);

#endif