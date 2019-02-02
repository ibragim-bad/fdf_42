#ifndef FDF_H
# define FDF_H

typedef struct		s_libx
{
	void *mlx_ptr;
	void *win_ptr;
}					t_libx;

typedef struct		s_pix
{
	int	x;
	int	y;
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
void	*draw_line(t_libx *mlx);
void	*window();
int		abs(int a);

#endif
