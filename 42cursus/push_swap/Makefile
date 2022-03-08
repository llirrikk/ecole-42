# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 00:49:37 by sserwyn           #+#    #+#              #
#    Updated: 2022/03/05 18:34:15 by sserwyn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= clang
NAME			= push_swap
NAME_BONUS		= checker

HEADER			= push_swap.h

RM				= rm -f

SRC_GNL			= get_next_line/get_next_line_utils.c \
					get_next_line/get_next_line.c
HEADER_GNL		= get_next_line/get_next_line.h

SRC_UTILS		= src/utils/actions1.c \
					src/utils/actions2.c \
					src/utils/actions3.c \
					src/utils/work_with_stack.c \
					src/utils/ft_atol_modified.c \
					src/utils/ft_list_push_back.c \
					src/utils/ft_create_elem.c \
					src/utils/ft_isdigit.c \
					src/utils/ft_lstclear.c \
					src/utils/ft_atoi.c \
					src/utils/handle_exits.c \
					src/utils/args_checker.c


SRC_MANDATORY	= src/mandatory/ft_swap.c \
					src/mandatory/main.c \
					src/mandatory/prepare_a_stack_to_put_in.c \
					src/mandatory/expected_moves.c \
					src/mandatory/find_stack_min_max_med.c \
					src/mandatory/sort_3_stack_elems.c \
					src/mandatory/stack_element_to_top.c \
					src/mandatory/stack_index2value_value2index.c \
					src/mandatory/stacks_moves_points.c \

SRC_BONUS		= src/bonus/ft_strcmp.c \
					src/bonus/main.c \
					src/bonus/use_instructions.c

SRC_MANDATORY	+= $(SRC_UTILS)

SRC_BONUS		+= $(SRC_GNL)
SRC_BONUS		+= $(SRC_UTILS)


OBJ_MANDATORY	= $(SRC_MANDATORY:.c=.o)
OBJ_BONUS		= $(SRC_BONUS:.c=.o)

CFLAGS			= -Wall -Werror -Wextra -I$(HEADER) -I$(HEADER_GNL)


.PHONY:		all clean fclean re bonus norm


all:			$(NAME)

$(NAME):		$(OBJ_MANDATORY) $(HEADER)
				$(CC) $(OBJ_MANDATORY) $(CFLAGS) -o $(NAME)

$(NAME_BONUS):	$(OBJ_BONUS) $(HEADER) $(HEADER_GNL)
				$(CC) $(OBJ_BONUS) $(CFLAGS) -o $(NAME_BONUS)

bonus:			$(NAME_BONUS)

%.o:			%.c $(HEADER) $(HEADER_GNL)
				$(CC) -Wall -Wextra -Werror -I$(HEADER) -O3 -c $< -o $@

clean:
				$(RM) $(OBJ_MANDATORY) $(OBJ_BONUS)

fclean:			clean
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all

norm:
				find . -name "*.c" -or -name "*.h" | xargs norminette
