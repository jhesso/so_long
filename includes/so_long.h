/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:21:24 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/26 20:23:24 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "../libft/includes/libft.h"

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
#  define COLLECT "./textures/wall.xpm"
# endif

# ifndef EXIT
#  define EXIT "./textures/wall.xpm"
# endif

# ifndef BUFF
#  define BUFF 42
# endif

enum e_key
{
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	ESC = 53
};

typedef struct	s_vector
{
	int			x;
	int			y;
}				t_vector;

/*	s_map
*	contains all information gathered about the given map
*/
typedef struct	s_map
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

/*	s_player
*	contains information of the player
*	(position (x, y) and any other useful information I deem necessary)
*/
typedef struct	s_player
{
	int			collectibles;
	t_vector	pos;
}				t_player;

/*	s_game
*	contains all information needed for the game
*/
typedef struct	s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
	int			width;
	int			height;
	t_map		map;
	t_player	player;
	void		*wall;
	void		*empty;
	void		*character;
	void		*collectible;
	void		*exit;
}				t_game;

/* utils.c */
void	clean_exit(int err_code, char **map, t_mlx *mlx);
int		error(int err_code);
int		get_rows(char **map);

/* debug.c */
void	debug_print_coordinate_map(t_map map);

/**********/
/*	 MAP  */
/**********/
/* read_map.c */
char	**read_map(char *file);

/* map_validation.c */
void	map_validate(t_map *map, t_player *player);

/* map_coordinates.c */
void	get_coordinates(t_map *map, t_player *player);

/* flood_fill.c */
int		flood_fill(t_map *map, t_vector pos, int **coord_map);

/**********/
/*	GAME  */
/**********/
/* game.c */
void	game_init(t_map map, t_player player);

/* window.c */
void	calculate_window_size(t_game *game);

/*	draw_map.c */
void	init_sprite(t_game *game);
void	assign_image(t_game *game, char c, int x, int y);
int		draw_map(t_game *game);

/* event.c */
int	close_game(t_game *game);
int	key_press(int keycode, t_game *game);

/* mlx_init.c */
void	init_mlx(t_game *game, char *title);
void	get_img(t_game *game, int width, int height);

#endif
