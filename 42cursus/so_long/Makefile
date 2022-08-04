CC				= clang
NAME			= so_long
NAME_BONUS		= so_long_bonus
SRC				= src/utils/ft_strcpy.c \
					src/utils/ft_strlen_without_last_nl.c \
					src/utils/ft_itoa.c \
					src/parse_map.c \
					src/handle_errors.c \
					src/player_moves.c \
					src/user_actions.c

HEADER			= so_long.h
MLXFLAGS		= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RM				= rm -f

SRC				+= get_next_line/get_next_line_utils.c \
				get_next_line/get_next_line.c
HEADER_GNL		= get_next_line/get_next_line.h

SRC_MANDATORY	= src/mandatory_part/so_long.c \
					src/mandatory_part/make_frame.c \
					src/mandatory_part/init_game_struct.c \
					src/mandatory_part/check_map.c \
					src/mandatory_part/init_imgs.c
SRC_BONUS		= src/bonus_part/so_long.c \
					src/bonus_part/make_frame.c \
					src/bonus_part/init_game_struct.c \
					src/bonus_part/check_map.c \
					src/bonus_part/init_imgs.c

SRC_MANDATORY	+= $(SRC)
SRC_BONUS		+= $(SRC)


OBJ_MANDATORY	= $(SRC_MANDATORY:.c=.o)
OBJ_BONUS		= $(SRC_BONUS:.c=.o)

CFLAGS			= -Wall -Werror -Wextra -I$(HEADER) -I$(HEADER_GNL)


.PHONY:		all clean fclean re bonus norm


all:			$(NAME)

$(NAME):		$(OBJ_MANDATORY) $(HEADER) $(HEADER_GNL)
				$(CC) $(OBJ_MANDATORY) $(CFLAGS) $(MLXFLAGS) -o $(NAME)

$(NAME_BONUS):	$(OBJ_BONUS) $(HEADER) $(HEADER_GNL)
				$(CC) $(OBJ_BONUS) $(CFLAGS) $(MLXFLAGS) -o $(NAME_BONUS)

bonus:			$(NAME_BONUS)

%.o:			%.c $(HEADER) $(HEADER_GNL)
				$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
				$(RM) $(OBJ_MANDATORY) $(OBJ_BONUS)

fclean:			clean
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all

norm:
				find . -name "*.c" -or -name "*.h" | grep --invert-match "mlx_linux" | xargs norminette
