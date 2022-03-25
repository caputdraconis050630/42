CC = gcc
CFLAGS = -c -Wall -Wextra -Werror

SRCS = first.c\
	   second.c\
	   third.c

OBJS = $(SRCS:.c=.o)

AR = ar
ARFLAGS = -rc
NAME = libft.a
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

%.o : $.c
	$(CC) $(CFLAGS) -c $<
