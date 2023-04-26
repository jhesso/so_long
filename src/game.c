/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:07:25 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/26 20:22:32 by jhesso           ###   ########.fr       */
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
	init_mlx(&game, "so_long");
	get_img(&game, game.width, game.height);
	init_sprite(&game);
	draw_map(&game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_key_hook(game.win, key_press, &game);
	mlx_loop(&game.mlx);
}
