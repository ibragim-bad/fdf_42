/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrankly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:06:26 by jfrankly          #+#    #+#             */
/*   Updated: 2018/11/29 18:49:20 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *p1;
	unsigned char *p2;

	p1 = (unsigned char *)dest;
	p2 = (unsigned char *)src;
	while (n--)
	{
		*(p1++) = *(p2++);
		if (*(p2 - 1) == ((unsigned char)c))
			return (p1);
	}
	return (NULL);
}
