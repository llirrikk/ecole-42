# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 18:06:26 by sserwyn           #+#    #+#              #
#    Updated: 2022/06/04 16:39:08 by sserwyn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= clang
NAME			= philo_bonus

HEADER			= philo.h

RM				= rm -f

SRC_MANDATORY	= ft_atoi.c \
					ft_strlen.c \
					philo_actions.c \
					sems.c \
					timeval.c \
					ft_isdigit.c \
					main.c \
					output.c \
					start.c \
					utils.c



OBJ_MANDATORY	= $(SRC_MANDATORY:.c=.o)

CFLAGS			= -Wall -Werror -Wextra -pthread -O3


.PHONY:		all clean fclean re norm


all:			$(NAME)

$(NAME):		$(OBJ_MANDATORY) $(HEADER)
				$(CC) $(OBJ_MANDATORY) $(CFLAGS) -I$(HEADER) -o $(NAME)


%.o:			%.c $(HEADER) $(HEADER_GNL)
				$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

clean:
				$(RM) $(OBJ_MANDATORY)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

norm:
				find . -name "*.c" -or -name "*.h" | xargs norminette
