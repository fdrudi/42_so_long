/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:26:26 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/18 19:37:11 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		if (x1 < 4 && y1 < 4)
			e->n.patr[j] = 1;
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
	if (x1 > y1)
	{
		if (x < 0)
			e->n.x_m[j] = -1;
		else
			e->n.x_m[j] = 1;
		e->n.y_m[j] = 0;
	}
	else
	{
		if (y < 0)
			e->n.y_m[j] = -1;
		else
			e->n.y_m[j] = 1;
		e->n.x_m[j] = 0;
	}
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
	if (x1 < y1 && x != 0)
	{
		if (x < 0)
			e->n.x_m[j] = -1;
		else
			e->n.x_m[j] = 1;
		e->n.y_m[j] = 0;
	}
	else if (y1 < x1 && y != 0)
	{
		if (y < 0)
			e->n.y_m[j] = -1;
		else
			e->n.y_m[j] = 1;
		e->n.x_m[j] = 0;
	}
	else if (y == 0)
	{
		if (e->w.m[e->n.n_y[j] - 1][e->n.n_x[j]] != '1')
			e->n.y_m[j] = -1;
		else if (e->w.m[e->n.n_y[j] + 1][e->n.n_x[j]] != '1')
				e->n.y_m[j] = 1;
		e->n.x_m[j] = 0;

	}
	else if (x == 0)
	{
		if (e->w.m[e->n.n_y[j]][e->n.n_x[j] - 1] != '1')
			e->n.x_m[j] = -1;
		else if (e->w.m[e->n.n_y[j]][e->n.n_x[j] + 1] != '1')
			e->n.x_m[j] = -1;
		e->n.y_m[j] = 0;
	}
	return (0);
}

int	ft_check_enemy_patr(t_env *e, int j)
{
	if (e->w.m[e->n.n_y[j] - 1][e->n.n_x[j]] != '1')
	{
		e->n.y_m[j] = -1;
		e->n.x_m[j] = 0;
	}
	else if (e->w.m[e->n.n_y[j] + 1][e->n.n_x[j]] != '1')
	{
		e->n.y_m[j] = 1;
		e->n.x_m[j] = 0;
	}
	else if (e->w.m[e->n.n_y[j]][e->n.n_x[j] - 1] != '1')
	{
		e->n.x_m[j] = -1;
		e->n.y_m[j] = 0;
	}
	else if (e->w.m[e->n.n_y[j]][e->n.n_x[j] + 1] != '1')
	{
		e->n.x_m[j] = 1;
		e->n.y_m[j] = 0;
	}
	return (0);
}

int	ft_enemy_move(t_env *e, int j, int i)
{
	if (e->n.y_m[j] == -1)
	{
		if (i == 4 && e->w.m[e->n.n_y[j] + 1][e->n.n_x[j]] != '1')
			ft_put_floor(e, e->n.n_x[j], e->n.n_y[j] + 1);
		ft_animation(e, "./sprites/enemy/enemy_back", e->n.n_x[j], e->n.n_y[j]);
		if (i == 2)
		{
			e->index = ++i;
			e->n.n_y[j] -= 1;
			ft_animation(e, "./sprites/enemy/enemy_back", e->n.n_x[j], e->n.n_y[j]);
		}
	}
	if (e->n.y_m[j] == 1)
	{
		if (i == 4 && e->w.m[e->n.n_y[j] - 1][e->n.n_x[j]] != '1')
			ft_put_floor(e, e->n.n_x[j], e->n.n_y[j] - 1);
		ft_animation(e, "./sprites/enemy/enemy_front", e->n.n_x[j], e->n.n_y[j]);
		if (i == 2)
		{
			e->index = ++i;
			e->n.n_y[j] += 1;
			ft_animation(e, "./sprites/enemy/enemy_front", e->n.n_x[j], e->n.n_y[j]);
		}
	}
	if (e->n.x_m[j] == -1)
	{
		if (i == 4 && e->n.x_m[j] == -1)
			ft_put_floor(e, e->n.n_x[j] + 1, e->n.n_y[j]);
		ft_animation(e, "./sprites/enemy/enemy_side_sx", e->n.n_x[j], e->n.n_y[j]);
		if (i == 2)
		{
			e->index = ++i;
			e->n.n_x[j] -= 1;
			ft_animation(e, "./sprites/enemy/enemy_side_sx", e->n.n_x[j], e->n.n_y[j]);
		}
	}
	if (e->n.x_m[j] == 1)
	{
		if (i == 4 && e->w.m[e->n.n_y[j]][e->n.n_x[j] - 1] != '1')
			ft_put_floor(e, e->n.n_x[j] - 1, e->n.n_y[j]);
		ft_animation(e, "./sprites/enemy/enemy_side_dx", e->n.n_x[j], e->n.n_y[j]);
		if (i == 2)
		{
			e->index = ++i;
			e->n.n_x[j] += 1;
			ft_animation(e, "./sprites/enemy/enemy_side_dx", e->n.n_x[j], e->n.n_y[j]);
		}
	}
	return (0);
}

int	ft_enemy_dir(t_env *e, int j, int i)
{
	if (e->n.y_m[j] == -1)
	{
		if (e->w.m[e->n.n_y[j] - 1][e->n.n_x[j]] == '1' && i == 1)
			return (1);
		ft_enemy_move(e, j, i);
	}
	else if (e->n.y_m[j] == 1)
	{
		if (e->w.m[e->n.n_y[j] + 1][e->n.n_x[j]] == '1' && i == 1)
			return (1);
		ft_enemy_move(e, j, i);
	}
	else if (e->n.x_m[j] == -1)
	{
		if (e->w.m[e->n.n_y[j]][e->n.n_x[j] - 1] == '1' && i == 1)
			return (1);
		ft_enemy_move(e, j, i);
	}
	else if (e->n.x_m[j] == 1)
	{
		if (e->w.m[e->n.n_y[j]][e->n.n_x[j] + 1] == '1' && i == 1)
			return (1);
		ft_enemy_move(e, j, i);
	}
	return (0);
}

int	ft_enemy_animation(t_env *e)
{
	int			j;
	static int	i;

	j = 0;
	if (i > 4)
		i = 0;
	if (ft_delay(&e->d4, 1000) == 1)
		return (0);
	while (j < e->n.n_c)
	{
		e->index = i;
		if (e->n.patr[j] == 1)
		{
			if (i == 1)
				ft_check_enemy_moves(e, j);
			if (ft_enemy_dir(e, j, i) == 1)
			{
				ft_check_enemy_moves_b(e, j);
				if (ft_enemy_dir(e, j, i) == 1)
					e->n.patr[j] = -1;
			}
		}
		j++;
	}
	i++;
	return (0);
}

int	ft_enemy_patrol(t_env *e)
{
	int			j;
	static int	i;
	static int	x;

	j = 0;
	if (i > 4)
		i = 0;
	if (ft_delay(&e->d5, 2000) == 1)
		return (0);
	while (j < e->n.n_c)
	{
		e->index = i;
		ft_check_pg(e, j, i);
		if (e->n.patr[j] == -1)
		{
			if (i == 0 && x == 0)
			{
				ft_check_enemy_patr(e, j);
				x = 1;
			}
			if (ft_enemy_dir(e, j, i) == 1)
				ft_check_enemy_patr(e, j);
		}
		j++;
	}
	i++;
	return (0);
}
