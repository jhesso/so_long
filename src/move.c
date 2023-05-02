/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:34:55 by jhesso            #+#    #+#             */
/*   Updated: 2023/05/02 20:38:51 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_win(t_game *game)
{
	if (game->player.collectibles != game->map.collectibles)
		return (0);
	game_won(game);
	return (1);
}

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
