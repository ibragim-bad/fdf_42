/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_gradient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balvyn-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 22:11:01 by balvyn-s          #+#    #+#             */
/*   Updated: 2019/02/14 13:29:41 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		get_color(t_point *current, t_point *start, t_point *end)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current->x - start->x > current->y - start->y)
		percentage = percent(start->x, end->x, current->x);
	else
		percentage = percent(start->y, end->y, current->y);
	red = get_light((start->color >> 16) & 0xFF,
					(end->color >> 16) & 0xFF, percentage);
	green = get_light((start->color >> 8) & 0xFF,
			(end->color >> 8) & 0xFF, percentage);
	blue = get_light(start->color & 0xFF, end->color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

void	menu_init(t_fdf *fdf)
{
	if (fdf->menu == 0)
	{
		mlx_string_put(fdf->mlx, fdf->win, 50, 50, \
		0xFFFFFF, "use arrows to navigate");
		mlx_string_put(fdf->mlx, fdf->win, 50, 70, \
		0xFFFFFF, "press +/- to zoom");
		mlx_string_put(fdf->mlx, fdf->win, 50, 90, \
		0xFFFFFF, "use q/w/a/s/z/x to rotate");
		mlx_string_put(fdf->mlx, fdf->win, 50, 110, \
		0xFFFFFF, "use 1/2 to resize height");
		mlx_string_put(fdf->mlx, fdf->win, 50, 130, \
		0xFFFFFF, "use 3 to return start image");
		mlx_string_put(fdf->mlx, fdf->win, 50, 150, \
		0xFFFFFF, "press 4 to change colour");
		mlx_string_put(fdf->mlx, fdf->win, 50, 170, \
		0xFFFFFF, "press 5 to hide help");
	}
	else
		mlx_string_put(fdf->mlx, fdf->win, 50, 50, \
		0xFFFFFF, "press 5 to show help");
}
