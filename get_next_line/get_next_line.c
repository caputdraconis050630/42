/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:54:12 by guntkim           #+#    #+#             */
/*   Updated: 2022/03/23 13:46:17 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*store;
	char		*dst;

	dst = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!dst || fd < 0)
		return (0);
	read(fd, dst, BUFFER_SIZE);
	return (dst);
}
