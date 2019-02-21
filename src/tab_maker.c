/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balvyn-s <balvyn-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:21:33 by jfrankly          #+#    #+#             */
/*   Updated: 2019/02/11 21:38:17 by balvyn-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_put_sizes(t_fdf *fdf)
{
	char	*line;
	int		ret;

	line = NULL;
	fdf->lines = 0;
	fdf->chars = 0;
	while ((ret = get_next_line(fdf->fd, &line)) == 1)
	{
		if (line_val(fdf, line) == -1)
			return (-1);
	}
	fdf->offset = WIN_HEIGHT / (2 * fdf->lines) + 2;
	fdf->pad_x = WIN_WIDTH / (fdf->lines / 2) + fdf->offset * fdf->lines;
	fdf->pad_y = WIN_HEIGHT / 6;
	return (0);
}

int	tab_make(t_fdf *fdf)
{
	if (ft_put_sizes(fdf) == -1)
		return (-1);
	if (!(fdf->map = (int **)ft_memalloc(sizeof(int *) * fdf->lines)))
		return (-1);
	if (!(fdf->color = (int **)ft_memalloc(sizeof(int *) * fdf->lines)))
		return (-1);
	close(fdf->fd);
	if (((fdf->fd = open(fdf->name, O_RDONLY)) == -1))
		return (-1);
	return (0);
}

int	get_cords(t_fdf *fdf)
{
	int		i;
	int		j;
	int		ret;
	char	*line;
	char	**tab;

	i = 0;
	while ((ret = get_next_line(fdf->fd, &line)) > 0)
	{
		j = 0;
		tab = ft_strsplit(line, ' ');
		if (!(fdf->map[i] = ft_memalloc(sizeof(int) * fdf->chars)))
			return (-1);
		if (!(fdf->color[i] = ft_memalloc(sizeof(int) * fdf->chars)))
			return (-1);
		while (tab[j] != NULL)
		{
			fdf->map[i][j] = ft_atoi(tab[j]);
			fdf->color[i][j] = ft_getcol(tab[j]);
			j++;
		}
		ft_arrclr(tab);
		i++;
	}
	return (0);
}
