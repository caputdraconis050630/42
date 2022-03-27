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

#include "get_next_line.h"

static size_t	is_there_nl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (FAIL);
	while (s[i] != NULL)
	{
		if (s[i] == '\n')
			return (i);
		i += 1;
	}
	return (FAIL);
}

static char	*get_ret_line(char *store)
{
	size_t	nl_index;
	size_t	len;
	char	*dst;
	char	*tmp;

	nl_index = is_there_nl(store);
	while (store[len] != NULL)
		len += 1;
	dst = ft_strndup(store, nl_index);
	tmp = ft_strndup(&store[nl_index + 1], len);
	if (!dst || !tmp)
		return (FAIL);
	free_str(store);
	store = tmp;
	return (dst);
}

static void	mid_process(char *buffer, char *store, size_t read_size)
{
	char	*tmp;

	if (store == NULL)
		tmp = ft_strndup(buffer, read_size);
	else
		tmp = ft_strjoin(store, buffer);
	free_str(store);
	store = tmp;
}

char	*get_next_line(int fd)
{
	static char	*store[OPEN_MAX];
	char		*buffer;
	size_t		index;
	size_t		read_size;

	if (fd > OPEN_MAX || fd < 0 || BUFFER_SIZE <= 0)
		return (FAIL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (FAIL);
	index = is_there_nl(store[fd]);
	read_size = read(fd, buffer, BUFFER_SIZE);
	while (index == FAIL && read_size > 0)
	{
		buffer[read_size] = '\0';
		mid_process(buffer, store[fd], read_size);
		index = is_there_nl(store[fd]);
		read_size = read(fd, buffer, BUFFER_SIZE);
	}
	free_str(buffer);
	if (read_size < 0)
		return (FAIL);
	return (get_ret_line(store[fd]));
}
