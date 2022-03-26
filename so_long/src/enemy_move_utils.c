/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:40:20 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/24 15:46:49 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_cond(t_env *e, int y, int x)
{
	if (e->w.m[y][x] == '1' || e->w.m[y][x] == 'E' || e->w.m[y][x] == 'C'
		|| e->w.m[y][x] == 'N')
		return (1);
	return (0);
}

int	ft_check_attack(t_env *e, int j)
{
	if (e->w.m[e->n.n_y[j] - 1][e->n.n_x[j]] == 'P')
	{
		e->n.y_m[j] = -1;
		e->n.x_m[j] = 0;
		return (1);
	}
	else if (e->w.m[e->n.n_y[j] + 1][e->n.n_x[j]] == 'P')
	{
		e->n.y_m[j] = 1;
		e->n.x_m[j] = 0;
		return (1);
	}
	else if (e->w.m[e->n.n_y[j]][e->n.n_x[j] - 1] == 'P')
	{
		e->n.x_m[j] = -1;
		e->n.y_m[j] = 0;
		return (1);
	}
	else if (e->w.m[e->n.n_y[j]][e->n.n_x[j] + 1] == 'P')
	{
		e->n.x_m[j] = 1;
		e->n.y_m[j] = 0;
		return (1);
	}
	return (0);
}

int	ft_check_pg(t_env *e, int j)
{
	int	x;
	int	y;
	int	x1;
	int	y1;

	if (e->n.i[j] == 0)
	{
		x = e->p.pg_x - e->n.n_x[j];
		y = e->p.pg_y - e->n.n_y[j];
		x1 = x;
		y1 = y;
		if (x1 < 0)
			x1 *= -1;
		if (y1 < 0)
			y1 *= -1;
		if (x == 0 && y == 0)
			ft_you_died(e);
		if (x1 < 5 && y1 < 5)
			e->n.patr[j] = 1;
	}
	return (0);
}

int	ft_check_enemy_patr(t_env *e, int j)
{
	if (ft_cond(e, e->n.n_y[j] - 1, e->n.n_x[j]) == 0)
	{
		e->n.y_m[j] = -1;
		e->n.x_m[j] = 0;
	}
	else if (ft_cond(e, e->n.n_y[j], e->n.n_x[j] - 1) == 0)
	{
		e->n.x_m[j] = -1;
		e->n.y_m[j] = 0;
	}
	else if (ft_cond(e, e->n.n_y[j], e->n.n_x[j] + 1) == 0)
	{
		e->n.x_m[j] = 1;
		e->n.y_m[j] = 0;
	}
	else if (ft_cond(e, e->n.n_y[j] + 1, e->n.n_x[j]) == 0)
	{
		e->n.y_m[j] = 1;
		e->n.x_m[j] = 0;
	}
	return (0);
}
