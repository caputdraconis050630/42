/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:56:25 by guntkim           #+#    #+#             */
/*   Updated: 2022/03/16 17:38:02 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*dst;

	len = 0;
	i = 0;
	if (!s || !f)
		return (0);
	while (s[len])
		len += 1;
	dst = (char *)malloc(sizeof(char) * len + 1);
	if (!dst)
		return (0);
	while (i < len)
	{
		dst[i] = f(i, s[i]);
		i += 1;
	}
	dst[i] = '\0';
	return (dst);
}
