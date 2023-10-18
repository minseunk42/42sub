NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = -I./header
RM = rm -rf
SRCS = srcs/main.c srcs/raycast.c srcs/move.c srcs/util.c srcs/turn.c srcs/event_util.c srcs/draw_util.c
OBJS = $(SRCS:.c=.o)
MLX = -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGl -framework AppKit

all :
	make $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

$(NAME) : $(LIBFT) $(GNL) $(OBJS)
	$(CC) $(CFLAGS) $(HEADER) $(OBJS) $(MLX) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY : all clean fclean re bonus
