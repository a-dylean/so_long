#include "../includes/so_long.h"

int on_keypress(int keysym, t_vars *game)
{
	(void)game;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	game;

	if (argc == 2)
	{
		game.game_over = 0;
		game.pos_x = 0;
		game.pos_y = 0;
		game.mlx = mlx_init();
		if (!game.mlx)
			return (1);
		parse_input(argv[1], &game);
		game.window = mlx_new_window(game.mlx, game.map_weight * SIZE,
				game.map_height * SIZE, WINDOW_NAME);
		if (!game.window)
			return (free(game.mlx), 1);
		create_images(&game);
		//render_images(&game);
		mlx_hook(game.window, 2, 0, key_hook, &game);
		mlx_hook(game.window, 17, 0, exit_hook, &game);
		mlx_loop_hook(game.mlx, &render_images, &game);
		mlx_loop(game.mlx);
	}
	else
		print_error("WRONG INPUT! Try: ./so_long [PATH TO MAP]");
	return (0);
}
