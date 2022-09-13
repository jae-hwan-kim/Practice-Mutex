# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 10:46:44 by jaekim            #+#    #+#              #
#    Updated: 2022/04/21 15:28:36 by kimjaehwa        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
NAME = libft.a
MANDATORY_PART =    ft_isalpha \
                    ft_isdigit \
                    ft_isalnum \
                    ft_isascii \
                    ft_isprint \
                    ft_strlen \
                    ft_memset \
                    ft_bzero \
                    ft_memcpy \
                    ft_memmove \
                    ft_strlcpy \
                    ft_strlcat \
                    ft_toupper \
                    ft_tolower \
                    ft_strchr \
                    ft_strrchr \
                    ft_strncmp \
                    ft_memchr \
                    ft_memcmp \
                    ft_strnstr \
                    ft_atoi \
                    ft_calloc \
                    ft_strdup \
                    ft_substr \
                    ft_strjoin \
                    ft_strtrim \
                    ft_split \
                    ft_itoa \
                    ft_strmapi \
                    ft_striteri \
                    ft_putchar_fd \
                    ft_putstr_fd \
                    ft_putendl_fd \
                    ft_putnbr_fd 

BONUS_PART =    ft_lstnew \
                ft_lstadd_front \
                ft_lstsize \
                ft_lstlast \
                ft_lstadd_back \
                ft_lstdelone \
                ft_lstclear \
                ft_lstiter \
                ft_lstmap

SRCS = $(addsuffix .c, $(MANDATORY_PART))
SRCS_B = $(addsuffix .c, $(BONUS_PART))

ifdef WITH_BONUS
	OBJS = $(OBJS_MANDATORY) $(OBJS_BONUS)
else
	OBJS = $(addsuffix .o, $(MANDATORY_PART))
endif

OBJS_MANDATORY = $(addsuffix .o, $(MANDATORY_PART))
OBJS_BONUS = $(addsuffix .o, $(BONUS_PART))

.c.o: $(SRCS) $(SRCS_B)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

bonus:
	@make WITH_BONUS=1 all

clean :
	rm -f $(OBJS_MANDATORY) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME) $(OBJS_MANDATORY) $(OBJS_BONUS)

re : clean all

.PHONY : all clean fclean re bonus
