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

int	is_there_nl(char *s)
{
	int	i;

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

char	*get_ret_line(char *store)
{
	int		nl_index;
	size_t	len;
	char	*dst;
	char	*tmp;

	nl_index = is_there_nl(store);
	len = 0;
	while (store[len])
		len += 1;
	dst = ft_strndup(store, nl_index);
	tmp = ft_strndup(&store[nl_index + 1], len);
	if (!dst || !tmp)
		return (NULL);
	free_str(store);
	store = tmp;
	return (dst);
}

void	mid_process(char *buffer, char **store, int fd, size_t read_size)
{
	char	*tmp;

	if (store[fd] == NULL)
		tmp = ft_strndup(buffer, read_size);
	else
		tmp = ft_strjoin(store, buffer);
	free_str(store[fd]);
	store[fd] = tmp;
}

char	*get_next_line(int fd)
{
	static char	*store[OPEN_MAX];
	char		*buffer;
	int			index;
	size_t		read_size;

	if (fd > OPEN_MAX || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer) // Null Guard
		return (NULL);
	index = is_there_nl(store[fd]);
	read_size = read(fd, buffer, BUFFER_SIZE);
	while (index == -1 && read_size > 0)
	{
		buffer[read_size] = '\0';
		mid_process(buffer, store, fd, read_size);
		index = is_there_nl(store[fd]);
		read_size = read(fd, buffer, BUFFER_SIZE);
	}
	free_str(buffer);
	if (read_size < 0)
		return (NULL);
	return (get_ret_line(store[fd]));
}
