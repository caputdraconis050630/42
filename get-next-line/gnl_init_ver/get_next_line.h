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
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	int		fd;
	char	*store;
	t_list	*next;
}	t_list;

ssize_t	is_there_nl(char *s);
char	*get_ret_line(char *store);
char	*mid_process(char *buffer, char *store, ssize_t read_size);
char	*get_next_line(int fd);
char	*process_store(char *store);
void	free_str(char *str);
ssize_t	ft_strlen(const char *str);
char	*ft_strndup(char *s, ssize_t len);
void	*ft_memcpy(void *dst, void *src, ssize_t size);
char	*ft_strjoin(char const *s1, char const *s2);

#endif