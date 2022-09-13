NAME=philo

CC=cc
CFLAGS= -Wall -Wextra -Werror -fsanitize=thread

RM=rm -f
SRC= main.c \
	 init.c \
	 check.c \
	 utils.c \
	 print.c \
	 meal.c \
	
OBJ=$(SRC:.c=.o)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
