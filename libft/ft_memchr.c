/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrankly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:16:14 by jfrankly          #+#    #+#             */
/*   Updated: 2018/11/29 18:53:55 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (NULL);
	while (i < n)
	{
		if (((unsigned char *)arr)[i] == ((unsigned char)c))
			return (&((unsigned char *)arr)[i]);
		i++;
	}
	return (NULL);
}
