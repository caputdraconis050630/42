# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 11:49:26 by guntkim           #+#    #+#              #
#    Updated: 2022/03/22 18:14:58 by guntkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

AR			=	ar
ARFLAGS		=	-rc

RM			=	rm -f

SRCS		=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c\
				ft_memset.c	ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c\
				ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c\
				ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c\
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
				ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCS_BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS		=	$(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

NAME		=	libft.a

ifdef BONUS_FLAG
	OBJS_FILES = $(OBJS) $(OBJS_BONUS)
else
	OBJS_FILES = $(OBJS)
endif

all:			$(NAME)

$(NAME):		${OBJS_FILES}
				$(AR) $(ARFLAGS) $@ $^

%.o: 			%.c
				${CC} ${CFLAGS} -c $< -o $@

clean:
				$(RM) $(OBJS) $(OBJS_BONUS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

bonus:
				@make BONUS_FLAG=1 all

.PHONY:			all clean fclean re bonus
