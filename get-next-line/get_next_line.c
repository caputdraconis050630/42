/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:41:03 by guntakkim         #+#    #+#             */
/*   Updated: 2022/03/25 18:41:03 by guntakkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static t_staticVar  staticVar;
    char                *ret;
    char                *buf;
    size_t              read_size;

    staticVar.index = 0;
    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    read_size = read(fd, buf, BUFFER_SIZE);
    if (read_size == -1) // Error
        return (0);
    buf[read_size] = '\0';
    ft_strlcat(staticVar.store, read);
    ret = get_ret_pointer(&(staticVar.store[staticVar.index]));
    // validate check ret
    return (ret);
}

char    *get_ret_pointer(char *s)
{
    size_t  len;
    char    *dst;

    len = 0;
    while (s[len] != '\0' && s[len] == '\n')
        len += 1;
    dst = ft_strdup(s, len);
    if (!dst)
        return (NULL);
    return (dst);
}