/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:18:01 by guntkim           #+#    #+#             */
/*   Updated: 2022/03/20 15:53:50 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dst;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (0);
	dst = ft_lstnew(f(lst->content));
	if (!dst)
		return (0);
	tmp = dst;
	lst = lst->next;
	while (lst)
	{
		tmp->next = (t_list *)malloc(sizeof(t_list));
		if (!(tmp->next))
		{
			ft_lstclear(&dst, del);
			return (0);
		}
		tmp->next->content = f(lst->content);
		tmp->next->next = 0;
		lst = lst->next;
		tmp = tmp->next;
	}
	return (dst);
}
