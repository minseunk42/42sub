NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
PRINTF = ./ft_printf/libftprintf.a
PRINTF_DIR = ft_printf/
HEADER = includes
SRCS = srcs/main.c
OBJS = $(SRCS:.c=.o)
B_SRCS =
B_OBJS = $(B_SRCS:.c=.o)

ifdef BONUS
	F_OBJS = $(B_OBJS)
else
    F_OBJS = $(OBJS)
endif

all :
	make $(NAME)

clean :
	make -C $(PRINTF_DIR) clean
	$(RM) $(OBJS) $(B_OBJS)

fclean : clean
	make -C $(PRINTF_DIR) fclean
	$(RM) $(NAME)

re :
	make fclean
	make all

bonus :
	make BONUS=1 $(NAME)

$(NAME) : $(PRINTF) $(F_OBJS)
	$(CC) $(CFLAGS) $(F_OBJS) -I $(HEADER) -L $(PRINTF_DIR) -lftprintf -o $@ 

$(PRINTF) :
	make -C $(PRINTF_DIR) all

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY : all clean fclean re bonus
