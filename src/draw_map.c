/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:19:40 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/26 19:58:29 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprite(t_game *game)
{
	int	x;
	int	y;

	game->wall = mlx_xpm_file_to_image(game->mlx.mlx, WALL, &x, &y);
	game->empty = mlx_xpm_file_to_image(game->mlx.mlx, EMPTY, &x, &y);
	game->character = mlx_xpm_file_to_image(game->mlx.mlx, CHAR, &x, &y);
	game->collectible = mlx_xpm_file_to_image(game->mlx.mlx, COLLECT, &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlx.mlx, EXIT, &x, &y);
}

void	assign_image(t_game *game, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->wall, x, y);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->empty, x, y);
	else if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->empty, x, y);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->character, x, y);
	}
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->collectible, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->exit, x, y);
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
			assign_image(game, game->map.map[y][x], x * SPRITE_SIZE, y * SPRITE_SIZE);
			x++;
		}
		y++;
	}
	return (1);
}
