#include "./minilibx/mlx.h"
#include "fdf.h"
#include <stdlib.h>

int		int_nul(int (* mat)[51])
{
	int	i;
	int	j;

	i = 0;
	while (i < 51)
	{
		j = 0;
		while (j++ < 51)
		{
			mat[i][j] = 0;
			if (j == 50)
				mat[i][j] = 1;
		}
		i++;
	}
	mat[50][0] = 1;
}

int		matrix(t_libx *mlx)
{
	int		mat[51][51];
	int		i;
	int		j;
	int		s;

	s = 30;
	i = 0;
	int_nul(mat);
	while (!mat[i + 1][0])
	{
		j = 0;
 		while (!mat[i][j + 1])
		{
		 	draw_line(mlx,i * s, j * s, (i + 1) *s, j * s);
			draw_line(mlx,i * s, j * s, i *s, (j + 1) * s);
			j++;
		}
		i++;
	}
	return (0);
}
