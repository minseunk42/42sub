# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 19:33:42 by gylim             #+#    #+#              #
#    Updated: 2023/07/26 18:58:47 by minseunk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC 	   = 		cc
CFLAGS = 		-Wall -Wextra -Werror -g3 -fsanitize=address
HEADER = 		-I./header

SRC_DIR   = 	src
SRC_FILES = 	builtin/cd.c \
				builtin/cd_utils.c \
				builtin/echo.c \
				builtin/env.c \
				builtin/exit.c \
				builtin/export.c \
				builtin/pwd.c \
				builtin/unset.c \
				builtin/builtins.c \
				env/env_list.c \
				env/env_list2.c \
				env/env_list3.c \
				executor/builtin.c \
				executor/cmd.c \
				executor/cmd_run.c \
				executor/cmd_set.c \
				executor/envp.c \
				executor/executor.c \
				executor/job.c \
				executor/path.c \
				executor/pipeline.c \
				executor/rd.c \
				executor/rd_set.c \
				executor/simplecmd.c \
				executor/status.c \
				executor/types.c \
				executor/types_rd.c \
				expander/expander.c \
				expander/expander2.c \
				expander/expander3.c \
				expander/expander4.c \
				expander/expander5.c \
				heredoc/heredoc.c \
				heredoc/heredoc2.c \
				heredoc/heredoc3.c \
				lexer/lexer.c \
				lexer/token.c \
				parser/parser.c \
				parser/cmdline.c \
				parser/job.c \
				parser/cmd.c \
				parser/rdlist.c \
				parser/simplecmd.c \
				parser/tokenlist.c  \
				parser/tree.c	\
				free.c \
				main.c \
				setup.c \
				utils.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:.c=.o)

LIB_DIR = libft
LIBFT = -L./$(LIB_DIR) -lft
LIB = $(LIBFT) $(CPPFLAGS) $(LDFLAGS) -lreadline
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADER) -c $(CPPFLAGS) -o $@ $<

$(NAME): $(OBJ)
	make -C $(LIB_DIR) all
	$(CC) $(CFLAGS) $(HEADER) $(LIB) -o $@ $^

clean:
	make -C $(LIB_DIR) clean
	rm -rf $(OBJ)
	rm -rf ./temp/*

fclean:
	make clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: 
	make fclean
	make all

.PHONY: clean fclean re all bonus
