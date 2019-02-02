/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrankly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:10:17 by jfrankly          #+#    #+#             */
/*   Updated: 2018/11/29 17:19:59 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *p1;
	unsigned char *p2;

	p1 = dest;
	p2 = (unsigned char *)src;
	if (p2 < p1)
		while (n--)
			*(p1 + n) = *(p2 + n);
	else
		while (n--)
			*(p1++) = *(p2++);
	return (dest);
}
