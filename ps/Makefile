NAME = push_swap
BNAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
PRINTF = ./ft_printf/libftprintf.a
PRINTF_DIR = ft_printf/
GNL = ./gnl/libftgnl.a
GNL_DIR = gnl/
HEADER = includes
SRCS = srcs/ps_main.c srcs/hard.c srcs/algo.c srcs/opti.c srcs/argv_func.c srcs/utils.c srcs/stack_func.c srcs/stack_func2.c srcs/swap_func.c srcs/free.c srcs/push_func.c srcs/r_func.c srcs/rr_func.c 
OBJS = $(SRCS:.c=.o)
B_SRCS = srcs/ck_main.c srcs/argv_func.c srcs/utils.c srcs/stack_func.c srcs/stack_func2.c srcs/swap_func.c srcs/free.c srcs/push_func.c srcs/r_func.c srcs/rr_func.c
B_OBJS = $(B_SRCS:.c=.o)

ifdef WITH_BONUS
	TOTAL_OBJS = $(OBJS) $(B_OBJS)
else
	TOTAL_OBJS = $(OBJS)
endif

all :
	make $(NAME)

clean :
	make -C $(PRINTF_DIR) clean
	make -C $(GNL_DIR) clean
	$(RM) $(OBJS) $(B_OBJS)

fclean : clean
	make -C $(PRINTF_DIR) fclean
	make -C $(GNL_DIR) fclean
	$(RM) $(NAME)
	$(RM) $(BNAME)

re :
	make fclean
	make all

bonus :
	make WITH_BONUS=1 $(BNAME)

$(NAME) : $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(HEADER) -L $(PRINTF_DIR) -lftprintf -o $@ 

$(BNAME) : $(PRINTF) $(GNL) $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) -I $(HEADER) -L $(GNL_DIR) -lftgnl -L $(PRINTF_DIR) -lftprintf -o $@

$(PRINTF) :
	make -C $(PRINTF_DIR) all

$(GNL) :
	make -C $(GNL_DIR) all

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY : all clean fclean re bonus
