/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrankly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 11:07:12 by jfrankly          #+#    #+#             */
/*   Updated: 2018/12/02 14:45:30 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cn(int n)
{
	int		i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char		*str;
	int			l;
	int			neg;
	long	int	nb;

	nb = (long)n;
	neg = 0;
	if (nb < 0)
	{
		neg++;
		nb *= -1;
	}
	l = ft_cn(nb);
	if (!(str = (char *)malloc(sizeof(char) * l + neg + 1)))
		return (NULL);
	str[l + neg] = '\0';
	while (l || (neg && l > 0))
	{
		str[--l + neg] = nb % 10 + '0';
		nb /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
