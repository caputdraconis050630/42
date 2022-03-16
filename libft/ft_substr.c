/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:56:40 by guntkim           #+#    #+#             */
/*   Updated: 2022/03/16 16:42:19 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	srclen;
	size_t	mallocsize;

	i = 0;
	srclen = ft_strlen(s);
	if (!s)
		return (0);
	if (srclen <= start)
		mallocsize = 1;
	else if (srclen - start > len)
		mallocsize = len + 1;
	else
		mallocsize = srclen - start + 1;
	dst = (char *)malloc(sizeof(char) * mallocsize);
	if (!dst)
		return (0);
	while (i + 1 < mallocsize)
	{
		dst[i] = s[start + i];
		i += 1;
	}
	dst[i] = '\0';
	return (dst);
}
