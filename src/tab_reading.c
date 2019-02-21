/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_life.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrankly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:35:32 by jfrankly          #+#    #+#             */
/*   Updated: 2019/02/11 19:24:13 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_isnum(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((!(ft_isdigit(str[i]))) && (i == 0 && (str[i] != '-')))
			return (0);
		i++;
	}
	return (1);
}

int		line_val(t_fdf *fdf, char *line)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[i])
	{
		if (!(ft_isnum(tab[i])))
			return (-1);
		i++;
	}
	if (fdf->lines == 0)
		fdf->chars = i;
	else
	{
		if (i != fdf->chars)
			return (-1);
	}
	free(line);
	ft_arrclr(tab);
	fdf->lines++;
	return (0);
}

void	free_map_color(t_fdf *fdf)
{
	int i;

	i = 0;
	while (i < fdf->lines)
	{
		free(fdf->map[i]);
		free(fdf->color[i]);
		i++;
	}
	free(fdf->map);
	free(fdf->color);
}

int		tab_filler(t_fdf *fdf)
{
	if (tab_make(fdf) == -1)
		return (-1);
	if (get_cords(fdf) == -1)
		return (-1);
	return (0);
}
