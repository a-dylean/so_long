#include "../includes/so_long.h"

void init_vars(t_vars *game)
{
	game->map_height = 0;
	game->map_weight = 0;
	game->pos_x = 0;
	game->pos_y = 0;
	game->player_pos_x = 0;
	game->player_pos_y = 0;
	game->player_count = 0;
	game->end_count = 0;
	game->keys_count = 0;
	game->keys_collected = 0;
	game->steps = 0;
	game->msg_error = NULL;
}

int	main(int argc, char **argv)
{
	t_vars	game;

	if (argc == 2)
	{
		init_vars(&game);
		parse_input(argv[1], &game);
		game.mlx = mlx_init();
		if (!game.mlx)
			return (1);
		game.window = mlx_new_window(game.mlx, game.map_weight * SIZE,
				game.map_height * SIZE, WINDOW_NAME);
		if (!game.window)
			return (free(game.mlx), 1);
		create_images(&game);
		mlx_hook(game.window, KeyPress, KeyPressMask, key_hook, &game);
		mlx_hook(game.window, DestroyNotify, \
	ButtonPressMask, close_game, &game);
		mlx_loop_hook(game.mlx, &render_images, &game);
		mlx_loop(game.mlx);
	}
	else
		exit_with_error("WRONG INPUT! Try: ./so_long [PATH TO MAP]");
	return (0);
}
