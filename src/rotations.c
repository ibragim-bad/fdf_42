/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrankly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:17:45 by jfrankly          #+#    #+#             */
/*   Updated: 2019/02/14 18:24:37 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(int *y, int *z, double a, t_fdf *fdf)
{
	int previous_y;

	*y -= fdf->lines * fdf->offset / 2;
	*z -= 0;
	previous_y = *y;
	*y = previous_y * cos(a) + *z * sin(a) + fdf->lines * fdf->offset / 2;
	*z = -previous_y * sin(a) + *z * cos(a);
}

void	rotate_y(int *x, int *z, double b, t_fdf *fdf)
{
	int previous_x;

	*x -= fdf->chars * fdf->offset / 2;
	previous_x = *x;
	*x = previous_x * cos(b) + *z * sin(b) + fdf->chars * fdf->offset / 2;
	*z = -previous_x * sin(b) + *z * cos(b);
}

void	rotate_z(int *x, int *y, double c, t_fdf *fdf)
{
	int previous_x;
	int previous_y;

	*x -= fdf->chars * fdf->offset / 2;
	*y -= fdf->lines * fdf->offset / 2;
	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(c) - previous_y * sin(c) \
	+ fdf->lines * fdf->offset / 2;
	*y = previous_x * sin(c) + previous_y * cos(c) \
	+ fdf->chars * fdf->offset / 2;
}
