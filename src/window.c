/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:12:58 by jhesso            #+#    #+#             */
/*   Updated: 2023/05/04 16:01:34 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	calculate_window_size()
*	calculates the size needed for our window, if the map is really large
*	limit the window size to the full hd resolution in order to fit most screens
*/
void	calculate_window_size(t_game *game)
{
	game->width = game->map.cols * SIZE;
	game->height = game->map.rows * SIZE;
	if (game->width > 1920)
		game->width = 1920;
	if (game->height > 1056)
		game->height = 1056;
}
