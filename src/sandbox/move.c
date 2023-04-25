/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:11:19 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/12 14:17:33 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_up(t_mlx *mlx)
{
	(*mlx).mlx = (*mlx).mlx;
	ft_printf("up\n");
	return (0);
}

static int	move_left(t_mlx *mlx)
{
	(*mlx).mlx = (*mlx).mlx;
	ft_printf("left\n");
	return (0);
}

static int	move_down(t_mlx *mlx)
{
	(*mlx).mlx = (*mlx).mlx;
	ft_printf("down\n");
	return (0);
}

static int	move_right(t_mlx *mlx)
{
	(*mlx).mlx = (*mlx).mlx;
	ft_printf("right\n");
	return (0);
}

int	move(int keycode, t_mlx *mlx)
{
	if (keycode == 13)
		move_up(mlx);
	else if (keycode == 0)
		move_left(mlx);
	else if (keycode == 1)
		move_down(mlx);
	else
		move_right(mlx);
	return (0);
}
