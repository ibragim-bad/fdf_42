/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_second.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrankly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:28:12 by jfrankly          #+#    #+#             */
/*   Updated: 2019/02/14 13:29:05 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		define_color(int z, t_fdf *fdf)
{
	if (z <= 0 && fdf->col_code == 0)
		return (0x008000);
	else if (z <= 0 && fdf->col_code == 1)
		return (0x9932CC);
	else if (z <= 0 && fdf->col_code == 2)
		return (0x8B4513);
	else if (z <= 0 && fdf->col_code == 3)
		return (0xFFD700);
	else if (z <= 0 && fdf->col_code == 4)
		return (0x00FF7F);
	if (z < 10)
		return (0x8B4513);
	return (0xffffff);
}

t_point	*get_simple_point(int x, int y, int z, t_fdf *fdf)
{
	t_point *new;

	if ((new = (t_point*)malloc(sizeof(t_point))))
	{
		new->x = x;
		new->y = y;
		new->z = z;
		new->color = define_color(z, fdf);
	}
	return (new);
}

t_point	*get_point(int x, int y, t_fdf *fdf)
{
	t_point *new;

	if (!(new = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = fdf->map[fdf->n][fdf->m] * fdf->x_z;
	rotate_x(&new->y, &new->z, fdf->a, fdf);
	rotate_y(&new->x, &new->z, fdf->b, fdf);
	rotate_z(&new->x, &new->y, fdf->c, fdf);
	if (!(fdf->color[fdf->n][fdf->m]))
		new->color = define_color(fdf->map[fdf->n][fdf->m], fdf);
	else
		new->color = fdf->color[fdf->n][fdf->m];
	iso(&(new->x), &(new->y), new->z, fdf);
	return (new);
}

t_line	*get_t_line(t_point *f, t_point *s)
{
	t_line *new;

	if (!f || !s)
		return (NULL);
	if ((new = (t_line *)malloc(sizeof(t_line))))
	{
		new->start = f;
		new->end = s;
	}
	return (new);
}
