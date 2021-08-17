# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/17 12:01:39 by sserwyn           #+#    #+#              #
#    Updated: 2021/08/17 12:03:07 by sserwyn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
NAME	= ft_cat
SRC		= main.c ft_putstr.c ft_strlen.c
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