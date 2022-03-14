# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:57:20 by fdrudi            #+#    #+#              #
#    Updated: 2022/03/14 11:43:00 by fdrudi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRC			=	so_long.c so_long_utils.c\

OBJ			=	$(SRC:.c=.o)

MLX			=	./libmlx.dylib

LIBFT		=	libft/libft.a

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

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

re.all:		fclean

.PHONY:		all clean fclean re
