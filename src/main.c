#include "../includes/so_long.h"

int main(void)
{
    void	*mlx_ptr;
    void	*win_ptr;
    void *collectible;
    void *background;
    char	*relative_path_c = "xpm/collectible.xpm";
	int		img_width = 16;
	int		img_height = 17;

   
    mlx_ptr = mlx_init();
    if (!mlx_ptr)
		  return (1);
    win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
    if (!win_ptr)
		  return (free(mlx_ptr), 1);
        
    collectible  = mlx_xpm_file_to_image(mlx_ptr, relative_path_c, &img_width, &img_height);       
    while (1)
    mlx_put_image_to_window(mlx_ptr, win_ptr, collectible, 1, 1);  
        ;
       
      

    mlx_destroy_window(mlx_ptr, win_ptr);
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
   
    return(0);
}
