/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:07:25 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/26 19:45:39 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	game_init()
*	start of the game loop
*/
void	game_init(t_map map, t_player player)
{
	t_game	game;

	game.map = map;
	game.player = player;
	calculate_window_size(&game);
	game.mlx = init_mlx(game.width, game.height, "so_long");
	game.mlx = get_img(game.mlx, game.width, game.height);
	init_sprite(&game);
	draw_map(&game);
	mlx_hook(game.mlx.window, 17, 0, close_game, &game);
	mlx_key_hook(game.mlx.window, key_press, &game);
	mlx_loop(&game.mlx);
}
