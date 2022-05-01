# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sserwyn@student.21-school.ru <sserwyn>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 21:53:07 by sserwyn           #+#    #+#              #
#    Updated: 2022/04/30 21:58:46 by sserwyn@stu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= clang
NAME			= pipex

HEADER			= pipex.h

RM				= rm -f

SRC_MANDATORY	= src/mandatory/ft_strjoin.c \
					src/mandatory/ft_split.c \
					src/mandatory/main.c \
					src/mandatory/utils.c \
					src/mandatory/ft_strlen.c \
					src/mandatory/error_with_exit.c \
					src/mandatory/ft_putstr.c \
					src/mandatory/ft_strncmp.c


OBJ_MANDATORY	= $(SRC_MANDATORY:.c=.o)

CFLAGS			= -Wall -Werror -Wextra -I$(HEADER)


.PHONY:		all clean fclean re norm


all:			$(NAME)

$(NAME):		$(OBJ_MANDATORY) $(HEADER)
				$(CC) $(OBJ_MANDATORY) $(CFLAGS) -o $(NAME)


%.o:			%.c $(HEADER) $(HEADER_GNL)
				$(CC) -Wall -Wextra -Werror -I$(HEADER) -O3 -c $< -o $@

clean:
				$(RM) $(OBJ_MANDATORY)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

norm:
				find . -name "*.c" -or -name "*.h" | xargs norminette
