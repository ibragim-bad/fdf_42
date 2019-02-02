#ifndef FDF_H
# define FDF_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "./minilibx/mlx.h"
#include <stdlib.h>
#include "./libft/libft.h"
#include "./libft/get_next_line.h"

typedef struct		s_libx
{
	void *mlx_ptr;
	void *win_ptr;
}					t_libx;

typedef struct		s_pix
{
	int	x;
	int	y;
	int z;
	void *next;
}					t_pix;

typedef struct		s_line
{
	int x0;
	int y0;
	int x1;
	int y1;
}					t_line;

typedef struct		s_delta
{
	int dx;
	int dy;
	int D;
}					t_delta;

void	plotLine(t_line *line, t_libx *mlx);
void	plotLineLow(t_line	*line, t_libx *mlx);
void plotLineHigh(t_line *line, t_libx *mlx);
void *draw_line(t_libx *mlx, int x0,int y0,int x1,int y1);
void	*window();
int		abs(int a);
int		matrix(t_libx *mlx);

#endif
