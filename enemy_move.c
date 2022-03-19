/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:26:26 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/19 18:42:51 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_enemy_move_b(t_env *e, int j, int i)
{
	if (e->n.x_m[j] == -1)
	{
		if (i == 4 && ft_check_cond(e, e->n.n_y[j], e->n.n_x[j] + 1, j) == 0)
			ft_put_floor(e, e->n.n_x[j] + 1, e->n.n_y[j]);
		ft_animation(e, "./sprites/enm/enm_sx", e->n.n_x[j], e->n.n_y[j]);
		if (i == 2)
		{
			e->index = ++i;
			e->n.n_x[j] -= 1;
			ft_animation_b(e, "./sprites/enm/enm_sx", e->n.n_x[j], e->n.n_y[j]);
		}
	}
	else if (e->n.x_m[j] == 1)
	{
		if (i == 4 && ft_check_cond(e, e->n.n_y[j], e->n.n_x[j] - 1, j) == 0)
			ft_put_floor(e, e->n.n_x[j] - 1, e->n.n_y[j]);
		ft_animation(e, "./sprites/enm/enm_dx", e->n.n_x[j], e->n.n_y[j]);
		if (i == 2)
		{
			e->index = ++i;
			e->n.n_x[j] += 1;
			ft_animation_b(e, "./sprites/enm/enm_dx", e->n.n_x[j], e->n.n_y[j]);
		}
	}
	return (0);
}

int	ft_enemy_move(t_env *e, int j, int i)
{
	if (e->n.y_m[j] == -1)
	{
		if (i == 4 && ft_check_cond(e, e->n.n_y[j] + 1, e->n.n_x[j], j) == 0)
			ft_put_floor(e, e->n.n_x[j], e->n.n_y[j] + 1);
		ft_animation(e, "./sprites/enm/enm_back", e->n.n_x[j], e->n.n_y[j]);
		if (i == 2)
		{
			e->index = ++i;
			e->n.n_y[j] -= 1;
			ft_animation_b(e, "./sprites/enm/enm_back", e->n.n_x[j], e->n.n_y[j]);
		}
	}
	else if (e->n.y_m[j] == 1)
	{
		if (i == 4 && ft_check_cond(e, e->n.n_y[j] - 1, e->n.n_x[j], j) == 0)
			ft_put_floor(e, e->n.n_x[j], e->n.n_y[j] - 1);
		ft_animation(e, "./sprites/enm/enm_fnt", e->n.n_x[j], e->n.n_y[j]);
		if (i == 2)
		{
			e->index = ++i;
			e->n.n_y[j] += 1;
			ft_animation_b(e, "./sprites/enm/enm_fnt", e->n.n_x[j], e->n.n_y[j]);
		}
	}
	else
		ft_enemy_move_b(e, j, i);
	return (0);
}

int	ft_enemy_dir(t_env *e, int j, int i)
{
	if (e->n.y_m[j] == -1)
	{
		if (i == 1 && ft_check_cond(e, e->n.n_y[j] - 1, e->n.n_x[j], j) == 1)
			return (1);
		ft_enemy_move(e, j, i);
		return (0);
	}
	else if (e->n.y_m[j] == 1)
	{
		if (i == 1 && ft_check_cond(e, e->n.n_y[j] + 1, e->n.n_x[j], j) == 1)
			return (1);
		ft_enemy_move(e, j, i);
		return (0);
	}
	else if (e->n.x_m[j] == -1)
	{
		if (i == 1 && ft_check_cond(e, e->n.n_y[j], e->n.n_x[j] - 1, j) == 1)
			return (1);
		ft_enemy_move(e, j, i);
		return (0);
	}
	else if (e->n.x_m[j] == 1)
	{
		if (i == 1 && ft_check_cond(e, e->n.n_y[j], e->n.n_x[j] + 1, j) == 1)
			return (1);
		ft_enemy_move(e, j, i);
		return (0);
	}
	return (1);
}

int	ft_enemy_animation(t_env *e)
{
	int			j;
	static int	i;

	j = -1;
	if (i > 4)
		i = 0;
	if (ft_delay(&e->d4, 700) == 1)
		return (0);
	while (++j < e->n.n_c)
	{
		e->index = i;
		if (i == 1)
			if (ft_check_attack(e, j) == 1)
				e->n.patr[j] = 2;
		if (e->n.patr[j] == 1)
		{
			if (i == 1)
				ft_check_enemy_moves(e, j);
			if (ft_enemy_dir(e, j, i) == 1)
			{
				ft_check_enemy_moves_b(e, j);
				if (ft_enemy_dir(e, j, i) == 1)
					e->n.patr[j] = 0;
			}
		}
	}
	i++;
	return (0);
}

int	ft_enemy_patrol(t_env *e)
{
	int			j;
	static int	i;

	j = -1;
	if (i > 4)
		i = 0;
	if (ft_delay(&e->d5, 2000) == 1)
		return (0);
	while (++j < e->n.n_c)
	{
		e->index = i;
		ft_check_pg(e, j, i);
		if (e->n.patr[j] == -1 || e->n.patr[j] == 0)
		{
			if (i == 0 && e->n.patr[j] == 0)
			{
				ft_check_enemy_patr(e, j);
				e->n.patr[j] = -1;
			}
			if (ft_enemy_dir(e, j, i) == 1)
				ft_check_enemy_patr(e, j);
		}
	}
	i++;
	return (0);
}
