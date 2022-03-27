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
	static char	*save[OPEN_MAX];
	char		*buffer;
	char		*tmp;

	if (fd > OPEN_MAX || fd < 0 || BUFFER_SIZE <= 0)
		return (FAIL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (FAIL);

	free_str(buffer);
	return (get_ret_line());
}
