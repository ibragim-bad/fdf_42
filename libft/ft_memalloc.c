/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrankly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:26:38 by jfrankly          #+#    #+#             */
/*   Updated: 2018/12/02 19:10:43 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memalloc(size_t size)
{
	void		*mem;

	if (size == (size_t)(-1) || !(mem = malloc(size)))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
