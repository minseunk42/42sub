CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = includes
SRCS = srcs/main.c srcs/opfunc.c
OBJS = ${SRCS:.c=.o}
TARGET = do-op 
RM = rm -f
AR = ar rsc

all : $(TARGET)
	
$(TARGET) : $(OBJS)
	@$(CC) $(CFLAGS) -I $(HEADER) -o $@ $^

.c.o :
	@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(TARGET)

re : fclean all

.PHONY: all fclean clean re
