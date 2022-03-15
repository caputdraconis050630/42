/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:55:47 by guntkim           #+#    #+#             */
/*   Updated: 2022/03/15 18:20:00 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*dest;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	dst = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!dst)
		return (0);
	while (i < s1_len)
	{
		dst[i] = s1_len[i];
		i += 1;
	}
	while (i < s1_len + s2_len)
	{
		dst[i] = s2_len[i - s1_len];
		i += 1;
	}
	dst[i] = '\0';
	return (dst);
}
