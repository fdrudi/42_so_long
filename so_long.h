/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:03:42 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/12 17:44:18 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx_mms_20200219/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*path;
	int		pg_y;
	int		pg_x;
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

char	**ft_get_next_matrix(int fd);
int		ft_strlen(char *s);
char	**ft_split(const char *s, char c);

#endif
