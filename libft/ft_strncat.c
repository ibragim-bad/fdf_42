/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrankly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:51:15 by jfrankly          #+#    #+#             */
/*   Updated: 2018/12/02 19:16:55 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *app, size_t n)
{
	char		*p;
	char		*a;

	p = dest + ft_strlen(dest);
	a = (char *)app;
	while (*a && n--)
		*p++ = *a++;
	*p = '\0';
	return (dest);
}
