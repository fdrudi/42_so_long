# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:57:20 by fdrudi            #+#    #+#              #
#    Updated: 2022/03/24 19:14:10 by fdrudi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRC			=	./src/so_long.c ./src/so_long_utils.c ./src/map_utils.c ./src/check.c ./src/animation.c\
				./src/enemy_move.c ./src/set_env.c ./src/close.c ./src/animation_utils.c ./src/myinit.c\
				./src/enemy_move_utils.c ./src/enemy_move_check.c ./src/enemy_attack.c\
				./src/map_utils2.c ./src/enemy_moveset.c ./src/enemy_attack_moveset.c\
				./src/mage_move.c ./src/mage_attack.c ./src/check_menu.c ./src/check_menu2.c\
				./src/enemy_dir.c ./src/key_dir.c ./src/get_next_matrix.c\

OBJ			=	$(SRC:.c=.o)

MLX			=	./libmlx.dylib

LIBFT		=	libft/libft.a

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -Imlx

%.o:%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			make -C ./libft
			make -C ./minilibx_mms_20200219
			$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(MLX) $(LIBFT)

all:		$(NAME)

clean:
			${RM} $(OBJ)

fclean: 	clean
			${RM} $(NAME) ${OBJ}

fclean.all:	fclean
			make fclean -C libft
			make clean -C minilibx_mms_20200219

re:			fclean all

re.all:		fclean.all all

.PHONY:		all clean fclean re
