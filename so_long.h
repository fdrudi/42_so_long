/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:03:42 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/16 12:54:57 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx_mms_20200219/mlx.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_win
{
	int		x;
	int		y;
	int		fd;
	char	**map;
}				t_win;

typedef struct s_enemy
{
	int		*enm_x;
	int		*enm_y;
	int		enm_count;
}				t_enemy;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*path;
	int		end;
	int		next;
	int		lst_key;
	int		delay;
	int		delay2;
	int		delay3;
	int		delay4;
	int		index;
	int		moves;
	int		img_x;
	int		img_y;
	int		pg_y;
	int		pg_x;
	int		*obj_x;
	int		*obj_y;
	int		obj_count;
	int		ex_y;
	int		ex_x;
	t_win	w;
	t_enemy	n;
	// int		x;
	// int		y;
	// int		fd;
	// char	**map;
}				t_vars;

int		*ft_intjoin(int *str, int i, int size);
char	*ft_strclean(char *str);
int		*ft_int_trim(int *str, int pos, int size);
int		ft_move_count(t_vars *vars, t_win *map);
int	ft_key_press(int keycode, t_vars *vars);
int	ft_key_release(int keycode, t_vars *vars);
int	ft_move_pg(t_vars *vars, int y, int x);
int	ft_endgame(t_vars *vars);
int	ft_reset(t_vars *vars, int n);
int	ft_next_level(t_vars *vars);
int	ft_start(t_vars *vars);
int	ft_make_map(t_vars *vars, int *img_x, int *img_y);
int	ft_check_next_map(t_vars *vars);
int	ft_check_obj(t_vars *vars);
int	ft_strlen_y(char **s);
int	ft_hook_loop(t_vars *vars);
int	ft_obj_animation(t_vars *vars);
int	ft_check_exit(t_vars *vars);
int	ft_animation(t_vars *vars, char *s2, int x, int y);
int	ft_delay(int *delay, int time);
int	ft_put_floor(t_vars *vars, int x, int y);
int	ft_put_floor_map(t_vars *vars, int x, int y);
int	ft_fade(t_vars *vars);
int	ft_enemy_animation(t_vars *vars);
int	ft_check_enemy_moves(t_vars *vars, int i);
int	ft_close_win(t_vars *vars);


#endif
