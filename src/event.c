/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:06:22 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/28 14:34:18 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_printf("closed window\n");
	exit(0);
}

int	key_press(int keycode, t_game *game)
{
	ft_printf("key pressed: %d\n", keycode);
	if (keycode == ESC)
		close_game(game);
	else if (keycode == W)
		move_up(game);
	else if (keycode == A)
		move_left(game);
	else if (keycode == S)
		move_down(game);
	else if (keycode == D)
		move_rigth(game);
	// else if (keycode == 15 || keycode == 5 || keycode == 11)
	// 	get_color(keycode, mlx);
	return (0);
}
