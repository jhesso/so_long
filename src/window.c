/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:12:58 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/26 17:20:06 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calculate_window_size(t_game *game)
{
	game->width = game->map.cols * SPRITE_SIZE;
	game->height = game->map.rows * SPRITE_SIZE;
	ft_printf("width: %d, height: %d\n", game->width, game->height);
	// if (game->width > 1920)
	// 	game->width = 1920;
	// if (game->height > 1080)
	// 	game->height = 1080;
}
