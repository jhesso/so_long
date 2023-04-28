/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:34:55 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/28 14:50:49 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_game *game)
{

}

void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player.pos.x;
	y = game->player.pos.y;
	if (game->map.map[y - 1][x] == '1')
		return ;
	else if (game->map.map[y - 1][x] == 'C')
		game->player.collectibles++;
	else if (game->map.map[y - 1][x] == 'E')
		check_win(game); // ! need to also return the Exit back on the map if we didnt win
	game->map.map[y - 1][x] = 'P';
	game->map.map[y][x] = '0';
}
