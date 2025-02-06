/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:22:31 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/02/06 21:09:06 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*join_strings(char *buffer, char *temp)
{
	char	*new;

	new = ft_strjoin(buffer, temp);
	free(buffer);
	return (new);
}

char	**copy_map(char **map)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * (count_rows(map) + 1));
	if (!copy)
		error_exit("Error\nMalloc failed\n");
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	ft_flood_fill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->columns || y >= game->rows)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'X' || map[y][x] == 'E')
		return ;
	{
		map[y][x] = 'X';
		ft_flood_fill(map, x + 1, y, game);
		ft_flood_fill(map, x - 1, y, game);
		ft_flood_fill(map, x, y + 1, game);
		ft_flood_fill(map, x, y - 1, game);
	}
}

void	load_player(t_game *game)
{
	mlx_image_to_window(game->mlx, game->leprechaun, game->player_coords.x
		* PXL, game->player_coords.y * PXL);
}

void	refill_floor(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->floor, x * 32, y * 32);
}
