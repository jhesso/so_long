/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:12:58 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/26 20:21:31 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calculate_window_size(t_game *game)
{
	game->width = game->map.cols * SIZE;
	game->height = game->map.rows * SIZE;
	ft_printf("cols: %d, rows: %d\n", game->map.cols, game->map.rows);
	ft_printf("width: %d, height: %d\n", game->width, game->height);
	// if (game->width > 1920)
	// 	game->width = 1920;
	// if (game->height > 1080)
	// 	game->height = 1080;
}
