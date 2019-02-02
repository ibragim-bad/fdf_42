#include "./minilibx/mlx.h"
#include "fdf.h"
#include <stdlib.h>

void *window()
{
	t_libx *mlx;

	mlx = (t_libx *)malloc(sizeof(t_libx));
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 500, 500, "mlx 42");
	matrix(mlx);
	mlx_loop(mlx->mlx_ptr);
}

void *draw_line(t_libx *mlx, int x0,int y0,int x1,int y1)
{
	t_line *line;
	line = (t_line *)malloc(sizeof(t_line));
	line->x0 = x0;
	line->x1 = x1;
	line->y0 = y0;
	line->y1 = y1;
	plotLine(line, mlx);
}

void plotLineLow(t_line *line, t_libx *mlx)
{
	int yi;
	t_delta *d;
	t_pix *px;

	d = (t_delta *)malloc(sizeof(t_delta));
	px = (t_pix *)malloc(sizeof(t_pix));
	d->dx = line->x1 - line->x0;
	d->dy = line->y1 - line->y0;
	yi = 1;
	if (d->dy < 0)
	{
		yi = -1;
		d->dy = -(d->dy);
	}
	d->D = 2 * (d->dy) - d->dx;
	px->x = line->x0;
	px->y = line->y0;
	while (px->x < line->x1)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, px->x, px->y, 0xFFFFFFF);
		if (d->D > 0)
		{
			px->y = px->y + yi;
			d->D = d->D - 2 * (d->dx);
		}
		d->D = d->D + 2 * (d->dy);
		px->x++;
	}
}

void plotLineHigh(t_line *line, t_libx *mlx)
{
	int xi;
	t_delta *d;
	t_pix *px;

	d = (t_delta *)malloc(sizeof(t_delta));
	px = (t_pix *)malloc(sizeof(t_pix));
	d->dx = line->x1 - line->x0;
	d->dy = line->y1 - line->y0;
	xi = 1;
	if (d->dx < 0)
	{
		xi = -1;
		d->dx = -(d->dx);
	}
	d->D = 2 * (d->dx) - d->dy;
	px->x = line->x0;
	px->y = line->y0;
	while (px->y < line->y1)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, px->x, px->y, 0xFFFFFFF);
		if (d->D > 0)
		{
			px->x = px->x + xi;
			d->D = d->D - 2 * (d->dy);
		}
		d->D = d->D + 2 * (d->dx);
		px->y++;
	}
}

int		abs(int a)
{
	return (a > 0? a : -a);
}

void	plotLine(t_line *line, t_libx *mlx)
{
  if (abs(line->y1 - line->y0) < abs(line->x1 - line->x0))
  {
    if (line->x0 > line->x1)
      plotLineLow(line, mlx);
    else
       plotLineLow(line, mlx);
  }
  else
  {
    if (line->y0 > line->y1)
      plotLineHigh(line, mlx);
    else
      plotLineHigh(line, mlx);
  }
}
