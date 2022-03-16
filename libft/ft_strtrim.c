/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:56:36 by guntkim           #+#    #+#             */
/*   Updated: 2022/03/16 17:08:20 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	size_t	front;
	size_t	rear;

	if (!s1)
		return (0);
	if (!set)
		return ((char *)s1);
	front = 0;
	rear = ft_strlen(s1);
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	while (s1[rear - 1] && ft_strchr(set, s1[rear - 1]) && rear > front)
		rear--;
	dst = (char *)malloc(sizeof(char) * (rear - front + 1));
	if (dst)
		ft_strlcpy(dst, &s1[front], rear - front + 1);
	return (dst);
}
