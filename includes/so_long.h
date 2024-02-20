#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
#include <../mlx/mlx.h>
# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

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
	char relative_path;
	int img_width;
	int img_height;
} t_img;

t_img *collectible;


#endif