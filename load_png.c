#include "so_long.h"

void	add_images(t_game *game)
{
	mlx_texture_t* texture;
	mlx_image_t* image;

	printf("Adding images\n");
	texture = mlx_load_png("textures/Floor1.png");
	printf("Floor loaded\n");
	image = mlx_texture_to_image(game->mlx, texture);
	printf("Floor converted\n");
	game->floor = image;
	mlx_delete_texture(texture);
	texture = mlx_load_png("textures/Wall.png");
	image = mlx_texture_to_image(game->mlx, texture);
	game->wall = image;
	mlx_delete_texture(texture);
	texture = mlx_load_png("textures/Coin.png");
	image = mlx_texture_to_image(game->mlx, texture);
	game->coin = image;
	mlx_delete_texture(texture);
	texture = mlx_load_png("textures/Exit.png");
	image = mlx_texture_to_image(game->mlx, texture);
	game->exit = image;
	mlx_delete_texture(texture);
	texture = mlx_load_png("textures/Leprechaun.png");
	image = mlx_texture_to_image(game->mlx, texture);
	game->leprechaun = image;
	mlx_delete_texture(texture);
}
void	flood_fill_floor_wall(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '0')
				mlx_image_to_window(game->mlx, game->floor, j * PXL, i * PXL);
			if (game->map[i][j] == '1')
				mlx_image_to_window(game->mlx, game->wall, j * PXL, i * PXL);
		}
	}
}

void	flood_fill_collectibles(t_game *game)
{
	int i;
	int j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'C')
			{
				mlx_image_to_window(game->mlx, game->coin, j * PXL, i * PXL);
				game->coins_left++;
			}
			if (game->map[i][j] == 'P')
				mlx_image_to_window(game->mlx, game->leprechaun, j * PXL, i
					* PXL);
			if (game->map[i][j] == 'E')
				mlx_image_to_window(game->mlx, game->exit, j * PXL, i * PXL);
		}
	}
}