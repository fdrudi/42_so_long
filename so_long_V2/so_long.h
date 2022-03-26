/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:03:42 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/26 12:23:12 by fdrudi           ###   ########.fr       */
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
	int		n_m;
	int		*patr;
	int		*i;
}				t_enemy;

typedef struct s_pg
{
	int		pg_y;
	int		pg_x;
	int		pg_c;
	int		t_x;
	int		t_y;
	int		d_mg;
	int		d_ak;
	int		atk;
	int		atk_c;
	int		x_p;
	int		y_p;
}				t_pg;

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
	// int		index;
	int		mv;
	int		i_x;
	int		i_y;
	int		*obj_x;
	int		*obj_y;
	int		obj_c;
	int		ex_y;
	int		ex_x;
	t_pg	p;
	t_win	w;
	t_enemy	n;
}				t_env;

// * FUNCTIONS * //

// HOOKS

int		ft_key_press(int key, t_env *e);
int		ft_hook_loop(t_env *e);
void	ft_key_act_w(t_env *e, int key);
void	ft_key_act_s(t_env *e, int key);
void	ft_key_act_a(t_env *e, int key);
void	ft_key_act_d(t_env *e, int key);

// SET

int		ft_set_av_ac(t_env *e, int argc, char **argv);
void	ft_myinit(t_env *e);
void	ft_myinit2(t_env *e);
void	ft_myinit3(t_env *e);
int		ft_start(t_env *e);
int		ft_start_b(t_env *e);
int		ft_reset(t_env *e);
int		ft_reset_b(t_env *e);
void	ft_you_died(t_env *e);
int		ft_endgame(t_env *e);
int		ft_next_level(t_env *e);
int		ft_check_exit(t_env *e);
void	ft_exit(t_env *e);
void	ft_free_matrix(char **matrix, int y);
int		ft_close_win(t_env *e);
void	ft_error(t_env *e, char *s);

// MAP

void	ft_map_path(t_env *e);
void	ft_make_map(t_env *e);
int		ft_check_next_map(t_env *e);
void	ft_check_map(t_env *e);
void	ft_check_size_map(t_env *e, int *y, int *x);
void	ft_check_size_map2(t_env *e, int *y, int *x);
void	ft_check_size_map3(t_env *e, int *y, int *x);

// ANIMATIONS

int		ft_delay(int *delay, int time);
int		ft_animate(t_env *e, char *s2, int x, int y, int index);
int		ft_animate_b(t_env *e, char *s2, int x, int y, int index);
int		ft_put_floor(t_env *e, int x, int y);
int		ft_put_floor_map(t_env *e, int x, int y);

// OBJECTS

int		ft_obj_animation(t_env *e);
int		ft_check_obj(t_env *e, int y, int x);

// MAGE

int		ft_mg_move(t_env *e);
int		ft_mg_attack(t_env *e);
int		ft_cond_mg(t_env *e);
int		ft_fade(t_env *e);
int		ft_move_count(t_env *e, t_win *m);

// ENEMY

int		ft_enemy_patrol(t_env *e);
int		ft_enemy_animation(t_env *e);
int		ft_enemy_attack(t_env *e);
int		ft_check_enemy_patr(t_env *e, int j);
int		ft_check_enemy_moves(t_env *e, int j);
int		ft_check_enemy_moves_b(t_env *e, int j);
int		ft_check_attack(t_env *e, int j);
int		ft_check_pg(t_env *e, int j);

int		ft_enemy_dir(t_env *e, int j);

int		ft_enemy_move_a(t_env *e, int j);
int		ft_enemy_move_d(t_env *e, int j);
int		ft_enemy_move_w(t_env *e, int j);
int		ft_enemy_move_s(t_env *e, int j);

void	ft_enemy_move_atk_w(t_env *e, int j, int y, int x);
void	ft_enemy_move_atk_s(t_env *e, int j, int y, int x);
void	ft_enemy_move_atk_a(t_env *e, int j, int y, int x);
void	ft_enemy_move_atk_d(t_env *e, int j, int y, int x);

int		ft_cond(t_env *e, int y, int x);

// UTILS

int		ft_min_nbr(int a, int b);
int		*ft_intjoin(int *str, int i, int size);
char	*ft_strclean(char *str);
int		*ft_int_trim(int *str, int pos, int size);
int		ft_strlen_gnl(char *s);
void	ft_get_next_matrix(t_env *e);

#endif
