/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:57:54 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/26 20:18:24 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_game *game, char *title)
{
	 game->mlx = mlx_init();
	 ft_printf("width: %d, height: %d\n", game->width, game->height);
	 game->win = mlx_new_window(game->mlx, game->width, game->height, title);
}

void	get_img(t_game *game, int width, int height)
{
	game->img = mlx_new_image(game->mlx, width, height);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_len,\
								&game->endian);
}
