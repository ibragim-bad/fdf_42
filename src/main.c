/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrankly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:31:24 by jfrankly          #+#    #+#             */
/*   Updated: 2019/02/11 18:32:38 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>

int	ft_init(t_fdf *fdf)
{
	fdf->x_z = 10;
	fdf->a = 0;
	fdf->b = 0;
	fdf->c = 0;
	fdf->menu = 0;
	fdf->col_code = 0;
	if (tab_filler(fdf) == -1)
	{
		ft_putendl("Error");
		return (-1);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_fdf fdf;

	if (ac != 2)
	{
		ft_putendl("usage: fdf \"name of file\"\n");
		return (1);
	}
	if (((fdf.fd = open(av[1], O_RDONLY)) == -1))
	{
		ft_putendl("error fd\n");
		return (1);
	}
	fdf.name = av[1];
	if (ft_init(&fdf))
		return (1);
	if ((setup_mlx(&fdf)))
		free_map_color(&fdf);
	write(1, "a", 1);
	return (0);
}
