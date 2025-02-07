/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:22:16 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/02/07 14:02:43 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_game *game)
{
	int		i;
	int		j;
	size_t	first_row_len;

	i = -1;
	first_row_len = ft_strlen(game->map[0]);
	while (game->map[++i])
	{
		j = -1;
		if (ft_strlen(game->map[i]) != first_row_len)
			return (0);
		while (game->map[i][++j])
		{
			if ((i == 0 || i == game->rows - 1 || j == 0 || j == game->columns
					- 1) && game->map[i][j] != '1')
				return (0);
		}
	}
	return (1);
}

int	check_elements(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
				game->p_count++;
			if (game->map[i][j] == 'C')
				game->c_count++;
			if (game->map[i][j] == 'E')
				game->e_count++;
		}
	}
	if (game->p_count != 1 || game->e_count != 1 || game->c_count < 1)
		return (0);
	return (1);
}

int	check_invalid_chars(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] != 'P' && game->map[i][j] != 'C'
				&& game->map[i][j] != 'E' && game->map[i][j] != '1'
				&& game->map[i][j] != '0')
				return (0);
		}
	}
	return (1);
}

int	check_valid_path(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	fill_map(game, game->player_coords.x, game->player_coords.y);
	while (game->map_copy[++i])
	{
		j = -1;
		while (game->map_copy[i][++j])
		{
			if (game->map_copy[i][j] == 'C' || game->map_copy[i][j] == 'P')
				error_exit("Error\nInvalid map, player or coin is blocked\n");
		}
	}
	free_arr_of_arr(game->map_copy);
	return (1);
}

void	fill_map(t_game *game, int x, int y)
{
	ft_flood_fill(game->map_copy, x, y, game);
}
