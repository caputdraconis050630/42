/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntakkim <guntkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:41:33 by guntakkim         #+#    #+#             */
/*   Updated: 2022/03/25 18:41:33 by guntakkim        ###   ########.fr       */
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

void    ft_strlcat(char *s1, char *s2)
{
    size_t  s1_len;
    size_t  i;

    s1_len = ft_strlen(s1);
    i = 0;
    while (s2[i])
    {
        s1[s1_len + i] = s2[i];
        i += 1;
    }
    s1[s1_len + i] = '\0';
}

char    *ft_strdup(char *s, size_t len)
{
    char    *ret;
    size_t  i;

    i = 0;
    ret = (char *)malloc(sizeof(char) * (len + 1));
    if (!ret)
        return (NULL);
    while (i < len)
    {
        ret[i] = s[i];
        i += 1;
    }
    ret [len] = '\0';
}