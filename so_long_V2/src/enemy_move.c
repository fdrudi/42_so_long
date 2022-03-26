/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:26:26 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/26 12:42:28 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_enemy_animation_help(t_env *e, int j)
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
	return ;
}

int	ft_enemy_animation(t_env *e)
{
	int	j;

	j = 0;
	if (ft_delay(&e->d4, 700) == 1)
		return (0);
	while (j < e->n.n_c)
	{
		if (e->n.i[j] > 4 && e->n.patr[j] == 1)
			e->n.i[j] = 0;
		if (e->w.m[e->n.n_y[j]][e->n.n_x[j]] == 'P' && e->p.pg_c == 5)
			ft_you_died(e);
		if (e->n.i[j] == 1 && e->n.patr[j] == 1)
		{
			if (ft_check_attack(e, j) == 1)
			{
				e->n.i[j] = 0;
				e->n.patr[j] = 2;
			}
		}
		if (e->n.patr[j] == 1)
			ft_enemy_animation_help(e, j);
		j++;
	}
	return (0);
}

void	ft_enemy_patrol_help(t_env *e, int j)
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
	return ;
}

int	ft_enemy_patrol(t_env *e)
{
	int	j;

	j = 0;
	if (ft_delay(&e->d5, 2000) == 1)
		return (0);
	while (j < e->n.n_c)
	{
		if (e->n.i[j] > 4 && (e->n.patr[j] == -1 || e->n.patr[j] == 0))
			e->n.i[j] = 0;
		if (e->w.m[e->n.n_y[j]][e->n.n_x[j]] == 'P' && e->p.pg_c == 5)
			ft_you_died(e);
		ft_check_pg(e, j);
		if (e->n.patr[j] == -1 || e->n.patr[j] == 0)
			ft_enemy_patrol_help(e, j);
		j++;
	}
	return (0);
}
