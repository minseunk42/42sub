NAME = server client
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
PRINTF = ./ft_printf/libftprintf.a
PRINTF_DIR = ft_printf/
HEADER = includes
S_SRCS = srcs/svr/main.c
S_OBJS = $(S_SRCS:.c=.o)
C_SRCS = srcs/ct/main.c
C_OBJS = $(C_SRCS:.c=.o)
SB_SRCS =
SB_OBJS = $(B_SRCS:.c=.o)
CB_SRCS =
CB_OBJS = $(B_SRCS:.c=.o)
OBJS = $(S_OBJS) $(SB_OBJS) $(C_OBJS) $(CB_OBJS) 

ifdef BONUS
	S_OBJS = $(SB_OBJS)
	C_OBJS = $(CB_OBJS)
endif

all : $(NAME)

clean :
	make -C $(PRINTF_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(PRINTF_DIR) fclean
	$(RM) $(NAME)

re :
	make fclean
	make all

bonus :
	make BONUS=1 $(NAME)

server : $(PRINTF) $(S_OBJS)
	$(CC) $(CFLAGS) $(S_OBJS) -I $(HEADER) -L $(PRINTF_DIR) -lftprintf -o $@

client : $(PRINTF) $(C_OBJS)
	$(CC) $(CFLAGS) $(C_OBJS) -I $(HEADER) -L $(PRINTF_DIR) -lftprintf -o $@

$(PRINTF) :
	make -C $(PRINTF_DIR) all

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY : all clean fclean re bonus
