/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balvyn-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 22:32:18 by balvyn-s          #+#    #+#             */
/*   Updated: 2019/02/11 18:34:12 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(int *x, int *y, int z, t_fdf *fdf)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599) + fdf->pad_x;
	*y = -(z + fdf->offset) + (previous_x + previous_y)
		* sin(0.523599) + fdf->pad_y;
}

int		draw_horizontal(t_fdf *fdf)
{
	t_point *f_point;
	t_point *s_point;

	fdf->t_x = 0;
	fdf->t_y = 0;
	fdf->n = 0;
	while (fdf->n != fdf->lines)
	{
		fdf->m = 0;
		while (fdf->m != fdf->chars - 1)
		{
			f_point = get_point(fdf->t_x, fdf->t_y, fdf);
			fdf->t_x += fdf->offset;
			fdf->m++;
			s_point = get_point(fdf->t_x, fdf->t_y, fdf);
			if ((put_line(get_t_line(f_point, s_point), fdf)))
				return (1);
			free(f_point);
			free(s_point);
		}
		fdf->t_x = 0;
		fdf->t_y += fdf->offset;
		fdf->n++;
	}
	return (0);
}

int		draw_vertical(t_fdf *fdf)
{
	t_point *f_point;
	t_point *s_point;

	fdf->m = 0;
	fdf->t_x = 0;
	fdf->t_y = 0;
	while (fdf->m != fdf->chars)
	{
		fdf->n = 0;
		while (fdf->n != fdf->lines - 1)
		{
			f_point = get_point(fdf->t_x, fdf->t_y, fdf);
			fdf->t_y += fdf->offset;
			fdf->n++;
			s_point = get_point(fdf->t_x, fdf->t_y, fdf);
			if ((put_line(get_t_line(f_point, s_point), fdf)))
				return (1);
			free(f_point);
			free(s_point);
		}
		fdf->t_y = 0;
		fdf->t_x += fdf->offset;
		fdf->m++;
	}
	return (0);
}

int		setup_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	if ((draw_init(fdf)))
		return (1);
	mlx_hook(fdf->win, 2, 5, key_press, fdf);
	mlx_hook(fdf->win, 17, 0, finish, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}

int		draw_init(t_fdf *fdf)
{
	fdf->img.img_ptr = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	fdf->img.data = (int *)mlx_get_data_addr(fdf->img.img_ptr, \
		&(fdf->img.bpp), &(fdf->img.size_l), &(fdf->img.endian));
	if ((draw_horizontal(fdf)))
		return (1);
	if ((draw_vertical(fdf)))
		return (1);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img_ptr, 0, 0);
	menu_init(fdf);
	return (0);
}
