/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:03:42 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/13 18:04:13 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx_mms_20200219/mlx.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*path;
	int		img_x;
	int		img_y;
	int		pg_y;
	int		pg_x;
	int		*obj_x;
	int		*obj_y;
	int		obj_count;
	int		x;
	int		y;
	int		fd;
	char	**map;

}				t_vars;

typedef struct s_win
{
	int		x;
	int		y;
	int		fd;
	char	**map;
}				t_win;

int		*ft_intjoin(int *str, int i, int size);
char	*ft_strclean(char *str);
int		*ft_int_trim(int *str, int pos, int size);



#endif
