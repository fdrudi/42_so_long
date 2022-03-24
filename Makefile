# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:57:20 by fdrudi            #+#    #+#              #
#    Updated: 2022/03/24 14:32:01 by fdrudi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRC			=	so_long.c so_long_utils.c map_utils.c check.c animation.c\
				enemy_move.c set_env.c close.c animation_utils.c myinit.c\
				enemy_move_utils.c enemy_move_check.c enemy_attack.c\
				map_utils2.c enemy_moveset.c enemy_attack_moveset.c\
				mage_move.c mage_attack.c check_menu.c check_menu2.c\
				enemy_dir.c key_dir.c get_next_matrix.c\

OBJ			=	$(SRC:.c=.o)

MLX			=	./libmlx.dylib

LIBFT		=	libft/libft.a

CC			=	gcc #-fsanitize=address

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

%.o:%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			make -C ./libft
			make -C ./minilibx_mms_20200219
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(LIBFT)

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
