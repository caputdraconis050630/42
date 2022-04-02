/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntakkim <guntakkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:51:56 by guntkim           #+#    #+#             */
/*   Updated: 2022/04/02 14:11:37 by guntakkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_store	*get_t_store(int fd, t_store *head)
{
	if (!head)
	{
		head = ft_newlst(fd);
		if (!head)
			return (NULL);
		return (head);
	}
	while (head->next)
	{
		if (head->fd == fd)
			return (head);
		head = head->next;
	}
	if (head->fd == fd)
		return (head);
	head->next = ft_newlst(fd);
	if (!(head->next))
		return (NULL);
	return (head->next);
}

t_store	*ft_newlst(int fd)
{
	t_store	*tmp;

	tmp = (t_store *)malloc(sizeof(t_store));
	if (!tmp)
		return (NULL);
	tmp->next = NULL;
	tmp->fd = fd;
	tmp->store = NULL;
	return (tmp);
}

ssize_t	is_there_nl(char *store)
{
	ssize_t	idx;

	idx = 0;
	if (!store)
		return (FT_FAIL);
	while (*store)
	{
		if (*store == '\n')
			return (idx);
		store += 1;
		idx += 1;
	}
	return (FT_FAIL);
}

char	*ft_strndup(char *str, ssize_t len)
{
	ssize_t	s_len;
	ssize_t	i;
	char	*dst;

	s_len = 0;
	i = 0;
	if (len < 0)
		return (NULL);
	while (str[s_len])
		s_len += 1;
	if (s_len < len)
		dst = (char *)malloc(sizeof(char) * (s_len + 1));
	else
		dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (i < s_len && i < len)
	{
		dst[i] = str[i];
		i += 1;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	ssize_t	s1_len;
	ssize_t	s2_len;
	ssize_t	i;

	i = 0;
	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len])
		s1_len += 1;
	while (s2[s2_len])
		s2_len += 1;
	dst = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!dst)
		return (NULL);
	while (i < s1_len)
	{
		dst[i] = s1[i];
		i += 1;
	}
	while (i - s1_len < s2_len)
	{
		dst[i] = s2[i - s1_len];
		i += 1;
	}
	dst[s1_len + s2_len] = '\0';
	return (dst);
}
