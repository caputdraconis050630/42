/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:29:15 by guntkim           #+#    #+#             */
/*   Updated: 2022/03/21 18:11:52 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dstaddr;
	unsigned char	*srcaddr;
	size_t			i;

	if (dst == src)
		return (dst);
	dstaddr = (unsigned char *)dst;
	srcaddr = (unsigned char *)src;
	i = 0;
	if (dstaddr <= srcaddr)
		ft_memcpy(dst, src, len);
	else
	{
		if (len == 0)
			return (dst);
		while (len--)
			dstaddr[len] = srcaddr[len];
	}
	return (dst);
}
