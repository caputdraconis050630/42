/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntakkim <guntakkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:17:13 by guntakkim         #+#    #+#             */
/*   Updated: 2022/04/07 11:17:37 by guntakkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_store	*get_t_store(int fd, t_store *head)
{
	t_store	*now;

	now = head;
	while (now->next)
	{
		now = now->next;
		if (now->fd == fd)
			return (now);
	}
	now->next = (t_store *)malloc(sizeof(t_store));
	if (now->next == NULL)
		return (NULL);
	now->next->fd = fd;
	now->next->prev = now;
	now->next->next = NULL;
	now->next->store = NULL;
	return (now->next);
}

void	free_node(t_store **now)
{
	free((*now)->store);
	if ((*now)->next != NULL)
		(*now)->next->prev = (*now)->prev;
	(*now)->prev->next = (*now)->next;
	free(*now);
	*now = NULL;
}

size_t	ft_strlen(char const *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len += 1;
		s += 1;
	}
	return (len);
}

char	*ft_strchr(char const *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		else
			s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}

size_t	ft_strlcpy(char *dst, char const *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize)
		dst[i] = '\0';
	return (ft_strlen(src));
}
