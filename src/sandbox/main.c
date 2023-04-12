/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:53:30 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/12 17:04:02 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// int	render_frame(t_mlx *mlx)
// {
// 	t_img			img;
// 	int				width;
// 	int				height;
// 	t_coordinates	coords;

// 	width = 1920;
// 	height = 1080;
// 	coords.x = 960;
// 	coords.y = 540;
// 	img = get_img(*mlx, width, height);
// 	draw_square(img, coords, 200);
// 	mlx_put_image_to_window(mlx->mlx, mlx->window, img.img, 0, 0);
// 	return (0);
// }

int	render_frame(t_mlx *mlx)
{
	int	size;

	size = 200;
	mlx->coord_x = mlx->width / 2 - (size / 2);
	mlx->coord_y = mlx->height / 2 - (size / 2);
	draw_square(mlx, size);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac < 2)
		ft_printf("%s\n", av[0]);
	mlx.width = 1920;
	mlx.height = 1080;
	mlx.color = 0x00FF0000;
	mlx = init_mlx(mlx.width, mlx.height, "so_long");
	mlx = get_img(mlx, mlx.width, mlx.height);
	mlx_hook(mlx.window, 2, 0, key_press, &mlx);
	mlx_loop_hook(mlx.mlx, render_frame, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
