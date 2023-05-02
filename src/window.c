/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:12:58 by jhesso            #+#    #+#             */
/*   Updated: 2023/05/02 19:49:20 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calculate_window_size(t_game *game)
{
	game->width = game->map.cols * SIZE;
	game->height = game->map.rows * SIZE;
	if (game->width > 1920)
		game->width = 1920;
	if (game->height > 1056)
		game->height = 1056;
}
