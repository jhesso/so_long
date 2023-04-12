/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:57:54 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/12 13:36:35 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_mlx	init_mlx(int width, int height, char *title)
{
	t_mlx	mlx;

	 mlx.mlx = mlx_init();
	 mlx.window = mlx_new_window(mlx.mlx, width, height, title);
	return (mlx);
}

t_img	get_img(t_mlx mlx, int width, int height)
{
	t_img	img;

	img.img = mlx_new_image(mlx.mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len,\
								&img.endian);
	return (img);
}
