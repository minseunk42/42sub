# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/24 15:20:03 by minseunk          #+#    #+#              #
#    Updated: 2023/09/22 09:02:13 by minseunk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC 	   = 		cc
CFLAGS = 		-Wall -Wextra -Werror
HEADER = 		-I./header

SRC_DIR   = 	srcs
SRC_FILES = 	main.c \
				util.c \
				philo.c \
				fork.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADER) -c -o $@ $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(HEADER) $(LIB) -o $@ $^ -lpthread -fsanitize=thread -g 

clean:
	rm -rf $(OBJ)
	rm -rf ./temp/*

fclean:
	make clean
	rm -f $(NAME)

re: 
	make fclean
	make all

.PHONY: clean fclean re all bonus
