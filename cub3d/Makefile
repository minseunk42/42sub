NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = -I./header
RM = rm -rf
SRCS = srcs/main.c srcs/raycast.c srcs/move.c srcs/init.c srcs/turn.c srcs/event_util.c srcs/draw_util.c \
parser/arg.c parser/array.c parser/config_detail.c parser/config_utils.c parser/config.c parser/ft_atoi.c \
parser/get_next_line.c parser/get_next_line_utils.c parser/map_error.c parser/map_error_util.c parser/map_parse.c \
parser/map_parse_util.c parser/parse.c parser/rgb_parse.c parser/rgb_utils.c parser/parse_util.c
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
