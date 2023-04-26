/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:07:25 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/26 19:10:47 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprite(t_game *game)
{
	int	x;
	int	y;

	game->wall = mlx_xpm_file_to_image(game->mlx.mlx, "./textures/wall.xpm", &x, &y);
	game->empty = mlx_xpm_file_to_image(game->mlx.mlx, "./textures/empty.xpm", &x, &y);
	game->player_img = mlx_xpm_file_to_image(game->mlx.mlx, "./textures/Pink_Monster.xpm", &x, &y);
	game->collectible = mlx_xpm_file_to_image(game->mlx.mlx, "./textures/wall.xpm", &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlx.mlx, "./textures/wall.xpm", &x, &y);
}

void	assign_image(t_game *game, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->wall, x, y);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->empty, x, y);
	else if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->empty, x, y);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->player_img, x, y);
	}
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->collectible, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->exit, x, y);
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
