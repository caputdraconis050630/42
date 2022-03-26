/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:41:25 by guntkim         #+#    #+#             */
/*   Updated: 2022/03/25 18:41:25 by guntkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h> // OPEN_MAX 사용

# ifndef BUFFER_SIZE
#   define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#   define OPEN_MAX 256
# endif

# define SUCCESS 1
# define FAIL -1
# define EOF 0

typedef struct s_staticVar
{
    char     *store;
    size_t   index;
} t_staticVar;

// get_next_line.c Functions
char    *get_next_line(int fd);
char    *get_ret_pointer(char *s);

// get_next_line_utils.c Functions
size_t  ft_strlen(char *s);
char    *ft_strdup(char *s, size_t len);
void    *ft_memcpy(void *dst, void *src, size_t size);
char    *ft_strjoin(char const *s1, char const *s2);

#endif