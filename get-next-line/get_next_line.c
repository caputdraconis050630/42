/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntakkim <guntakkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:52:00 by guntkim           #+#    #+#             */
/*   Updated: 2022/04/05 05:51:31 by guntakkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "get_next_line.h"

ssize_t	ft_strlen(char *str)
{
	ssize_t	len;

	len = 0;
	if (!str)
		return (FT_FAIL);
	while (str[len])
		len += 1;
	return (len);
}

char	*process_store(t_store *now, char *buf)
{
	char	*str;
	
	str = ft_strjoin(now->store, buf);
	if (!str)
		return (NULL);
	free(now->store);
	now->store = str;
	return (now->store);
}

char	*get_ret(t_store *now)
{
	ssize_t	idx;
	ssize_t	len;
	char	*dst;
	char	*store;

	len = ft_strlen(now->store);
	idx = is_there_nl(now->store);
	// printf("기존 store %s\n", now->store);
	if (idx == FT_FAIL)
	{
		dst = ft_strndup(now->store, len);
		store = ft_strndup("", 0);
	}
	else
	{
		dst = ft_strndup(now->store, idx);
		store = ft_strndup(&(now->store[idx]), len - idx);
	}
	if (!dst || !store)
		return (NULL);
	free(now->store);
	now->store = store;
	// printf("dst의 길이 %d dst %s\n", (int)ft_strlen(dst), dst);
	// printf("자르고 난 후의 store %s\n", now->store);
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
		if (!process_store(now, buf))
			return (NULL);
		if (read_size <= 0)
			break ;
	}
	free(buf);
	buf = NULL;
	if (read_size < 0) // read Error
		return (NULL);
	dst = get_ret(now);
	if (!dst)
		return (NULL);
	return (dst);
}

char	*get_next_line(int fd)
{
	static t_store	head;
	t_store			*now;
	char			*buf;
	char			*dst;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	now = get_t_store(fd, &head);
	if (!now)
		return (NULL);
	dst = get_read(fd, now, buf);
	free(now);
	if (!dst)
		return (NULL);
	return (dst);
}