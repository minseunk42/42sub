# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 19:33:42 by gylim             #+#    #+#              #
#    Updated: 2023/07/13 19:24:30 by minseunk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
SRC_FILES_MAND = main.c \
				 env_list.c \
				 env_list2.c \
				 env_list3.c \
				 setup.c \
				 lexer.c \
				 token.c \
				 utils.c
SRC_FILES_BONUS = 
SRC_MAND = $(addprefix $(SRC_DIR)/, $(SRC_FILES_MAND))
SRC_BONUS = $(addprefix $(SRC_DIR)/, $(SRC_FILES_BONUS))
ifdef BONUS_FLAG
	SRC = $(SRC_BONUS)
else
	SRC = $(SRC_MAND)
endif

OBJ_DIR = obj
OBJ_FILES_MAND = $(SRC_FILES_MAND:.c=.o)
OBJ_FILES_BONUS = $(SRC_FILES_BONUS:.c=.o)
OBJ_MAND = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES_MAND))
OBJ_BONUS = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES_BONUS))
ifdef BONUS_FLAG
	OBJ = $(OBJ_BONUS)
else
	OBJ = $(OBJ_MAND)
endif

LIB_DIR = libft
LIBFT = -L./$(LIB_DIR) -lft
LIB = $(LIBFT) $(CPPFLAGS) $(LDFLAGS) -lreadline
all: $(NAME)

#bonus:
#make BONUS_FLAG=1 all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $(CPPFLAGS) -o $@ $<

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(NAME): $(OBJ)
	make -C $(LIB_DIR) all
	$(CC) $(CFLAGS) $(LIB) -o $@ $^

clean:
	make -C $(LIB_DIR) clean
	rm -rf $(OBJ_DIR)

fclean:
	make clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: 
	make fclean
	make all

.PHONY: clean fclean re all bonus
