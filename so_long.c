/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:50:50 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/19 10:21:03 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

int	ft_hook_loop(t_env *e)
{
	ft_obj_animation(e);
	ft_enemy_patrol(e);
	ft_enemy_animation(e);
	if (e->obj_c == 0)
		ft_check_exit(e);
	if (e->w.m[e->pg_y][e->pg_x] == 'E')
		ft_fade(e);
	return (0);
}

int	ft_key_act(t_env *e, int key)
{
	if ((key == 13 || key == 126) && e->w.m[e->pg_y - 1][e->pg_x] != '1'
			&& (e->w.m[e->pg_y - 1][e->pg_x] != 'E' || e->obj_c == -1))
	{
		ft_move_pg(e, -1, 0);
		ft_move_count(e, &e->w);
	}
	if ((key == 1 || key == 125) && e->w.m[e->pg_y + 1][e->pg_x] != '1'
		&& (e->w.m[e->pg_y + 1][e->pg_x] != 'E' || e->obj_c == -1))
	{
		ft_move_pg(e, 1, 0);
		ft_move_count(e, &e->w);
	}
	if ((key == 0 || key == 123) && e->w.m[e->pg_y][e->pg_x - 1] != '1'
		&& (e->w.m[e->pg_y][e->pg_x - 1] != 'E' || e->obj_c == -1))
	{
		ft_move_pg(e, 0, -1);
		ft_move_count(e, &e->w);
	}
	if ((key == 2 || key == 124) && e->w.m[e->pg_y][e->pg_x + 1] != '1'
		&& (e->w.m[e->pg_y][e->pg_x + 1] != 'E' || e->obj_c == -1))
	{
		ft_move_pg(e, 0, 1);
		ft_move_count(e, &e->w);
	}
	return (0);
}

int	ft_key_press(int key, t_env *e)
{
	if (key == 53)
		ft_close_win(e);
	if (key == 15)
	{
		ft_reset(e, e->next);
		return (1);
	}
	if (e->end == 1)
	{
		if (key == 36)
		{
			e->next += 1;
			ft_next_level(e);
			return (0);
		}
	}
	if (e->end == 0)
		ft_key_act(e, key);
	return (0);
}

// int	ft_key_release(int key, t_env *e)
// {
// 	if (e->end == 0)
// 	{
// 		if ((key == 13 || key == 126) && e->w.m[e->pg_y - 1][e->pg_x] != '1'
// 			&& (e->w.m[e->pg_y - 1][e->pg_x] != 'E' || e->obj_c == -1))
// 		{
// 			if (e->lst_key != 1)
// 			{
// 				e->lst_key = 1;
// 				return (0);
// 			}
// 			ft_move_pg(e, -1, 0);
// 			ft_move_count(e, &e->w);
// 			e->lst_key = 1;

// 		}
// 		if ((key == 1 || key == 125) && e->w.m[e->pg_y + 1][e->pg_x] != '1'
// 			&& (e->w.m[e->pg_y + 1][e->pg_x] != 'E' || e->obj_c == -1))
// 		{
// 			if (e->lst_key != 2)
// 			{
// 				e->lst_key = 2;
// 				return (0);
// 			}
// 			ft_move_pg(e, 1, 0);
// 			ft_move_count(e, &e->w);
// 			e->lst_key = 2;

// 		}
// 		if ((key == 0 || key == 123) && e->w.m[e->pg_y][e->pg_x - 1] != '1'
// 			&& (e->w.m[e->pg_y][e->pg_x - 1] != 'E' || e->obj_c == -1))
// 		{
// 			if (e->lst_key != 3)
// 			{
// 				e->lst_key = 3;
// 				return (0);
// 			}
// 			ft_move_pg(e, 0, -1);
// 			ft_move_count(e, &e->w);
// 			e->lst_key = 3;
// 		}
// 		if ((key == 2 || key == 124) && e->w.m[e->pg_y][e->pg_x + 1] != '1'
// 			&& (e->w.m[e->pg_y][e->pg_x + 1] != 'E' || e->obj_c == -1))
// 		{
// 			if (e->lst_key != 4)
// 			{
// 				e->lst_key = 4;
// 				return (0);
// 			}
// 			ft_move_pg(e, 0, 1);
// 			ft_move_count(e, &e->w);
// 			e->lst_key = 4;
// 		}
// 	}
// 	return (0);
// }

int	main(void)
{
	t_env	e;
	// int		i;

	e.mlx = mlx_init();
	e.next = 0;
	e.n.x_m = (int *) malloc (sizeof(int) * 1);
	e.n.y_m = (int *) malloc (sizeof(int) * 1);
	ft_start(&e);
	// e.n.patr = (int *) malloc (sizeof(int) * e.n.n_c - 1);
	// i = -1;
	// while (++i <= e.n.n_c)
	// 	e.n.patr[i] = -1;
	mlx_loop_hook(e.mlx, ft_hook_loop, &e);
	mlx_hook(e.win, 17, 0, ft_close_win, &e);
	mlx_loop(e.mlx);
	return (0);
}
