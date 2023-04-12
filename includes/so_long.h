#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx;
	void		*window;
}				t_mlx;

typedef struct	s_coordinates
{
	int			x;
	int			y;
	int			z;
}				t_coordinates;

/* mlx_init.c */
t_mlx	init_mlx(int width, int height, char *title);
t_img	get_img(t_mlx mlx, int width, int height);

/* draw.c */
void	draw_pixel(t_img *img, int x, int y, int color);

/* event.c */
int	key_press(int keycode, t_mlx *mlx);

/* move.c */
int	move(int keycode, t_mlx *mlx);

/* sandbox.c */
void	draw_square(t_img img, t_coordinates coordinates, int size);
void	draw_line_horizontal(t_img *img, t_coordinates start, t_coordinates end,\
							int color);

#endif
