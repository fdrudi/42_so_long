/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:26:26 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/21 17:42:04 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_enemy_dir(t_env *e, int j)
{
	if (e->n.y_m[j] == -1)
	{
		if (e->n.i[j] == 2 && ft_cond(e, e->n.n_y[j] - 1, e->n.n_x[j]) == 1)
			return (1);
		ft_enemy_move_w(e, j);
		return (0);
	}
	else if (e->n.y_m[j] == 1)
	{
		if (e->n.i[j] == 2 && ft_cond(e, e->n.n_y[j] + 1, e->n.n_x[j]) == 1)
			return (1);
		ft_enemy_move_s(e, j);
		return (0);
	}
	else if (e->n.x_m[j] == -1)
	{
		if (e->n.i[j] == 2 && ft_cond(e, e->n.n_y[j], e->n.n_x[j] - 1) == 1)
			return (1);
		ft_enemy_move_a(e, j);
		return (0);
	}
	else if (e->n.x_m[j] == 1)
	{
		if (e->n.i[j] == 2 && ft_cond(e, e->n.n_y[j], e->n.n_x[j] + 1) == 1)
			return (1);
		ft_enemy_move_d(e, j);
		return (0);
	}
	return (1);
}

int	ft_enemy_animation(t_env *e)
{
	int	j;

	j = 0;
	if (ft_delay(&e->d4, 700) == 1)
		return (1);
	while (j < e->n.n_c)
	{
		if (e->n.i[j] > 4 && e->n.patr[j] == 1)
			e->n.i[j] = 0;
		e->index = e->n.i[j];
		if (e->n.i[j] == 1 && e->n.patr[j] == 1)
		{
			if (ft_check_attack(e, j) == 1)
			{
				e->n.i[j] = 0;
				e->n.patr[j] = 2;
			}
		}
		if (e->n.patr[j] == 1)
		{
			if (e->n.i[j] == 1)
				ft_check_enemy_moves(e, j);
			if (ft_enemy_dir(e, j) == 1 && e->n.i[j] == 2)
			{
				ft_check_enemy_moves_b(e, j);
				if (ft_enemy_dir(e, j) == 1)
					e->n.patr[j] = 0;
			}
			e->n.i[j] += 1;
		}
		j++;
	}
	return (0);
}

int	ft_enemy_patrol(t_env *e)
{
	int	j;

	j = 0;
	if (ft_delay(&e->d5, 2000) == 1)
		return (1);
	while (j < e->n.n_c)
	{
		if (e->n.i[j] > 4 && (e->n.patr[j] == -1 || e->n.patr[j] == 0))
			e->n.i[j] = 0;
		e->index = e->n.i[j];
		ft_check_pg(e, j);
		if (e->n.patr[j] == -1 || e->n.patr[j] == 0)
		{
			if (e->n.i[j] == 0 && e->n.patr[j] == 0)
			{
				ft_check_enemy_patr(e, j);
				e->n.patr[j] = -1;
			}
			if (ft_enemy_dir(e, j) == 1 && e->n.i[j] == 2)
			{
				ft_check_enemy_patr(e, j);
				e->n.i[j] -= 1;
			}
			else
				e->n.i[j] += 1;
		}
		j++;
	}
	return (0);
}
