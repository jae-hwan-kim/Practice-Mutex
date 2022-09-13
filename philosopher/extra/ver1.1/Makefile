NAME=philo

CC=cc
# CFLAGS= -Wall -Wextra -Werror

RM=rm -f
SRC= ./src/main.c \
	 ./utils/error.c \
	 ./utils/check.c \
	 ./utils/init.c \
	 ./utils/print.c \
	 ./utils/ft_atoi.c \
	 ./utils/ft_isdigit.c \
	 ./src/meals.c \
	 
	
OBJ=$(SRC:.c=.o)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
# $(CFLAGS) 

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
