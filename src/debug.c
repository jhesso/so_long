/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:43:54 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/25 14:46:26 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	debug_print_coordinate_map(t_map map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map.rows)
	{
		x = 0;
		while (x < map.cols)
		{
			ft_printf("%d", map.coordinate_map[y][x]);
			x++;
		}
		ft_putchar_fd('\n', 1);
		y++;
	}
}
