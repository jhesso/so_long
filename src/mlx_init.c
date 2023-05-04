/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:57:54 by jhesso            #+#    #+#             */
/*   Updated: 2023/05/04 15:53:39 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	init_mlx()
*	initializes mlx :D
*/
void	init_mlx(t_game *game, char *title)
{
	 game->mlx = mlx_init();
	 game->win = mlx_new_window(game->mlx, game->width, game->height, title);
}

/*	get_img()
*	creates a new img and saves it to our game struct
*/
void	get_img(t_game *game, int width, int height)
{
	game->img = mlx_new_image(game->mlx, width, height);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_len,\
								&game->endian);
}
