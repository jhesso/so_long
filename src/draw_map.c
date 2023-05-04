/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:19:40 by jhesso            #+#    #+#             */
/*   Updated: 2023/05/04 15:37:05 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
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
