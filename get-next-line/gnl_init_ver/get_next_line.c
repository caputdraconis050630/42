/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:41:03 by guntkim         #+#    #+#             */
/*   Updated: 2022/03/25 18:41:03 by guntkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

ssize_t	is_there_nl(char *s)
{
	ssize_t	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i += 1;
	}
	return (-1);
}

char	*process_store(char *store)
{
	char	*tmp;
	ssize_t	len;
	ssize_t	index;

	index = is_there_nl(store);
	len = ft_strlen(store);
	tmp = ft_strndup(&store[index + 1], len - index + 1);
	free_str(store);
	return (tmp);
}

char	*get_ret_line(char *store)
{
	ssize_t	index;
	char	*dst;

	index = is_there_nl(store);
	if (index == -1)
		dst = ft_strndup(store, ft_strlen(store));
	else
		dst = ft_strndup(store, index);
	if (!dst)
		return (NULL);
	return (dst);
}

char	*mid_process(char *buffer, char *store, ssize_t read_size)
{
	char	*tmp;

	// if (!store)
	// 	store = ft_strndup("", 0);
	if (store == (char *)NULL)
		tmp = ft_strndup(buffer, read_size);
	else
	{
		tmp = ft_strjoin(store, buffer);
		free_str(store);
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*buffer;
	char		*dst;
	ssize_t		read_size; 

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_size = 1;
	while (is_there_nl(store) == -1 && read_size > 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size <= 0)
			break;
		buffer[read_size] = '\0';
		store = mid_process(buffer, store, read_size);
	}
	free_str(buffer);
	if (read_size < 0) // read Error
		return (NULL);
	dst = get_ret_line(store);
	store = process_store(store);
	return (dst);
}
