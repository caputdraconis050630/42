/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:28:01 by guntkim         #+#    #+#             */
/*   Updated: 2022/03/25 20:28:01 by guntkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test", O_RDONLY);
	while ((line = get_next_line(fd)) != 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	close(fd);
	return (0);
}