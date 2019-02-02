/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrankly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:26:34 by jfrankly          #+#    #+#             */
/*   Updated: 2018/12/12 17:29:21 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_check_n_copy(char **stock, char **line)
{
	char	*tmp;

	tmp = ft_strchr(*stock, '\n');
	if (tmp)
	{
		*line = ft_strsub(*stock, 0, tmp - *stock);
		ft_memmove(*stock, tmp + 1, ft_strlen(tmp));
		tmp = NULL;
		return (1);
	}
	return (0);
}

int				fill_stock(int const fd, char **line, char **stock)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if (!(*stock))
		{
			if (!(*stock = ft_strdup(buf)))
				return (-1);
		}
		else if (*stock)
		{
			tmp = ft_strjoin(*stock, buf);
			free(*stock);
			*stock = tmp;
		}
		if (ft_check_n_copy(stock, line))
			return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static	char	*stock[12000];
	int				rtrn;

	if (fd < 0 || fd > 12000 || !line || BUFF_SIZE < 1 || BUFF_SIZE > 10000000)
		return (-1);
	if (stock[fd] && ft_check_n_copy(&stock[fd], line))
		return (1);
	rtrn = fill_stock(fd, line, &stock[fd]);
	if (rtrn != 0)
		return (rtrn);
	if (stock[fd] == NULL || stock[fd][0] == '\0')
		return (0);
	*line = stock[fd];
	stock[fd] = NULL;
	return (1);
}
