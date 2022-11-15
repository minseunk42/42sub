CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
HEADER = includes
SRCS = srcs/dp1.c srcs/dp2.c srcs/main.c srcs/setmap.c srcs/setmap2.c srcs/validate.c srcs/sub.c
OBJS = ${SRCS:.c=.o}
NAME = bsq 
RM = rm -f

all : $(NAME)
	
$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -I $(HEADER) -o $@ $^

.c.o :
	@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY: all fclean clean re
