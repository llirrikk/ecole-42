# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sserwyn <sserwyn@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/17 17:20:45 by sserwyn           #+#    #+#              #
#    Updated: 2021/08/23 19:41:16 by sserwyn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
NAME	= bsq
SRC		= main.c \
			ft_realloc.c \
			ft_putstr.c \
			ft_strlen.c \
			ft_putstr_error.c \
			is_ascii.c \
			first_line.c \
			error_exits.c \
			map_checker.c \
			read_console_main.c \
			str_utils.c \
			read_file_main.c

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