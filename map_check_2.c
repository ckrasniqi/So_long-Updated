/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:51:30 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/02/07 14:01:38 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill2(char **map, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->columns || y >= game->rows)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	{
		map[y][x] = 'X';
		ft_flood_fill2(map, x + 1, y, game);
		ft_flood_fill2(map, x - 1, y, game);
		ft_flood_fill2(map, x, y + 1, game);
		ft_flood_fill2(map, x, y - 1, game);
	}
}

void	fill_map2(t_game *game, int x, int y)
{
	ft_flood_fill2(game->map_copy2, x, y, game);
}

int	check_valid_path2(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	fill_map2(game, game->player_coords.x, game->player_coords.y);
	while (game->map_copy2[++i])
	{
		j = -1;
		while (game->map_copy2[i][++j])
		{
			if (game->map_copy2[i][j] == 'C' || game->map_copy2[i][j] == 'P'
				|| game->map_copy2[i][j] == 'E')
				error_exit("Error\nInvalid map, exit or coin is blocked\n");
		}
	}
	free_arr_of_arr(game->map_copy2);
	return (1);
}
