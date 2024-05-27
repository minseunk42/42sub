NAME = btc
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
HEADER = ./
SRCS = main.cpp BitcoinExchange.cpp
OBJS = $(SRCS:.cpp=.o)

all :
	make $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(HEADER) -o $@ 

%.o : %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY : all clean fclean re