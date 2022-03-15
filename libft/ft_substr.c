/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:56:40 by guntkim           #+#    #+#             */
/*   Updated: 2022/03/15 18:36:43 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	int		i;
	int		srclen;
	int		mallocsize;

	i = 0;
	srclen = ft_strlen(s);
	mallocsize = srclen - start + 1;
	dst = (char *)malloc(sizeof(char) * mallocsize);
	if (!dst || mallocsize <= 1)
		return (0);
	while (s[start + i] && i < len)
	{
		dst[i] = s[start + i];
		i += 1;
	}
	dst[i] = '\0';
	return (dst);
}
