/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:40:20 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/19 18:39:12 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_attack(t_env *e, int j)
{
	if (e->n.n_y[j] - 1 == e->pg_y && e->n.n_x[j] == e->pg_x)
	{
		e->n.y_m[j] = -1;
		e->n.x_m[j] = 0;
		return (1);
	}
	else if (e->n.n_y[j] + 1 == e->pg_y && e->n.n_x[j] == e->pg_x)
	{
		e->n.y_m[j] = 1;
		e->n.x_m[j] = 0;
		return (1);
	}
	else if (e->n.n_y[j] == e->pg_y && e->n.n_x[j] - 1 == e->pg_x)
	{
		e->n.x_m[j] = -1;
		e->n.y_m[j] = 0;
		return (1);
	}
	else if (e->n.n_y[j] == e->pg_y && e->n.n_x[j] + 1 == e->pg_x)
	{
		e->n.x_m[j] = 1;
		e->n.y_m[j] = 0;
		return (1);
	}
	return (0);
}

int	ft_check_cond(t_env *e, int y, int x, int j)
{
	int	i;

	i = -1;
	if (e->w.m[y][x] == '1' || e->w.m[y][x] == 'E' || e->w.m[y][x] == 'C')
		return (1);
	else
	{
		while (++i < e->n.n_c)
			if (x == e->n.n_x[j] && y == e->n.n_y[j])
				return (1);
	}
	// if (ft_check_attack(e, j) == 1)
	// {
	// 	e->n.patr[j] = 2;
	// 	return (1);
	// }
	return (0);
}

int	ft_check_pg(t_env *e, int j, int i)
{
	int	x;
	int	y;
	int	x1;
	int	y1;

	if (i == 0)
	{
		x = e->pg_x - e->n.n_x[j];
		y = e->pg_y - e->n.n_y[j];
		x1 = x;
		y1 = y;
		if (x1 < 0)
			x1 *= -1;
		if (y1 < 0)
			y1 *= -1;
		// if (x == 0 && y == 0)
		// {
		// 	e->end = -1;
		// 	// ft_close_win(e);
		// }
		if (x1 < 5 && y1 < 5)
			e->n.patr[j] = 1;
	}
	return (0);
}

int	ft_check_enemy_patr(t_env *e, int j)
{
	if (ft_check_cond(e, e->n.n_y[j] - 1, e->n.n_x[j], j) == 0)
	{
		e->n.y_m[j] = -1;
		e->n.x_m[j] = 0;
	}
	else if (ft_check_cond(e, e->n.n_y[j] + 1, e->n.n_x[j], j) == 0)
	{
		e->n.y_m[j] = 1;
		e->n.x_m[j] = 0;
	}
	else if (ft_check_cond(e, e->n.n_y[j], e->n.n_x[j] - 1, j) == 0)
	{
		e->n.x_m[j] = -1;
		e->n.y_m[j] = 0;
	}
	else if (ft_check_cond(e, e->n.n_y[j], e->n.n_x[j] + 1, j) == 0)
	{
		e->n.x_m[j] = 1;
		e->n.y_m[j] = 0;
	}
	return (0);
}
