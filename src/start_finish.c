/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_first.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balvyn-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 22:26:12 by balvyn-s          #+#    #+#             */
/*   Updated: 2019/02/11 19:39:18 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	swap_points(t_line *l)
{
	ft_swap(&(l->start->x), &(l->end->x));
	ft_swap(&(l->start->y), &(l->end->y));
	ft_swap(&(l->start->color), &(l->end->color));
}

int		ft_abs(int a)
{
	return (a > 0 ? a : -a);
}

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		finish(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img.img_ptr);
	mlx_destroy_window(fdf->mlx, fdf->win);
	free_map_color(fdf);
	exit(0);
	return (0);
}

int		start_pos(int key, t_fdf *fdf)
{
	if (key == KB_3)
	{
		fdf->offset = WIN_HEIGHT / (2 * fdf->lines) + 2;
		fdf->pad_x = WIN_WIDTH / (fdf->lines / 2) + fdf->offset * fdf->lines;
		fdf->pad_y = WIN_HEIGHT / 6;
		fdf->x_z = 10;
		fdf->a = 0;
		fdf->b = 0;
		fdf->c = 0;
	}
	return (0);
}
