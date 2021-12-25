# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/17 17:20:45 by sserwyn           #+#    #+#              #
#    Updated: 2021/12/25 16:17:00 by sserwyn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
NAME	= libftprintf.a
HEADER	= ft_printf.h
SRC		= ft_ltoa.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_pointer_to_str.c \
			ft_itoa.c \
			ft_printf.c \
			ft_putnbr_base.c \
			ft_strlen.c \
			ft_handling_str_args.c \
			ft_strcpy.c

OBJ		= $(SRC:.c=.o)
CFLAGS	= -Wall -Werror -Wextra -I.$(HEADER)
RM		= rm -f
AR  	= ar -rcs

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
			$(AR) $(NAME) $(OBJ) $(HEADER)

%.o:		%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJ) $(B_OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

# so:
# 			gcc -shared -o libftprintf.so *.o

.PHONY:		all clean fclean re
