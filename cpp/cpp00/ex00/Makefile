NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
HEADER = includes
SRCS = megaphone.cpp

all :
	make $(NAME)

clean :
	$(RM) $(NAME)

re :
	make clean
	make all

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -I $(HEADER) -o $@ 

.PHONY : all clean re
