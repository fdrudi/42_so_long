/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:03:42 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/19 18:42:01 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx_mms_20200219/mlx.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_win
{
	int		x;
	int		y;
	int		fd;
	char	**m;
	char	**av;
	int		ac;
}				t_win;

typedef struct s_enemy
{
	int		*n_x;
	int		*n_y;
	int		*x_m;
	int		*y_m;
	int		n_c;
	int		*patr;
}				t_enemy;

typedef struct s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*path;
	int		end;
	int		next;
	int		lst_key;
	int		d;
	int		d2;
	int		d3;
	int		d4;
	int		d5;
	int		d6;
	int		index;
	int		mv;
	int		i_x;
	int		i_y;
	int		pg_y;
	int		pg_x;
	int		*obj_x;
	int		*obj_y;
	int		obj_c;
	int		ex_y;
	int		ex_x;
	t_win	w;
	t_enemy	n;
}				t_env;

int		*ft_intjoin(int *str, int i, int size);
char	*ft_strclean(char *str);
int		*ft_int_trim(int *str, int pos, int size);
int		ft_move_count(t_env *e, t_win *m);
int		ft_key_press(int key, t_env *e);
int		ft_key_release(int key, t_env *e);
int		ft_move_pg(t_env *e, int y, int x);
int		ft_endgame(t_env *e);
int		ft_reset(t_env *e, int n);
int		ft_next_level(t_env *e);
void	ft_exit(t_env *e);
void	free_matrix(char **matrix);
int		ft_start(t_env *e);
void	ft_make_map(t_env *e);
int		ft_check_next_map(t_env *e);
int		ft_check_obj(t_env *e);
int		ft_strlen_y(char **s);
int		ft_hook_loop(t_env *e);
int		ft_obj_animation(t_env *e);
int		ft_check_exit(t_env *e);
int		ft_animation(t_env *e, char *s2, int x, int y);
int		ft_delay(int *delay, int time);
int		ft_put_floor(t_env *e, int x, int y);
int		ft_put_floor_map(t_env *e, int x, int y);
int		ft_fade(t_env *e);
int		ft_enemy_animation(t_env *e);
int		ft_check_enemy_moves(t_env *e, int j);
int		ft_close_win(t_env *e);
int		ft_enemy_patrol(t_env *e);
int		ft_check_pg(t_env *e, int j, int i);
int		ft_min_nbr(int a, int b);
int		ft_check_cond(t_env *e, int y, int x, int j);
int		ft_check_enemy_patr(t_env *e, int j);
int		ft_check_enemy_moves_b(t_env *e, int j);
int		ft_start_b(t_env *e);
int		ft_reset_b(t_env *e, int n);
int		ft_enemy_attack(t_env *e);
int		ft_animation_b(t_env *e, char *s2, int x, int y);
int		ft_check_attack(t_env *e, int j);

#endif
