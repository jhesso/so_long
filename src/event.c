/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:06:22 by jhesso            #+#    #+#             */
/*   Updated: 2023/05/02 20:21:38 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	game->player.moves++;
}

void	print_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->player.moves);
	moves = ft_strjoin("moves: ", moves);
	mlx_string_put(game->mlx, game->win, 5, 5, GREEN, moves);
	ft_printf("%s\n", moves);
	free(moves);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_game(game);
	else if (keycode == W)
	{
		if (move_up(game, game->player_x, game->player_y))
			move(game);
	}
	else if (keycode == A)
	{
		if (move_left(game, game->player_x, game->player_y))
			move(game);
	}
	else if (keycode == S)
	{
		if (move_down(game, game->player_x, game->player_y))
			move(game);
	}
	else if (keycode == D)
	{
		if (move_right(game, game->player_x, game->player_y))
			move(game);
	}
	print_moves(game);
	return (0);
}
