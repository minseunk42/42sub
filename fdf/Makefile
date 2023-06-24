NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFT = ./libft/libft.a
LIBFT_DIR = libft/
GNL = ./gnl/libftgnl.a
GNL_DIR = gnl/
HEADER = includes
SRCS = srcs/main.c srcs/map.c srcs/draw.c
OBJS = $(SRCS:.c=.o)
MLX = -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGl -framework AppKit

all :
	make $(NAME)

clean :
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean
	$(RM) $(NAME)

re :
	make fclean
	make all

$(NAME) : $(LIBFT) $(GNL) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -I $(HEADER) -L $(LIBFT_DIR) -lft -L $(GNL_DIR) -lftgnl -o $@

$(LIBFT) :
	make -C $(LIBFT_DIR) all

$(GNL) :
	make -C $(GNL_DIR) all

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY : all clean fclean re bonus
