/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:53:30 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/12 13:58:40 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_mlx			mlx;
	t_img			img;
	t_coordinates	coordinates;
	int				width;
	int				height;

	if (ac < 2)
		ft_printf("%s\n", av[0]);
	width = 1280;
	height = 720;
	mlx = init_mlx(width, height, "so_long");
	img = get_img(mlx, width, height);
	coordinates.x = 640;
	coordinates.y = 360;
	// draw_square(img, coordinates, 200);
	mlx_hook(mlx.window, 2, 0, key_press, &mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.window, img.img, 0, 0);
	mlx_loop(mlx.mlx);
	return (0);
}
