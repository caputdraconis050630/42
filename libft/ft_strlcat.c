/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:31:25 by guntkim           #+#    #+#             */
/*   Updated: 2022/03/15 18:26:52 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (srclen + dstsize);
	if (dstlen > dstsize)
		return (srclen + dstsize);
	while ((dstlen + i + 1) < dstsize && src[i] != '\0')
	{
		dst[dstlen + i] = src[i];
		i += 1;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
