#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_vars game;

	game.game_over = 0;
	if (argc == 2)
	{
		parse_input(argv[1], &game);
		// mlx_ptr = mlx_init();
		// if (!mlx_ptr)
		// 	return (1);
		// win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
		// 		WINDOW_NAME);
		// if (!win_ptr)
		// 	return (free(mlx_ptr), 1);
		// collectible  = mlx_xpm_file_to_image(mlx_ptr, relative_path_c,
		//		&img_width, &img_height);
		// if (!collectible)
		//     return (0);
		// wall = mlx_xpm_file_to_image(mlx_ptr, relative_path_w, &img_width,
		//		&img_height);
		// void *player = mlx_xpm_file_to_image(mlx_ptr, PATH_WALL, &img_width,
		//		&img_height);
		// while (1)
		// mlx_put_image_to_window(mlx_ptr, win_ptr, collectible, 1, 1);
		// mlx_put_image_to_window(mlx_ptr, win_ptr, wall, 5, 5);
		// mlx_put_image_to_window(mlx_ptr, win_ptr, player, 5, 5);
		//     ;
		// mlx_destroy_window(mlx_ptr, win_ptr);
		// mlx_destroy_display(mlx_ptr);
		//free(mlx_ptr);
	}
	else
		print_error("WRONG INPUT! Try: ./so_long [PATH TO MAP]");
	return (0);
}
