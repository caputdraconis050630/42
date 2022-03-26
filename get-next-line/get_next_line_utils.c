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

size_t  ft_strlen(char *s)
{
    size_t  len;

    len = 0;
    while (s[len])
        len += 1;
    return (len);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *dst;
    size_t  s1_len;
    size_t  s2_len;
    size_t  i;

    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    dst = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
    if (!dst)
        return (NULL);
    ft_memcpy(dst, s1, s1_len);
    ft_memcpy(dst + s1_len, s2, s2_len);
    dst[s1_len + s2_len] = '\0';
    return (dst);
}

char    *ft_strndup(char *s, size_t len)
{
    char    *dst;
    size_t  i;
    size_t  s_len;

    i = 0;
    s_len = ft_strlen(s);
    if (s_len < len)
        dst = (char *)malloc(sizeof(char) * (s_len + 1));
    else
        dst = (char *)malloc(sizeof(char) * (len + 1));
    if (!dst)
        return (NULL);
    while (s[i] && i < len)
    {
        dst[i] = s[i];
        i += 1;
    }
    dst[i] = '\0';
    return (dst);
}

void    *ft_memcpy(void *dst, void *src, size_t size)
{
    unsigned char       *u_dst;
    unsigned const char *u_src;
    size_t              i;

    i = 0;
    u_dst = (unsigned char *)dst;
    u_src = (unsigned char *)src;
    while (i < size)
    {
        u_dst[i] = u_src[i];
        i += 1;
    }
    return (dst);
}