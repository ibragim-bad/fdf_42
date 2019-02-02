/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrankly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:02:05 by jfrankly          #+#    #+#             */
/*   Updated: 2018/12/02 15:12:00 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hst, const char *ndl, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l;

	l = 0;
	i = 0;
	j = 0;
	while (ndl[l])
		l++;
	if (l == 0)
		return ((char *)hst);
	while (hst[i] && i < len)
	{
		while (hst[i + j] == ndl[j] && len > (i + j))
		{
			if (j == l - 1)
				return ((char *)hst + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
