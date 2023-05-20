NAME = push_swap
BNAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
PRINTF = ./ft_printf/libftprintf.a
PRINTF_DIR = ft_printf/
HEADER = includes
SRCS = srcs/ps_main.c srcs/utils.c srcs/stack_func.c srcs/swap_func.c srcs/free.c srcs/push_func.c srcs/r_func.c srcs/rr_func.c 
OBJS = $(SRCS:.c=.o)
B_SRCS = srcs/ck_main.c srcs/utils.c srcs/stack_func.c srcs/swap_func.c srcs/free.c srcs/push_func.c srcs/r_func.c srcs/rr_func.c
B_OBJS = $(B_SRCS:.c=.o)

all :
	make $(NAME)

clean :
	make -C $(PRINTF_DIR) clean
	$(RM) $(OBJS) $(B_OBJS)

fclean : clean
	make -C $(PRINTF_DIR) fclean
	$(RM) $(NAME)
	$(RM) $(BNAME)

re :
	make fclean
	make all

bonus :
	make $(BNAME)

$(NAME) : $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(HEADER) -L $(PRINTF_DIR) -lftprintf -o $@ 

$(BNAME) : $(PRINTF) $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) -I $(HEADER) -L $(PRINTF_DIR) -lftprintf -o $@

$(PRINTF) :
	make -C $(PRINTF_DIR) all

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY : all clean fclean re bonus
