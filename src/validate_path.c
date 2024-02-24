# include "../includes/so_long.h"

void flood_fill(t_vars *game, int x, int y)
{
    if (x < 0 || y < 0 || x >= game->map_weight || y >= game->map_height || game->map_copy[y][x] == WALL || game->map_copy[y][x] == 'V')
        return ;
    game->map_copy[y][x] = 'V';
    flood_fill(game, x + 1, y);
    flood_fill(game, x - 1, y);
    flood_fill(game, x, y + 1);
    flood_fill(game, x, y - 1);
}

void fill(t_vars *game, int x, int y)
{
    flood_fill(game, x, y);
}

void player_position(t_vars *game)
{
    int i;
    int j;

    i = 0;
    while (i < game->map_height)
    {
        j = 0;
        while (j < game->map_weight)
        {
            if (game->map[i][j] == PLAYER)
            {
                game->player_pos_y = j;
                game->player_pos_x = i;
                return ;
            }
            j++;
        }
        i++;
    }
}

int valid_path(t_vars *game)
{
    int i;
    int j;

    i = 0;
    player_position(game);
    fill(game, game->player_pos_y, game->player_pos_x);
    while (i < game->map_height)
    {
        j = 0;
        while (j < game->map_weight)
        {
            if (game->map_copy[i][j] == 'C' || game->map_copy[i][j] == 'E')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

