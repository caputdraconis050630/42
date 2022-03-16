# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 13:12:37 by guntkim           #+#    #+#              #
#    Updated: 2022/02/17 13:12:41 by guntkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -c

NAME	= libft.a

SRCDIR	= srcs
INCDIR	= includes

SRCS	= ${SRCDIR}/ft_putchar.c ${SRCDIR}/ft_swap.c ${SRCDIR}/ft_putstr.c ${SRCDIR}/ft_strlen.c ${SRCDIR}/ft_strcmp.c
OBJS	= ${SRCS:.c=.o}

RM		= rm -f

all:		${NAME}

%.o: %.c
			${CC} ${CFLAGS} $< -o $@ -I ${INCDIR}

${NAME}:	${OBJS}
			ar -rc $@ ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
