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

typedef struct	s_map
{
	char		*line;
	struct		s_map *next;
}				t_map;

/* utils.c */
void	clean_exit(int err_code, char **map, t_mlx *mlx);
int		error(int err_code);

/* read_map.c */
char	**read_map(char *file);

/* map_validation.c */
void	map_validate(char **map);

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
void	debug_print_map(t_map *map);

#endif
