/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrankly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:17:32 by jfrankly          #+#    #+#             */
/*   Updated: 2018/12/04 15:50:59 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hst, const char *ndl)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = 0;
	i = 0;
	j = 0;
	while (ndl[len])
		len++;
	if (len == 0)
		return ((char*)hst);
	while (hst[i])
	{
		while (hst[i + j] == ndl[j])
		{
			if (j == len - 1)
				return ((char *)hst + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
