/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:21:24 by jhesso            #+#    #+#             */
/*   Updated: 2023/06/09 13:41:55 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/******************************************************************************/
/*								Includes  									  */
/******************************************************************************/

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>

# include "../libft/includes/libft.h"

/******************************************************************************/
/*								Defines  									  */
/******************************************************************************/

# ifndef SIZE
#  define SIZE 32
# endif

# ifndef WALL
#  define WALL "./textures/wall.xpm"
# endif

# ifndef EMPTY
#  define EMPTY "./textures/empty.xpm"
# endif

# ifndef CHAR
#  define CHAR "./textures/Pink_Monster.xpm"
# endif

# ifndef COLLECT
#  define COLLECT "./textures/coin.xpm"
# endif

# ifndef EXIT
#  define EXIT "./textures/exit_door.xpm"
# endif

# ifndef EXIT_O
#  define EXIT_O "./textures/exit_door_open.xpm"
# endif

# ifndef BUFF
#  define BUFF 42
# endif

# ifndef GREEN
#  define GREEN 0x00FF00
# endif

enum e_key
{
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	ESC = 53,
	UP = 126,
	DOWN = 125,
	RIGHT = 124,
	LEFT = 123
};

/******************************************************************************/
/*								Structs 									  */
/******************************************************************************/

typedef struct s_vector
{
	int			x;
	int			y;
}				t_vector;

typedef struct s_map
{
	char		**map;
	int			**coordinate_map;
	int			rows;
	int			cols;
	int			collectibles;
	int			start;
	int			exit;
	int			c;
}				t_map;

typedef struct s_player
{
	int			collectibles;
	int			win_condition;
	int			moves;
	t_vector	pos;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	char		**map_cpy;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
	int			width;
	int			height;
	int			player_x;
	int			player_y;
	t_map		map;
	t_player	player;
	void		*wall;
	void		*empty;
	void		*character;
	void		*collectible;
	void		*exit;
	void		*exit_open;
}				t_game;

/******************************************************************************/
/*								  Functions									  */
/******************************************************************************/

/*--------------------------Utils and error handling--------------------------*/
/* utils.c */
int		get_rows(char **map);
void	free_map(char **map, int **coordinate_map);

/* error.c */
void	error(int err_code);

/* debug.c */
void	debug_print_coordinate_map(t_map map);

/*------------------------------------Map-------------------------------------*/
/* read_map.c */
char	**read_map(char *file);

/* map_validation.c */
void	map_validate(t_map *map, t_player *player);

/* map_coordinates.c */
void	get_coordinates(t_map *map, t_player *player);

/* flood_fill.c */
int		flood_fill(t_map *map, t_vector pos, int **coord_map);

/*----------------------------------Game--------------------------------------*/
/* game.c */
void	game_init(t_map map, t_player player);
void	game_won(t_game *game);

/* window.c */
void	calculate_window_size(t_game *game);

/*	draw_map.c */
void	init_sprite(t_game *game);
void	assign_image(t_game *game, char c, int x, int y);
int		draw_map(t_game *game);

/* event.c */
int		close_game(t_game *game);
int		key_press(int keycode, t_game *game);
int		check_win(t_game *game);
void	print_moves(t_game *game);

/* move.c */
void	move(t_game *game);
int		move_up(t_game *game, int x, int y);
int		move_left(t_game *game, int x, int y);
int		move_down(t_game *game, int x, int y);
int		move_right(t_game *game, int x, int y);

/* mlx_init.c */
void	init_mlx(t_game *game, char *title);
void	get_img(t_game *game, int width, int height);

#endif
