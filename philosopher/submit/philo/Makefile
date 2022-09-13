# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 16:39:32 by jaekim            #+#    #+#              #
#    Updated: 2022/09/07 02:10:33 by jaekim           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME=philo

CC=cc
CFLAGS= -Wall -Wextra -Werror
THREAD = -fsanitize=thread
RM=rm -rf

SRC= ./main.c \
	 ./src/init.c ./src/end.c ./src/time.c ./src/monitor.c ./src/action.c ./src/display.c \

UTILS= ./utils/actions.c ./utils/check_flag_utils.c ./utils/check_philo_utils.c ./utils/is_utils.c \
	 ./utils/error.c ./utils/safe_utils.c ./utils/ft_strlen.c ./utils/ft_strncmp.c  ./utils/ft_atoi.c ./utils/ft_isdigit.c \
	
SRC_OBJS=$(SRC:.c=.o)
UTILS_OBJS=$(UTILS:.c=.o)

OBJS= $(SRC_OBJS) $(UTILS_OBJS)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

debug_thread :
	$(CC) $(SRC) $(UTILS) -g3 $(THREAD) -o philo_test

debug_sanitize :
	$(CC) $(SRC) $(UTILS) -g3  -fsanitize=address -o philo_test

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	$(RM) philo_test.dSYM
	$(RM) philo_test

re : fclean all

.PHONY : all clean fclean re
