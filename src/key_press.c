/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balvyn-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 22:27:26 by balvyn-s          #+#    #+#             */
/*   Updated: 2019/02/14 13:28:23 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		zoom(int key, t_fdf *fdf)
{
	if (key == KB_PLS)
	{
		if (fdf->offset < 50)
		{
			fdf->offset += OFFSET;
			if (fdf->x_z <= 10 && fdf->x_z != 0)
				fdf->x_z += ZZZ;
		}
	}
	else if (key == KB_MIN)
	{
		if (fdf->offset > 5)
		{
			fdf->offset -= OFFSET;
			if (fdf->x_z >= 2)
				fdf->x_z -= ZZZ;
		}
	}
	return (0);
}

int		high_z(int key, t_fdf *fdf)
{
	if (key == KB_1)
	{
		if (fdf->x_z < 10)
			fdf->x_z += ZZZ;
	}
	else if (key == KB_2)
	{
		if (fdf->x_z >= 1)
			fdf->x_z -= ZZZ;
	}
	else if (key == KB_5)
		fdf->menu = (fdf->menu == 0) ? 1 : 0;
	else if (key == KB_4)
		fdf->col_code += (fdf->col_code == 4) ? -4 : 1;
	return (0);
}

int		moving(int key, t_fdf *fdf)
{
	if (key == KB_UP)
		fdf->pad_y += PADDING;
	else if (key == KB_DOWN)
		fdf->pad_y -= PADDING;
	else if (key == KB_LEFT)
		fdf->pad_x += PADDING;
	else if (key == KB_RIGHT)
		fdf->pad_x -= PADDING;
	return (0);
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == KP_Q)
		fdf->a += 0.05;
	else if (key == KP_W)
		fdf->a -= 0.05;
	else if (key == KP_S)
		fdf->b -= 0.05;
	else if (key == KP_A)
		fdf->b += 0.05;
	else if (key == KB_I)
		fdf->c += 0.05;
	else if (key == KB_U)
		fdf->c -= 0.05;
}

int		key_press(int key, t_fdf *fdf)
{
	if (key == KB_ESC)
		finish(fdf);
	zoom(key, fdf);
	high_z(key, fdf);
	moving(key, fdf);
	rotate(key, fdf);
	start_pos(key, fdf);
	mlx_destroy_image(fdf->mlx, fdf->img.img_ptr);
	if ((draw_init(fdf)))
		finish(fdf);
	return (0);
}
