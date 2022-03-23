/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:19:11 by guntkim           #+#    #+#             */
/*   Updated: 2022/03/20 14:06:33 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		cnt;
	t_list	*tmp;

	cnt = 0;
	if (!lst)
		return (0);
	tmp = lst;
	while (tmp)
	{
		cnt += 1;
		tmp = tmp->next;
		if (!tmp)
			break ;
	}
	return (cnt);
}
