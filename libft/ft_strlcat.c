/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrankly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:52:30 by jfrankly          #+#    #+#             */
/*   Updated: 2018/11/29 18:53:11 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t len;

	len = ft_strlen(dest);
	if (size > len)
		ft_strncat(dest, src, (size - len - 1));
	if (size < len)
		return (size + ft_strlen(src));
	return (len + ft_strlen(src));
}
