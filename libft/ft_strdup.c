/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrankly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:21:07 by jfrankly          #+#    #+#             */
/*   Updated: 2018/12/03 16:50:57 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *str)
{
	char		*dst;
	char		*p;

	if ((dst = (char *)malloc(ft_strlen(str) + 1)) == NULL)
		return (0);
	p = dst;
	while (*str)
		*p++ = *str++;
	*p = '\0';
	return (dst);
}
