/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrankly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:50:21 by jfrankly          #+#    #+#             */
/*   Updated: 2019/02/08 19:43:25 by balvyn-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft2_wl(char const *s, char c)
{
	size_t	n;

	n = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		n++;
		s++;
	}
	return (n);
}

static	char	*ft2_s(const char *s, char c)
{
	size_t	j;
	size_t	i;
	char	*new;

	i = 0;
	j = 0;
	if (!(new = (char *)malloc((sizeof(char)) * (ft2_wl(s, c) + 1))))
		return (NULL);
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		new[j++] = s[i++];
	}
	new[j] = '\0';
	return (new);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**new;
	int		words;

	if (s && c)
		words = ft_wordsnb(s, c);
	if (!s || !(new = (char **)malloc((sizeof(char *)) * (words + 1))))
		return (NULL);
	i = 0;
	while (i < words && *s)
	{
		if (!(new[i] = ft2_s(s, c)))
		{
			ft_arrclr(new);
			return (NULL);
		}
		while (*s == c)
			s++;
		s += ft2_wl(s, c);
		i++;
	}
	new[i] = 0;
	return (new);
}
