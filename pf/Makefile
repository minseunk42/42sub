NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar -rcs
LIBFT = ./libft/libft.a
LIBFT_DIR = libft/
SRCS = ft_printf.c ft_printf_utils.c ft_printf_utils2.c print_pct.c print_chr.c print_str.c print_int.c print_usi.c print_hex.c print_ptr.c set_format.c
OBJS = $(SRCS:.c=.o)
B_SRCS = ft_printf_bonus.c ft_printf_utils_bonus.c ft_printf_utils2_bonus.c print_pct_bonus.c print_chr_bonus.c print_str_bonus.c print_int_bonus.c print_usi_bonus.c print_hex_bonus.c print_ptr_bonus.c set_format_bonus.c
B_OBJS = $(B_SRCS:.c=.o)

ifdef BONUS
	F_OBJS = $(B_OBJS)
else
    F_OBJS = $(OBJS)
endif

all :
	make $(NAME)

clean :
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) $(B_OBJS)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re :
	make fclean
	make all

bonus :
	make BONUS=1 $(NAME)

$(NAME) : $(LIBFT) $(F_OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $@ $^

$(LIBFT) :
	make -C $(LIBFT_DIR) all

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY : all clean fclean re bonus