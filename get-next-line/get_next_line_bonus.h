/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntakkim <guntakkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:52:02 by guntkim           #+#    #+#             */
/*   Updated: 2022/04/07 11:31:42 by guntakkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
	struct s_store	*prev;
	struct s_store	*next;
}	t_store;

// get_next_line.c Prototype
char	*get_read(int fd, char **store);
char	*get_ret(char const *store);
char	*process_store(char **store, ssize_t len);
char	*get_next_line(int fd);
char	*append_store(char const *store, char const *buf);

// get_next_line_utils.c Prototype
size_t	ft_strlen(char const *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	free_node(t_store **now);
t_store	*get_t_store(int fd, t_store *head);

#endif