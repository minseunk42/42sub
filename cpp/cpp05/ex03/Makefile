NAME = bureaucrat
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
HEADER = ./
SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJS = $(SRCS:.cpp=.o)

all :
	make $(NAME)

clean :
	$(RM) $(OBJS) *_shrubbery

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