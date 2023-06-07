/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:19:40 by jhesso            #+#    #+#             */
/*   Updated: 2023/06/07 15:44:16 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	init_sprite()
*	load all sprites to memory
*/
void	init_sprite(t_game *game)
{
	int	x;
	int	y;

	game->wall = mlx_xpm_file_to_image(game->mlx, WALL, &x, &y);
	game->empty = mlx_xpm_file_to_image(game->mlx, EMPTY, &x, &y);
	game->character = mlx_xpm_file_to_image(game->mlx, CHAR, &x, &y);
	game->collectible = mlx_xpm_file_to_image(game->mlx, COLLECT, &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlx, EXIT, &x, &y);
	game->exit_open = mlx_xpm_file_to_image(game->mlx, EXIT_O, &x, &y);
}

/*	assign_image()
*	select which image goes to the spot we're looking at, also swaps the exit
*	to the open version once all collectibles are collected by the player
*/
void	assign_image(t_game *game, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall, x, y);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->empty, x, y);
	else if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->empty, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->character, x, y);
	}
	else if (c == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->empty, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->collectible, x, y);
	}
	else if (c == 'E' && game->player.collectibles != game->map.collectibles)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->empty, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->exit, x, y);
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->empty, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->exit_open, x, y);
	}
}

// static void	get_top_left_y(t_game *game, int *y)
// {
// 	*y = 0;
// 	if (game->player_y - 33 / 2 > 0)
// 	{
// 		if (game->map.rows - game->player_y > 33 / 2)
// 			*y = game->player_y - 33 / 2;
// 		else
// 			*y = game->map.rows - 33;
// 	}
// }

// /*	center_player()
// *	incase we get a big map (when drawn is more than 1920x1080)
// *	center the screen around the player
// */
// static int	center_player(t_game *g, int row, int col, int x)
// {
// 	int	y;

// 	get_top_left_y(g, &y);
// 	while (y < g->map.rows)
// 	{
// 		col = 0;
// 		x = 0;
// 		if (g->player_x - 60 / 2 > 0)
// 		{
// 			if (g->map.cols - g->player_x > 60 / 2)
// 				x = g->player_x - 60 / 2;
// 			else
// 				x = g->player_x - 60;
// 		}
// 		while (col < g->map.cols)
// 		{
// 			assign_image(g, g->map.map[y][x], col * SIZE, row * SIZE);
// 			col++;
// 			x++;
// 		}
// 		row++;
// 		y++;
// 	}
// 	return (1);
// }

/*	draw_map()
*	go through the map and put the corresponding sprite to the screen
*/
int	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	// if ((game->map.rows > 33 || game->map.cols > 60) && (game->player_y > 33 / 2
	// 		|| game->player_x > 60 / 2))
	// 	return (center_player(game, 0, 0, 0));
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			assign_image(game, game->map.map[y][x], x * SIZE, y * SIZE);
			x++;
		}
		y++;
	}
	return (1);
}
