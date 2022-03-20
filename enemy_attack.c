/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_attack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:48:01 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/20 17:59:40 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_enemy_move_atk_b(t_env *e, int j)
{
	if (e->n.x_m[j] == -1)
	{
		ft_animation(e, "./sprites/enm/atk/enm_atk_sx", e->n.n_x[j], e->n.n_y[j]);
		if (e->n.i[j] == 5)
		{
			ft_put_floor(e, e->n.n_x[j] - 1, e->n.n_y[j]);
			if (e->w.m[e->n.n_y[j]][e->n.n_x[j] - 1] == e->w.m[e->pg_y][e->pg_x])
				e->end = -1;
		}
		else if (e->n.i[j] == 1)
		{
			e->n.i[j] += 1;
			e->index = e->n.i[j];
			ft_animation_b(e, "./sprites/enm/atk/enm_atk_sx", e->n.n_x[j] - 1, e->n.n_y[j]);
		}
		else if (e->n.i[j] == 3)
		{
			ft_put_floor(e, e->n.n_x[j] - 1, e->n.n_y[j]);
			e->n.i[j] += 1;
			e->index = e->n.i[j];
			ft_animation(e, "./sprites/enm/atk/enm_atk_sx", e->n.n_x[j] - 1, e->n.n_y[j]);
		}
		return ;
	}
	else if (e->n.x_m[j] == 1)
	{
		ft_animation(e, "./sprites/enm/atk/enm_atk_dx", e->n.n_x[j], e->n.n_y[j]);
		if (e->n.i[j] == 5)
		{
			ft_put_floor(e, e->n.n_x[j] + 1, e->n.n_y[j]);
			if (e->w.m[e->n.n_y[j]][e->n.n_x[j] + 1] == e->w.m[e->pg_y][e->pg_x])
				e->end = -1;
		}
		else if (e->n.i[j] == 1)
		{
			e->n.i[j] += 1;
			e->index = e->n.i[j];
			ft_animation_b(e, "./sprites/enm/atk/enm_atk_dx", e->n.n_x[j] + 1, e->n.n_y[j]);
		}
		else if (e->n.i[j] == 3)
		{
			ft_put_floor(e, e->n.n_x[j] + 1, e->n.n_y[j]);
			e->n.i[j] += 1;
			e->index = e->n.i[j];
			ft_animation(e, "./sprites/enm/atk/enm_atk_dx", e->n.n_x[j] + 1, e->n.n_y[j]);
		}
		return ;
	}
	return ;
}

void	ft_enemy_move_atk(t_env *e, int j)
{
	if (e->n.y_m[j] == -1)
	{
		ft_animation(e, "./sprites/enm/atk/enm_atk_back", e->n.n_x[j], e->n.n_y[j]);
		if (e->n.i[j] == 5)
		{
			ft_put_floor(e, e->n.n_x[j], e->n.n_y[j] - 1);
			if (e->w.m[e->n.n_y[j] - 1][e->n.n_x[j]] == e->w.m[e->pg_y][e->pg_x])
				e->end = -1;
		}
		else if (e->n.i[j] == 1)
		{
			e->n.i[j] += 1;
			e->index = e->n.i[j];
			ft_animation_b(e, "./sprites/enm/atk/enm_atk_back", e->n.n_x[j], e->n.n_y[j] - 1);
		}
		else if (e->n.i[j] == 3)
		{
			ft_put_floor(e, e->n.n_x[j], e->n.n_y[j] - 1);
			e->n.i[j] += 1;
			e->index = e->n.i[j];
			ft_animation(e, "./sprites/enm/atk/enm_atk_back", e->n.n_x[j], e->n.n_y[j] - 1);
		}
		return ;
	}
	else if (e->n.y_m[j] == 1)
	{
		ft_animation(e, "./sprites/enm/atk/enm_atk_front", e->n.n_x[j], e->n.n_y[j]);
		if (e->n.i[j] == 5)
		{
			ft_put_floor(e, e->n.n_x[j], e->n.n_y[j] + 1);
			if (e->w.m[e->n.n_y[j] + 1][e->n.n_x[j]] == e->w.m[e->pg_y][e->pg_x])
				e->end = -1;
		}
		else if (e->n.i[j] == 1)
		{
			e->n.i[j] += 1;
			e->index = e->n.i[j];
			ft_animation_b(e, "./sprites/enm/atk/enm_atk_front", e->n.n_x[j], e->n.n_y[j] + 1);
		}
		else if (e->n.i[j] == 3)
		{
			ft_put_floor(e, e->n.n_x[j], e->n.n_y[j] + 1);
			e->n.i[j] += 1;
			e->index = e->n.i[j];
			ft_animation(e, "./sprites/enm/atk/enm_atk_front", e->n.n_x[j], e->n.n_y[j] + 1);
		}
		return ;
	}
	else
		ft_enemy_move_atk_b(e, j);
	return ;
}

void	ft_enemy_dir_atk(t_env *e, int j)
{
	if (e->n.y_m[j] == -1)
	{
		ft_enemy_move_atk(e, j);
		return ;
	}
	else if (e->n.y_m[j] == 1)
	{
		ft_enemy_move_atk(e, j);
		return ;
	}
	else if (e->n.x_m[j] == -1)
	{
		ft_enemy_move_atk(e, j);
		return ;
	}
	else if (e->n.x_m[j] == 1)
	{
		ft_enemy_move_atk(e, j);
		return ;
	}
}

int	ft_enemy_attack(t_env *e)
{
	int	j;

	j = 0;
	if (ft_delay(&e->d6, 1000) == 1)
		return (1);
	while (j < e->n.n_c)
	{
		e->index = e->n.i[j];
		if (e->n.patr[j] == 2)
		{
			ft_enemy_dir_atk(e, j);
			if (e->n.i[j] == 5)
				e->n.patr[j] = -1;
			else
				e->n.i[j] += 1;
		}
		j++;
	}
	return (0);
}
