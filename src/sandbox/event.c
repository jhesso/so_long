/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:51:06 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/12 15:50:03 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_close(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit(0);
}

// void	get_color(int keycode, t_mlx *mlx)
// {
// 	if (keycode == 15)
// 		mlx->color = 0x00FF0000;
// 	else if (keycode == 5)
// 		mlx->color = 0x0000FF00;
// 	else
// 		mlx->color = 0x000000FF;
// }

int	key_press(int keycode, t_mlx *mlx)
{
	(*mlx).window = (*mlx).window;
	ft_printf("key pressed: %d\n", keycode);
	if (keycode == 53)
		win_close(mlx);
	else if(keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		move(keycode, mlx);
	// else if (keycode == 15 || keycode == 5 || keycode == 11)
	// 	get_color(keycode, mlx);
	return (0);
}
