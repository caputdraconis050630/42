/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:40:11 by guntkim           #+#    #+#             */
/*   Updated: 2022/03/15 18:31:46 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	size_t			i;
	unsigned char	*saddr;

	i = 0;
	saddr = (unsigned char *)s;
	while (saddr[i] && i < len)
	{
		if (saddr[i] == (unsigned char)c)
			return ((void *)&saddr[i]);
		i += 1;
	}
	if (saddr[i] == (unsigned char)c)
		return ((void *)&saddr[i]);
	return (0);
}
