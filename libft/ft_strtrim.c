/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrankly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:49:16 by jfrankly          #+#    #+#             */
/*   Updated: 2018/12/02 19:18:06 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft2_w(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		l;
	char	*new;

	if (s == NULL)
		return (NULL);
	l = ft_strlen(s);
	while (ft2_w(s[l - 1]))
		l--;
	if (l <= 0)
		l = 0;
	i = -1;
	while (ft2_w(s[++i]) && l != 0)
		l--;
	if (!(new = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	s += i;
	i = -1;
	while (++i < l)
		new[i] = *s++;
	new[i] = '\0';
	return (new);
}
