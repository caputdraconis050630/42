/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:41:25 by guntakkim         #+#    #+#             */
/*   Updated: 2022/03/25 18:41:25 by guntakkim        ###   ########.fr       */
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

# ifndef TRUE
#   define TRUE 1
# endif

# ifndef FALSE
#   define FALSE 0
# endif

typedef struct s_staticVar
{
    char     *store;
    size_t   index;
} t_staticVar;

// get_next_line.c Functions
char    *get_next_line(int fd);

// get_next_line_utils.c Functions
size_t  ft_strlen(char *s);
void    ft_strlcat(char *s1, char *s2);

#endif