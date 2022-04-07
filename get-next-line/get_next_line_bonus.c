/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntakkim <guntakkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 23:54:20 by guntkim           #+#    #+#             */
/*   Updated: 2022/04/07 12:12:44 by guntakkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_read(int fd, char **store)
{
	char	*buf;
	char	*tmp;
	char	*dst;
	ssize_t	read_size;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	dst = *store;
	while ((dst == NULL || !ft_strchr(dst, '\n')) && buf != NULL)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		tmp = dst;
		dst = append_store(dst, buf, read_size);
		free(tmp);
	}
	free(buf);
	buf = NULL;
	if (read_size < 0 || dst == NULL || *dst == '\0')
	{
		free(dst);
		dst = NULL;
	}
	return (dst);
}

char	*get_ret(char const *store)
{
	char	*dst;
	size_t	len;

	if (ft_strchr(store, '\n'))
		len = ft_strchr(store, '\n') - store + 1;
	else
		len = ft_strchr(store, '\0') - store;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, store, len + 1);
	return (dst);
}

char	*process_store(char **store, ssize_t len)
{
	char	*dst;

	if (len == FT_FAIL)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(*store) - len + 1));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, (*store) + len, ft_strlen(*store) - len + 1);
	free(*store);
	*store = NULL;
	return (dst);
}

char	*append_store(char const *store, char *buf, ssize_t read_size)
{
	char	*dst;
	size_t	len;

	if (buf == NULL)
		return (NULL);
	buf[read_size] = '\0';
	if (store == NULL)
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

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	now = get_t_store(fd, &head);
	if (now == NULL)
		return (NULL);
	now->store = get_read(fd, &(now->store));
	if (now->store == NULL)
	{
		free_node(&now);
		return (NULL);
	}
	dst = get_ret(now->store);
	now->store = process_store(&(now->store), ft_strlen(dst));
	if (dst == NULL || now->store == NULL)
	{
		free_node(&now);
		return (NULL);
	}
	return (dst);
}
