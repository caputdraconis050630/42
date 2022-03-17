/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:40:11 by guntkim           #+#    #+#             */
/*   Updated: 2022/03/16 14:56:53 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	size_t			i;
	unsigned char	*saddr;
    unsigned char   uc;

	i = 0;
    uc = (unsigned char)c;
	saddr = (unsigned char *)s;
	while (i < len)
	{
		if (saddr[i] == uc)
			return ((void *)&saddr[i]);
		i += 1;
	}
	return (0);
}
