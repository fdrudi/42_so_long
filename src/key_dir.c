/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:22:14 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/24 15:47:07 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_key_act_w(t_env *e, int key)
{
	if ((key == 13 || key == 126) && e->w.m[e->p.pg_y - 1][e->p.pg_x] != '1'
			&& (e->w.m[e->p.pg_y - 1][e->p.pg_x] != 'E' || e->obj_c == -1))
	{
		if (e->lst_key == -1 && e->p.atk == 1)
			e->lst_key = 1;
		else if (e->lst_key == -1 && e->end == 0)
		{
			e->p.atk = 1;
			e->index = 0;
			ft_animate(e, "./spr/mg/mg_back", e->p.pg_x, e->p.pg_y);
		}
	}
	return ;
}

void	ft_key_act_s(t_env *e, int key)
{
	if ((key == 1 || key == 125) && e->w.m[e->p.pg_y + 1][e->p.pg_x] != '1'
		&& (e->w.m[e->p.pg_y + 1][e->p.pg_x] != 'E' || e->obj_c == -1))
	{
		if (e->lst_key == -1 && e->p.atk == 2)
			e->lst_key = 2;
		else if (e->lst_key == -1 && e->end == 0)
		{
			e->p.atk = 2;
			e->index = 0;
			ft_animate(e, "./spr/mg/mg_front", e->p.pg_x, e->p.pg_y);
		}
	}
	return ;
}

void	ft_key_act_a(t_env *e, int key)
{
	if ((key == 0 || key == 123) && e->w.m[e->p.pg_y][e->p.pg_x - 1] != '1'
		&& (e->w.m[e->p.pg_y][e->p.pg_x - 1] != 'E' || e->obj_c == -1))
	{
		if (e->lst_key == -1 && e->p.atk == 3)
			e->lst_key = 3;
		else if (e->lst_key == -1 && e->end == 0)
		{
			e->p.atk = 3;
			e->index = 0;
			ft_animate(e, "./spr/mg/mg_sx", e->p.pg_x, e->p.pg_y);
		}
	}
	return ;
}

void	ft_key_act_d(t_env *e, int key)
{
	if ((key == 2 || key == 124) && e->w.m[e->p.pg_y][e->p.pg_x + 1] != '1'
		&& (e->w.m[e->p.pg_y][e->p.pg_x + 1] != 'E' || e->obj_c == -1))
	{
		if (e->lst_key == -1 && e->p.atk == 4)
			e->lst_key = 4;
		else if (e->lst_key == -1 && e->end == 0)
		{
			e->p.atk = 4;
			e->index = 0;
			ft_animate(e, "./spr/mg/mg_dx", e->p.pg_x, e->p.pg_y);
		}
	}
	return ;
}
