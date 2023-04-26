/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:57:54 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/26 16:22:18 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx	init_mlx(int width, int height, char *title)
{
	t_mlx	mlx;

	 mlx.mlx = mlx_init();
	 mlx.window = mlx_new_window(mlx.mlx, width, height, title);
	return (mlx);
}

t_mlx	get_img(t_mlx mlx, int width, int height)
{

	mlx.img = mlx_new_image(mlx.mlx, width, height);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_len,\
								&mlx.endian);
	return (mlx);
}
