/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:22:06 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/02/06 21:12:13 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_set(mlx_key_data_t paramkey, t_game *game)
{
	if (paramkey.key == MLX_KEY_W && paramkey.action == MLX_PRESS)
		go_up(game);
	if (paramkey.key == MLX_KEY_S && paramkey.action == MLX_PRESS)
		go_down(game);
	if (paramkey.key == MLX_KEY_A && paramkey.action == MLX_PRESS)
		go_left(game);
	if (paramkey.key == MLX_KEY_D && paramkey.action == MLX_PRESS)
		go_right(game);
	if (paramkey.key == MLX_KEY_ESCAPE && paramkey.action == MLX_PRESS)
	{
		ft_printf("You exited the game by pressing ESC\n");
		free_the(game);
	}
}

void	go_up(t_game *game)
{
	if (game->map[game->player_coords.y - 1][game->player_coords.x] != '1'
		&& (game->map[game->player_coords.y - 1][game->player_coords.x] != 'E'
			|| game->coins_left == 0))
	{
		if (game->map[game->player_coords.y - 1][game->player_coords.x] == 'C')
			game->coins_left--;
		if (game->map[game->player_coords.y - 1][game->player_coords.x] == 'E'
			&& game->coins_left == 0)
		{
			ft_printf("You won the game with %d steps\n", game->steps);
			free_the(game);
		}
		game->map[game->player_coords.y][game->player_coords.x] = '0';
		refill_floor(game, game->player_coords.x, game->player_coords.y);
		game->player_coords.y--;
		game->map[game->player_coords.y][game->player_coords.x] = 'P';
		load_player(game);
		game->steps++;
		ft_printf("Moves made until now: %d\n", game->steps);
	}
}

void	go_down(t_game *game)
{
	if (game->map[game->player_coords.y + 1][game->player_coords.x] != '1'
		&& (game->map[game->player_coords.y + 1][game->player_coords.x] != 'E'
			|| game->coins_left == 0))
	{
		if (game->map[game->player_coords.y + 1][game->player_coords.x] == 'C')
			game->coins_left--;
		if (game->map[game->player_coords.y + 1][game->player_coords.x] == 'E'
			&& game->coins_left == 0)
		{
			ft_printf("You won the game with %d steps\n", game->steps);
			free_the(game);
		}
		game->map[game->player_coords.y][game->player_coords.x] = '0';
		refill_floor(game, game->player_coords.x, game->player_coords.y);
		game->player_coords.y++;
		game->map[game->player_coords.y][game->player_coords.x] = 'P';
		load_player(game);
		game->steps++;
		ft_printf("Moves made until now: %d\n", game->steps);
	}
}

void	go_left(t_game *game)
{
	if (game->map[game->player_coords.y][game->player_coords.x - 1] != '1'
		&& (game->map[game->player_coords.y][game->player_coords.x - 1] != 'E'
			|| game->coins_left == 0))
	{
		if (game->map[game->player_coords.y][game->player_coords.x - 1] == 'C')
			game->coins_left--;
		if (game->map[game->player_coords.y][game->player_coords.x - 1] == 'E'
			&& game->coins_left == 0)
		{
			ft_printf("You won the game with %d steps\n", game->steps);
			free_the(game);
		}
		game->map[game->player_coords.y][game->player_coords.x] = '0';
		refill_floor(game, game->player_coords.x, game->player_coords.y);
		game->player_coords.x--;
		game->map[game->player_coords.y][game->player_coords.x] = 'P';
		load_player(game);
		game->steps++;
		ft_printf("Moves made until now: %d\n", game->steps);
	}
}

void	go_right(t_game *game)
{
	if (game->map[game->player_coords.y][game->player_coords.x + 1] != '1'
		&& (game->map[game->player_coords.y][game->player_coords.x + 1] != 'E'
			|| game->coins_left == 0))
	{
		if (game->map[game->player_coords.y][game->player_coords.x + 1] == 'C')
			game->coins_left--;
		if (game->map[game->player_coords.y][game->player_coords.x + 1] == 'E'
			&& game->coins_left == 0)
		{
			ft_printf("You won the game with %d steps\n", game->steps);
			free_the(game);
		}
		game->map[game->player_coords.y][game->player_coords.x] = '0';
		refill_floor(game, game->player_coords.x, game->player_coords.y);
		game->player_coords.x++;
		game->map[game->player_coords.y][game->player_coords.x] = 'P';
		load_player(game);
		game->steps++;
		ft_printf("Moves made until now: %d\n", game->steps);
	}
}
