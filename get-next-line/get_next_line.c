/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:52:00 by guntkim           #+#    #+#             */
/*   Updated: 2022/04/01 20:45:36 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "get_next_line.h"

void	free_str(char *str)
{
	free(str);
	str = NULL;
}

char	*process_store(t_store *now, char *buf, ssize_t read_size)
{
	char	*str;
	ssize_t	len;

	while (buf[len])
		len += 1;
	if (!(now->store))
	{
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (!str)
			return (NULL);
		now->store = str;
	}
	else
	{
		str = ft_strjoin(now->store, buf);
		if (!str)
			return (NULL);
		free_str(now->store);
		now->store = str;
	}
	return (now->store);
}

char	*get_ret(t_store *now)
{
	ssize_t	idx;
	ssize_t	len;
	char	*dst;
	char	*store;

	while (now->store[len])
		len += 1;
	idx = is_there_nl(now->store);
	if (idx == FT_FAIL)
		return (now->store);
	dst = ft_strndup(now->store, idx);
	store = ft_strndup(&(now->store[idx + 1]), len - idx);
	if (!dst || !store)
		return (NULL);
	free_str(now->store);
	now->store = store;
	return (dst);
}

char	*get_read(int fd, t_store *now, char *buf)
{	
	ssize_t	read_size;
	char	*dst;

	read_size = 1;
	while (is_there_nl(now->store) == FT_FAIL && read_size > 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		buf[read_size] = '\0';
		if (!process_store(now, buf, read_size))
			return (NULL);
		if (read_size <= 0)
			break;
	}
	free_str(buf);
	if (read_size < 0) // read Error
		return (NULL);
	dst = get_ret(now);
	if (!dst)
		return (NULL);
	return (dst);
}

char	*get_next_line(int fd)
{
	static t_store	*head;
	t_store			*now;
	char			*buf;
	char			*dst;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	now = get_t_store(fd, head);
	if (!now)
		return (NULL);
	dst = get_read(fd, now, buf);
	if (!dst)
		return (NULL);
	free_str(buf);
	return (dst);
}