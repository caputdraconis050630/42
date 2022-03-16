/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:26:20 by guntkim           #+#    #+#             */
/*   Updated: 2022/03/16 17:51:22 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dstaddr;
	unsigned char	*srcaddr;

	dstaddr = (unsigned char *)dst;
	srcaddr = (unsigned char *)src;
	if (!dst || !src)
		return (0);
	if (n == 0)
		return (dst);
	while (n--)
		*dstaddr++ = *srcaddr++;
	return (dst);
}
