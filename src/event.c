/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:06:22 by jhesso            #+#    #+#             */
/*   Updated: 2023/05/04 18:14:25 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	move()
*	re-draw the map once we have moved
*/
void	move(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	game->player.moves++;
}

/*	print_moves()
*	prints the amount of times the player has moved both on screen and
*	terminal
*/
void	print_moves(t_game *game)
{
	char	*moves;
	char	*num;

	num = ft_itoa(game->player.moves);
	moves = ft_strjoin("moves: ", num);
	mlx_string_put(game->mlx, game->win, 5, 5, GREEN, moves);
	ft_printf("%s\n", moves);
	free(moves);
	free(num);
}

/*	close_game()
*	destroys the window and exits with EXIT_SUCCESS
*/
int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

/*	key_press()
*	handles all keypresses
*	we're only looking for wasd for movement and ESC to exit the game
*/
int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_game(game);
	else if (keycode == W || keycode == UP)
	{
		if (move_up(game, game->player_x, game->player_y))
			move(game);
	}
	else if (keycode == A || keycode == LEFT)
	{
		if (move_left(game, game->player_x, game->player_y))
			move(game);
	}
	else if (keycode == S || keycode == DOWN)
	{
		if (move_down(game, game->player_x, game->player_y))
			move(game);
	}
	else if (keycode == D || keycode == RIGHT)
	{
		if (move_right(game, game->player_x, game->player_y))
			move(game);
	}
	print_moves(game);
	return (0);
}
