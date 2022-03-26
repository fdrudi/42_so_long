/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:50:50 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/24 19:12:24 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_hook_loop(t_env *e)
{
	if (e->win != NULL)
	{
		ft_obj_animation(e);
		if (e->end == 0 || e->end == -1)
		{
			if (e->lst_key != -1 && e->lst_key != 7 && e->end == 0)
				ft_mg_move(e);
			else if (e->lst_key == 7)
				ft_mg_attack(e);
			ft_enemy_patrol(e);
			ft_enemy_animation(e);
			ft_enemy_attack(e);
		}
		if (e->obj_c == 0)
			ft_check_exit(e);
		if (e->w.m[e->p.y_p][e->p.x_p] == 'E')
			ft_fade(e);
	}
	return (0);
}

int	ft_key_dir(t_env *e, int key)
{
	if (key == 13 || key == 126)
		ft_key_act_w(e, key);
	else if (key == 1 || key == 125)
		ft_key_act_s(e, key);
	else if (key == 0 || key == 123)
		ft_key_act_a(e, key);
	else if (key == 2 || key == 124)
		ft_key_act_d(e, key);
	else if (key == 49 && ft_cond_mg(e) == 0)
		if (e->lst_key == -1)
			e->lst_key = 7;
	return (0);
}

int	ft_key_press(int key, t_env *e)
{
	if (key == 53)
		ft_close_win(e);
	else if (key == 15)
	{
		if (e->end == 2)
		{
			e->next = 0;
			ft_next_level(e);
		}
		else if (e->w.ac > 1)
			ft_reset_b(e);
		else
			ft_reset(e);
	}
	else if (e->end == 1)
	{
		if (key == 36)
		{
			e->next += 1;
			ft_next_level(e);
		}
	}
	else if (e->end == 0)
		ft_key_dir(e, key);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_env	e;

	e.mlx = mlx_init();
	if (e.mlx == NULL)
		ft_error(&e, "error : allocation error\n");
	e.next = 0;
	if (argc > 1)
	{
		ft_set_av_ac(&e, argc, argv);
		ft_start_b(&e);
	}
	else
	{
		e.w.ac = 1;
		ft_start(&e);
	}
	mlx_loop_hook(e.mlx, ft_hook_loop, &e);
	mlx_hook(e.win, 17, 0, ft_close_win, &e);
	mlx_loop(e.mlx);
	return (0);
}
