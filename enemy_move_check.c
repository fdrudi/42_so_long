/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:43:32 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/20 18:09:21 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_enemy_help(t_env *e, int i, int j, int a)
{
	if (a < 0)
	{
		if (i < 0 && ft_check_cond(e, e->n.n_y[j], e->n.n_x[j] - 1) == 0)
			e->n.x_m[j] = -1;
		else if (i > 0 && ft_check_cond(e, e->n.n_y[j], e->n.n_x[j] + 1) == 0)
			e->n.x_m[j] = 1;
		else
			e->n.x_m[j] = 0;
		e->n.y_m[j] = 0;
	}
	else if (a > 0)
	{
		if (i < 0 && ft_check_cond(e, e->n.n_y[j] - 1, e->n.n_x[j]) == 0)
			e->n.y_m[j] = -1;
		else if (i > 0 && ft_check_cond(e, e->n.n_y[j] + 1, e->n.n_x[j]) == 0)
			e->n.y_m[j] = 1;
		else
			e->n.y_m[j] = 0;
		e->n.x_m[j] = 0;
	}
	return (0);
}

int	ft_check_enemy_help_b(t_env *e, int j, int a)
{
	if (a < 0)
	{
		if (ft_check_cond(e, e->n.n_y[j] - 1, e->n.n_x[j]) == 0)
			e->n.y_m[j] = -1;
		else if (ft_check_cond(e, e->n.n_y[j] + 1, e->n.n_x[j]) == 0)
			e->n.y_m[j] = 1;
		else
			e->n.y_m[j] = 0;
		e->n.x_m[j] = 0;
	}
	else if (a > 0)
	{
		if (ft_check_cond(e, e->n.n_y[j], e->n.n_x[j] - 1) == 0)
			e->n.x_m[j] = -1;
		else if (ft_check_cond(e, e->n.n_y[j], e->n.n_x[j] + 1) == 0)
			e->n.x_m[j] = 1;
		else
			e->n.x_m[j] = 0;
		e->n.y_m[j] = 0;
	}
	return (0);
}

int	ft_check_enemy_moves(t_env *e, int j)
{
	int	x;
	int	y;
	int	x1;
	int	y1;

	x = e->pg_x - e->n.n_x[j];
	y = e->pg_y - e->n.n_y[j];
	x1 = x;
	y1 = y;
	if (x1 < 0)
		x1 *= -1;
	if (y1 < 0)
		y1 *= -1;
	if (x == 0 && y == 0)
	{
		e->end = -1;
		// ft_close_win(e);
	}
	if (x1 > y1)
		ft_check_enemy_help(e, x, j, -1);
	else if (y1 > x1)
		ft_check_enemy_help(e, y, j, 1);
	return (0);
}

int	ft_check_enemy_moves_b(t_env *e, int j)
{
	int	x;
	int	y;
	int	x1;
	int	y1;

	x = e->pg_x - e->n.n_x[j];
	y = e->pg_y - e->n.n_y[j];
	x1 = x;
	y1 = y;
	if (x1 < 0)
		x1 *= -1;
	if (y1 < 0)
		y1 *= -1;
	if (x == 0 && y == 0)
	{
		e->end = -1;
		// ft_close_win(e);
	}
	if (x1 < y1 && x != 0)
		ft_check_enemy_help(e, x, j, -1);
	else if (y1 < x1 && y != 0)
		ft_check_enemy_help(e, y, j, 1);
	else if (y == 0)
		ft_check_enemy_help_b(e, j, -1);
	else if (x == 0)
		ft_check_enemy_help_b(e, j, 1);
	return (0);
}
