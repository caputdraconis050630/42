/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:41:02 by guntkim           #+#    #+#             */
/*   Updated: 2022/03/17 14:06:15 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1addr;
	unsigned char	*s2addr;
	size_t			i;

	if (n == 0)
		return (0);
	s1addr = (unsigned char *)s1;
	s2addr = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1addr[i] != s2addr[i])
			return (s1addr[i] - s2addr[i]);
		i += 1;
	}
	return (0);
}
