/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balvyn-s <balvyn-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 22:24:10 by balvyn-s          #+#    #+#             */
/*   Updated: 2019/02/11 21:05:01 by balvyn-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx.h"
# include <stdlib.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <math.h>
# include "keys.h"
# define WIN_WIDTH 1200
# define WIN_HEIGHT 1000
# define PADDING 10
# define OFFSET 5
# define ZZZ 1

typedef struct		s_point
{
	int x;
	int y;
	int z;
	int color;
}					t_point;

typedef struct		s_delta
{
	int dx;
	int dy;
	int d;
	int x;
	int y;
}					t_delta;

typedef struct		s_line
{
	t_point			*start;
	t_point			*end;
}					t_line;

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_fdf
{
	int				fd;
	char			*name;
	void			*mlx;
	void			*win;
	int				**map;
	int				lines;
	int				chars;
	int				**color;
	int				offset;
	int				x_z;
	int				pad_x;
	int				pad_y;
	int				n;
	int				m;
	double			a;
	double			b;
	double			c;
	int				t_x;
	int				t_y;
	int				menu;
	t_img			img;
	int				col_code;
}					t_fdf;

int					ft_abs(int a);
void				ft_swap(int *a, int *b);
void				swap_points(t_line *l);
void				ft_printer(t_fdf *fdf);
int					ft_put_sizes(t_fdf *fdf);
int					line_val(t_fdf *fdf, char *line);
int					tab_make(t_fdf *fdf);
int					get_cords(t_fdf *fdf);
int					tab_filler(t_fdf *fdf);
int					key_press(int key, t_fdf *fdf);
int					put_line(t_line *l, t_fdf *fdf);
int					setup_mlx(t_fdf *fdf);
int					draw_init(t_fdf *fdf);
int					win_close(void *param);
void				draw_background(t_fdf *fdf);
t_point				*get_simple_point(int x, int y, int z, t_fdf *fdf);
int					ft_getcol(char *str);
void				free_map_color(t_fdf *fdf);
int					get_color(t_point *current, t_point *start, t_point *end);
int					ft_atoi_base(const char *str, int str_base);
int					start_pos(int key, t_fdf *fdf);
t_point				*get_point(int x, int y, t_fdf *fdf);
void				iso(int *x, int *y, int z, t_fdf *fdf);
t_line				*get_t_line(t_point *f, t_point *s);
void				rotate_x(int *y, int *z, double a, t_fdf *fdf);
void				rotate_y(int *x, int *z, double b, t_fdf *fdf);
void				rotate_z(int *x, int *y, double c, t_fdf *fdf);
int					finish(t_fdf *fdf);
void				menu_init(t_fdf *fdf);

#endif
