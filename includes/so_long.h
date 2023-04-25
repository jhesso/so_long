#ifndef SO_LONG_H
# define SO_LONG_H

// # include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "../libft/includes/libft.h"

# ifndef BUFF
#  define BUFF 42
# endif

typedef struct	s_mlx
{
	void		*mlx;
	void		*window;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
	int			color;
	int			height;
	int			width;
	int			coord_x;
	int			coord_y;
}				t_mlx;

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

typedef struct	s_vector
{
	int			x;
	int			y;
}				t_vector;

/*	s_player
*	contains information of the player
*	(position (x, y) and any other useful information I deem necessary)
*/
typedef struct	s_player
{
	int			collectibles;
	t_vector	pos;
}				t_player;


/* utils.c */
void	clean_exit(int err_code, char **map, t_mlx *mlx);
int		error(int err_code);
int		get_rows(char **map);

/* read_map.c */
char	**read_map(char *file);

/* map_validation.c */
void	map_validate(t_map *map, t_player *player);

/* map_coordinates.c */
void	get_coordinates(t_map *map, t_player *player);

/* flood_fill.c */
int		flood_fill(t_map *map, t_vector pos, int **coord_map);

/* mlx_init.c */
t_mlx	init_mlx(int width, int height, char *title);
t_mlx	get_img(t_mlx mlx, int width, int height);

/* draw.c */
void	draw_pixel(t_mlx *mlx, int x, int y, int color);

/* event.c */
int	key_press(int keycode, t_mlx *mlx);

/* move.c */
int	move(int keycode, t_mlx *mlx);

/* sandbox.c */
void	draw_square(t_mlx *mlx, int size);
// void	draw_line_horizontal(t_img *img, t_coordinates start, t_coordinates end,
 							// int color);

/* debug.c */
void	debug_print_coordinate_map(t_map map);

#endif
