#include "so_long.h"

void	error_exit(char *error)
{
	ft_printf("%s", error);
	exit(1);
}

int	count_rows(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	count_columns(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

void	free_arr_of_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_the(t_game *game)
{
	mlx_delete_image(game->mlx, game->floor);
	mlx_delete_image(game->mlx, game->leprechaun);
	mlx_delete_image(game->mlx, game->exit);
	mlx_delete_image(game->mlx, game->wall);
	mlx_delete_image(game->mlx, game->coin);
	free_arr_of_arr(game->map);
	free_arr_of_arr(game->map_copy);
	free(game);
	mlx_close_window(game->mlx);
	exit(0);
}