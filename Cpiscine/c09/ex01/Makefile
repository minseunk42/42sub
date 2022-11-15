CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = includes
SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
OBJS = ${SRCS:.c=.o}
TARGET = libft.a
RM = rm -f
AR = ar rsc

all : $(TARGET)
	
$(TARGET) : $(OBJS)
	$(AR) $@ $^

.c.o :
	$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(TARGET)

re : fclean all

.PHONY: all fclean clean re
