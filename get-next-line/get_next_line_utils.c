/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:51:56 by guntkim           #+#    #+#             */
/*   Updated: 2022/04/05 05:46:54 by guntakkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_store	*get_t_store(int fd, t_store *head)
{
	t_store	*now;

	now = head;
	while (now->next)
	{
		if (now->fd == fd)
			return (now);
		now = now->next;
	}
	now->next = (t_store *)malloc(sizeof(t_store));
	now->next->fd = fd;
	now->next->prev = now;
	now->next->next = NULL;
	now->next->store = NULL;
	return (now->next);
}

void	free_node(t_store **now)
{
	if ((*now)->store)
		free((*now)->store);
	(*now)->prev->next = (*now)->next;
	if ((*now)->next != NULL)
		(*now)->next->prev = (*now)->prev;
	free(*now);
	*now = NULL;
}

size_t	ft_strlen(char const *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	index;

	index = 0;
	if (s == NULL)
		return (NULL);
	while (s[index])
	{
		if (s[index] == (unsigned char)c)
			return ((char *)&s[index]);
		index += 1;
	}
	if (s[index] == (unsigned char)c)
		return ((char *)&s[index]);
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i += 1;
	}
	dst[i] = '\0';
	return (src_len);
}