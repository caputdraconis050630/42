/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:57:35 by guntakkim         #+#    #+#             */
/*   Updated: 2022/04/05 10:57:35 by guntakkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_read(int fd, t_store *now)
{
	char	*buf;
	char	*store;
	char	*tmp;
	ssize_t	read_size;

	store = now->store;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_size = 1;
	while (read_size > 0 && !ft_strchr(store, '\n'))
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0)
			break;
		buf[read_size] = '\0';
		tmp = store;
		store = append_store(store, buf);
		free(tmp);
	}
	free(buf);
	buf = NULL;
	return (store);
}

char	*get_ret(char *store)
{
	char	*dst;
	size_t	nl_index;
	
	if (ft_strchr(store, '\n'))
		nl_index = (ft_strchr(store, '\n') - store) + 1;
	else
		nl_index = ft_strchr(store, '\0') - store;
	dst = (char *)malloc(sizeof(char) * (nl_index + 1));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, store, nl_index + 1);
	return (dst);
}

char	*process_store(t_store *now, ssize_t len)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (ft_strlen(now->store) - len + 1));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, &now->store[len], ft_strlen(now->store) - len + 1);
	free(now->store);
	now->store = NULL;
	return (dst);
}

char	*append_store(char *store, char *buf)
{
	char	*dst;
	size_t	len;

	if (buf == NULL)
		return (NULL);
	else if (store == NULL)
	{
		dst = (char *)malloc(sizeof(char) * (ft_strlen(buf) + 1));
		if (dst == NULL)
			return (NULL);
		ft_strlcpy(dst, buf, ft_strlen(buf) + 1);
		return (dst);
	}
	len = ft_strlen(store) + ft_strlen(buf) + 1;
	dst = (char *)malloc(sizeof(char) * len);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, store, ft_strlen(store) + 1);
	ft_strlcpy(dst + ft_strlen(store), buf, ft_strlen(buf) + 1);
	return (dst);
}

char	*get_next_line(int fd)
{
	static t_store	head;
	t_store			*now;
	char			*dst;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	now = get_t_store(fd, &head);
	if (now == NULL)
		return (NULL);
	now->store = get_read(fd, now);
	// printf("now->store : %s\n", now->store);
	if (now->store == NULL)
	{
		free_node(&now);
		return (NULL);
	}
	dst = get_ret(now->store);
	now->store = process_store(now, ft_strlen(dst));
	if (dst == NULL || now->store == NULL)
	{
		free_node(&now);
		return (NULL);
	}
	return (dst);
}