/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:51:06 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/12 14:18:53 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_close(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit(0);
}

int	key_press(int keycode, t_mlx *mlx)
{
	(*mlx).window = (*mlx).window;
	ft_printf("key pressed: %d\n", keycode);
	if (keycode == 53)
		win_close(mlx);
	else if(keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		move(keycode, mlx);
	return (0);
}
