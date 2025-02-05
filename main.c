#include "so_long.h"

t_game	*init_game(char *argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		error_exit("Error\nMalloc failed\n");
	game->map = read_map(argv);
	game->map_copy = copy_map(game->map);
	game->steps = 0;
	game->rows = count_rows(game->map);
	game->columns = count_columns(game->map);
	game->coins_left = 0;
	game->c_count = 0;
	game->e_count = 0;
	game->p_count = 0;
	game->player_coords = find_player(game->map, 'P');
	return (game);
}
void	launch_game(t_game *game)
{
	flood_fill_floor_wall(game);
	flood_fill_collectibles(game);
	mlx_key_hook(game->mlx, (mlx_keyfunc)key_set, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_the(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		printf("Welcome to So Long!\n");
		game = init_game(argv[1]);
		printf("Map loaded successfully\n");
		add_images(game);
		printf("Images loaded successfully\n");
		check_map_validity(game);
		printf("Map is valid\n");
		game->mlx = mlx_init(PXL * game->columns, PXL * game->rows,
				"Maze O'Gold", true);
		printf("Mlx initialized successfully\n");
		if (!game->mlx)
		{
			free_arr_of_arr(game->map);
			free(game);
			error_exit("Error\nFailed to initialize mlx\n");
		}
		launch_game(game);
		printf("Game launched successfully\n");
	}
	else
	{
		error_exit("Error\nInvalid number of arguments\n");
	}
	return (0);
}
