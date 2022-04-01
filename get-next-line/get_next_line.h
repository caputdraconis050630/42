/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:52:02 by guntkim           #+#    #+#             */
/*   Updated: 2022/04/01 21:27:47 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (42)
# endif

# ifndef FT_FAIL
#  define FT_FAIL (-1)
# endif

typedef struct s_store
{
	int				fd;
	char			*store;
	struct s_store	*next;
}	t_store;

// Prototype - get_next_line.c
void		free_str(char *str);
char		*process_store(t_store *now, char *buf, ssize_t read_size);
char		*get_ret(t_store *now);
char		*get_read(int fd, t_store *now, char *buf);
char		*get_next_line(int fd);

// Prototype - get_next_line_utils.c
t_store		*get_t_store(int fd, t_store *head);
t_store		*ft_newlst(int fd);
ssize_t		is_there_nl(char *store);
char		*ft_strndup(char *str, ssize_t len);
char		*ft_strjoin(char *s1, char *s2);
#endif