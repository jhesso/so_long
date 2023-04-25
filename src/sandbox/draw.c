/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:59:13 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/12 17:01:40 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	// ft_printf("x: %d y: %d\n", x, y);
	dst = mlx->addr + (y * mlx->line_len + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
