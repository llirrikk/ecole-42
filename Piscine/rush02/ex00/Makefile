# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/17 17:20:45 by sserwyn           #+#    #+#              #
#    Updated: 2021/08/22 20:56:43 by sserwyn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
NAME	= rush-02
SRC		= main.c \
		argv_cleaner.c \
		ft_create_elem.c \
		ft_list_push_back.c \
		ft_putstr.c \
		ft_realloc.c \
		ft_strlen.c \
		is_ascii.c \
		parse_to_dict.c \
		parse_to_dict_main.c \
		number_finder.c \
		ft_strcmp.c \
		ft_list_find_digit.c \
		itoa.c \
		ft_recursive_power.c \
		list_clear.c \
		if_triple_is.c
	
OBJ		= $(SRC:.c=.o)
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all