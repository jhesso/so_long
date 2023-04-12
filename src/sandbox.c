/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:04:24 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/12 13:35:56 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_line_horizontal(t_img *img, t_coordinates start, t_coordinates end,\
							int color)
{
	int	x;

	x = start.x;
	while (x < end.x)
	{
		draw_pixel(img, x, start.y, color);
		x++;
	}
}

void	draw_line_vertical(t_img *img, t_coordinates start, t_coordinates end,\
							int color)
{
	int	y;

	y = start.y;
	while (y < end.y)
	{
		draw_pixel(img, start.x, y, color);
		y++;
	}
}

void	draw_square(t_img img, t_coordinates coordinates, int size)
{
	int				color;
	t_coordinates	start;
	t_coordinates	end;

	color = 0x00FF0000; // red
	start.x = coordinates.x;
	start.y = coordinates.y;
	end.x = coordinates.x + size;
	end.y = coordinates.y;
	draw_line_horizontal(&img, start, end, color);
	start.y += size;
	end.y += size;
	draw_line_horizontal(&img, start, end, color);
	start.y = coordinates.y;
	draw_line_vertical(&img, start, end, color);
	start.x += size;
	draw_line_vertical(&img, start, end, color);
}
