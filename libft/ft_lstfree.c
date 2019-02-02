/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrankly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:59:26 by jfrankly          #+#    #+#             */
/*   Updated: 2018/12/03 15:13:23 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list *alst)
{
	t_list	*tmp;

	tmp = alst;
	while (tmp)
	{
		alst = tmp;
		tmp = tmp->next;
		free(alst->content);
		free(alst);
	}
}
