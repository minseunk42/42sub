NAME = harlFilter
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
RM = rm -rf
HEADER = ./
SRCS = main.cpp Harl.cpp
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
	c++ $(CFLAGS) -o $@ -c $<

.PHONY : all clean fclean re