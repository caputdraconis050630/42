/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntakkim <guntkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:41:33 by guntkim         #+#    #+#             */
/*   Updated: 2022/03/25 18:41:33 by guntkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen(const char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

void	free_str(char *str)
{
	free(str);
	str = NULL;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	ssize_t	s1_len;
	ssize_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!dst)
		return (NULL);
	ft_memcpy(dst, (void *)s1, s1_len);
	ft_memcpy(dst + s1_len, (void *)s2, s2_len);
	dst[s1_len + s2_len] = '\0';
	return (dst);
}

char	*ft_strndup(char *s, ssize_t len)
{
	char	*dst;
	ssize_t	i;

	i = 0;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = s[i];
		i += 1;
	}
	dst[i] = '\0';
	return (dst);
}

void	*ft_memcpy(void *dst, void *src, ssize_t size)
{
	unsigned char		*u_dst;
	const unsigned char	*u_src;
	ssize_t				i;

	i = 0;
	u_dst = (unsigned char *)dst;
	u_src = (const unsigned char *)src;
	while (i < size)
	{
		u_dst[i] = u_src[i];
		i += 1;
	}
	return (dst);
}
