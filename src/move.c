/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:34:55 by jhesso            #+#    #+#             */
/*   Updated: 2023/05/04 15:57:29 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	check_win()
*	checks if we are able to "win" the game
*	returns 0 if we have not collected all collectibles yet, otherwise calls
*	the game_won function which closes the game
*/
int	check_win(t_game *game)
{
	if (game->player.collectibles != game->map.collectibles)
		return (0);
	game_won(game);
	return (1);
}

/*	move_up
*	checks everything necessary above our players current location and moves
*	the player up
*/
int	move_up(t_game *game, int x, int y)
{
	if (game->map.map[y - 1][x] == '1')
		return (0);
	game->player_y = y - 1;
	if (game->map.map[y - 1][x] == 'C')
	{
		game->map.map[y][x] = '0';
		game->player.collectibles++;
	}
	if (game->map.exit == 1)
	{
		game->map.exit = 2;
		game->map.map[y][x] = 'E';
	}
	else if (game->map.map[y - 1][x] == 'E')
	{
		if (!check_win(game))
			game->map.exit = 1;
		game->map.map[y][x] = '0';
	}
	else
		game->map.map[y][x] = '0';
	game->map.map[y - 1][x] = 'P';
	return (1);
}

/*	move_left
*	checks everything necessary left of our players current location
*	and moves the player left
*/
int	move_left(t_game *game, int x, int y)
{
	if (game->map.map[y][x - 1] == '1')
		return (0);
	game->player_x = x - 1;
	if (game->map.map[y][x - 1] == 'C')
	{
		game->map.map[y][x] = '0';
		game->player.collectibles++;
	}
	if (game->map.exit == 1)
	{
		game->map.exit = 2;
		game->map.map[y][x] = 'E';
	}
	else if (game->map.map[y][x - 1] == 'E')
	{
		if (!check_win(game))
			game->map.exit = 1;
		game->map.map[y][x] = '0';
	}
	else
		game->map.map[y][x] = '0';
	game->map.map[y][x - 1] = 'P';
	return (1);
}

/*	move_down
*	checks everything necessary below our players current location and moves
*	the player down
*/
int	move_down(t_game *game, int x, int y)
{
	if (game->map.map[y + 1][x] == '1')
		return (0);
	game->player_y = y + 1;
	if (game->map.map[y + 1][x] == 'C')
	{
		game->map.map[y][x] = '0';
		game->player.collectibles++;
	}
	if (game->map.exit == 1)
	{
		game->map.exit = 2;
		game->map.map[y][x] = 'E';
	}
	else if (game->map.map[y + 1][x] == 'E')
	{
		if (!check_win(game))
			game->map.exit = 1;
		game->map.map[y][x] = '0';
	}
	else
		game->map.map[y][x] = '0';
	game->map.map[y + 1][x] = 'P';
	return (1);
}

/*	move_right
*	checks everything necessary to the right of our players current location
*	and moves the player right
*/
int	move_right(t_game *game, int x, int y)
{
	if (game->map.map[y][x + 1] == '1')
		return (0);
	game->player_x = x + 1;
	if (game->map.map[y][x + 1] == 'C')
	{
		game->map.map[y][x] = '0';
		game->player.collectibles++;
	}
	if (game->map.exit == 1)
	{
		game->map.exit = 2;
		game->map.map[y][x] = 'E';
	}
	else if (game->map.map[y][x + 1] == 'E')
	{
		if (!check_win(game))
			game->map.exit = 1;
		game->map.map[y][x] = '0';
	}
	else
		game->map.map[y][x] = '0';
	game->map.map[y][x + 1] = 'P';
	return (1);
}
