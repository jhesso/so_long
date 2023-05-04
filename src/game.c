/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:07:25 by jhesso            #+#    #+#             */
/*   Updated: 2023/05/04 15:38:54 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	game_won()
*	call this function when the game is won
*	frees all allocated memory and exits with (0)
*/
void	game_won(t_game *game)
{
	ft_printf("Congrats, you won the game!\n");
	close_game(game);
}

/*	game_init()
*	start of the game loop
*/
void	game_init(t_map map, t_player player)
{
	t_game	game;

	game.map_cpy = map.map;
	game.map = map;
	// print_string_arr(game.map.map);
	game.player = player;
	game.player_x = player.pos.x;
	game.player_y = player.pos.y;
	game.player.collectibles = 0;
	game.player.win_condition = 0;
	game.player.moves = 0;
	calculate_window_size(&game);
	init_mlx(&game, "so_long");
	get_img(&game, game.width, game.height);
	init_sprite(&game);
	draw_map(&game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_key_hook(game.win, key_press, &game);
	mlx_loop(&game.mlx);
}
