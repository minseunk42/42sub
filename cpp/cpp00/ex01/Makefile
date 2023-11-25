NAME = phonebook
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
HEADER = ./
SRCS = main.cpp PhoneBook.cpp Contact.cpp

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
