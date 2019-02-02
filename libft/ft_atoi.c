/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrankly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:06:26 by jfrankly          #+#    #+#             */
/*   Updated: 2018/12/04 15:51:54 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_atoi(char *nb)
{
	long long int	res;
	char			negative;

	negative = 0;
	res = 0;
	while (*nb == '\n' || *nb == '\t' || *nb == '\r' || *nb == '\f'
			|| *nb == ' ' || *nb == '\v')
		nb++;
	if (*nb == '-')
		negative = 1;
	if (*nb == '-' || *nb == '+')
		nb++;
	while (*nb != '\n' && *nb != '\t' && *nb != '\r' && *nb != '\f'
			&& *nb != ' ' && *nb != '\v' && (*nb >= '0' && *nb <= '9'))
	{
		res = res * 10 + (*nb - '0');
		if (res < 0 && negative == 1)
			return (0);
		else if (res < 0)
			return (-1);
		nb++;
	}
	if (negative)
		return (-res);
	return (res);
}
