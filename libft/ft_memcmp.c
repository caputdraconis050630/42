/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:41:02 by guntkim           #+#    #+#             */
/*   Updated: 2022/03/15 18:38:16 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1addr;
	unsigned char	*s2addr;
	int				i;

	s1addr = (unsigned char *)s1;
	s2addr = (unsigned char *)s2;
	i = 0;
	while (s1addr[i] && s2addr[i] && s1addr[i] == s2addr[i] && i < n)
		i += 1;
	if (i == n)
		return (0);
	return ((unsigned char)s1addr[i] - (unsigned char)s2addr[i]);
}
