CC = gcc
CFLAGS = -c -Wall -Wextra -Werror

AR = ar
ARFLAGS = -rc

NAME = libft.a

SRCS = first.c\
	   second.c\
	   third.c

OBJS = first.o\
	   second.o\
	   third.o

%.o : %.c
	$(CC) $(CFLAGS) -c $(SRCS)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $<
