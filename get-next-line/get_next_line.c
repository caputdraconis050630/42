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

static void	free_str(char *str)
{
	free(str);
	str = NULL;
}

// if there is a \n, return '\n' index
// else, return FAIL
static size_t	is_there_nl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (FAIL);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i += 1;
	}
	return (FAIL);
}

char	*get_next_line(int fd)
{
	static char	*store[OPEN_MAX];
	char		*buffer;
	char		*tmp;
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
		if (store[fd] == NULL)
			tmp = ft_strndup(buffer, read_size);
		else
			tmp = ft_strjoin(store[fd], buffer);
		free_str(store[fd]);
		store[fd] = tmp;
		index = is_there_nl(store[fd]);
		read_size = read(fd, buffer, BUFFER_SIZE);
	}
	free_str(buffer);
	return (get_ret_line());
}
