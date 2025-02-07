/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:21:59 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/02/07 14:03:40 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*init_game(char *argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		error_exit("Error\nMalloc failed\n");
	game->map = read_map(argv);
	game->map_copy = copy_map(game->map);
	game->map_copy2 = copy_map(game->map);
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

// void leaks ()
// {
//     system("leaks so_long");
// }
// 	atexit(leaks);

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		game = init_game(argv[1]);
		game->mlx = mlx_init(PXL * game->columns, PXL * game->rows,
				"Maze O'Gold", true);
		if (!game->mlx)
		{
			free(game);
			error_exit("Error\nFailed to initialize mlx\n");
		}
		check_map_validity(game);
		add_images(game);
		launch_game(game);
	}
	else
	{
		error_exit("Error\nInvalid number of arguments\n");
	}
	return (0);
}
