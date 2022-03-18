/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:26:26 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/18 16:27:40 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_enemy_moves(t_vars *vars, int j)
{
	int	x;
	int	y;
	int	x1;
	int	y1;

	x = vars->pg_x - vars->n.enm_x[j];
	y = vars->pg_y - vars->n.enm_y[j];
	x1 = x;
	y1 = y;
	if (x1 < 0)
		x1 *= -1;
	if (y1 < 0)
		y1 *= -1;
	if (x1 > y1)
	{
		if (x < 0)
			vars->n.x_move[j] = -1;
		else
			vars->n.x_move[j] = 1;
		vars->n.y_move[j] = 0;
	}
	else
	{
		if (y < 0)
			vars->n.y_move[j] = -1;
		else
			vars->n.y_move[j] = 1;
		vars->n.x_move[j] = 0;
	}
	return (0);
}

int	ft_check_enemy_moves_b(t_vars *vars, int j)
{
	int	x;
	int	y;
	int	x1;
	int	y1;

	x = vars->pg_x - vars->n.enm_x[j];
	y = vars->pg_y - vars->n.enm_y[j];
	x1 = x;
	y1 = y;
	if (x1 < 0)
		x1 *= -1;
	if (y1 < 0)
		y1 *= -1;
	if (x1 < y1 && x != 0)
	{
		if (x < 0)
			vars->n.x_move[j] = -1;
		else
			vars->n.x_move[j] = 1;
		vars->n.y_move[j] = 0;
	}
	else if (y1 < x1 && y != 0)
	{
		if (y < 0)
			vars->n.y_move[j] = -1;
		else
			vars->n.y_move[j] = 1;
		vars->n.x_move[j] = 0;
	}
	return (0);
}

int	ft_check_enemy_patr(t_vars *vars, int j)
{
	if (vars->w.map[vars->n.enm_y[j] - 1][vars->n.enm_x[j]] != '1')
	{
		vars->n.y_move[j] = -1;
		vars->n.x_move[j] = 0;
	}
	else if (vars->w.map[vars->n.enm_y[j] + 1][vars->n.enm_x[j]] != '1')
	{
		vars->n.y_move[j] = 1;
		vars->n.x_move[j] = 0;
	}
	else if (vars->w.map[vars->n.enm_y[j]][vars->n.enm_x[j] - 1] != '1')
	{
		vars->n.x_move[j] = -1;
		vars->n.y_move[j] = 0;
	}
	else if (vars->w.map[vars->n.enm_y[j]][vars->n.enm_x[j] + 1] != '1')
	{
		vars->n.x_move[j] = 1;
		vars->n.y_move[j] = 0;
	}
	return (0);
}

int	ft_enemy_move(t_vars *vars, int j, int i)
{
	if (vars->n.y_move[j] == -1)
	{
		if (i == 4 && vars->w.map[vars->n.enm_y[j] + 1][vars->n.enm_x[j]] != '1')
			ft_put_floor(vars, vars->n.enm_x[j], vars->n.enm_y[j] + 1);
		ft_animation(vars, "./sprites/enemy/enemy_back", vars->n.enm_x[j], vars->n.enm_y[j]);
		if (i == 2)
		{
			vars->index = ++i;
			vars->n.enm_y[j] -= 1;
			ft_animation(vars, "./sprites/enemy/enemy_back", vars->n.enm_x[j], vars->n.enm_y[j]);
		}
	}
	if (vars->n.y_move[j] == 1)
	{
		if (i == 4 && vars->w.map[vars->n.enm_y[j] - 1][vars->n.enm_x[j]] != '1')
			ft_put_floor(vars, vars->n.enm_x[j], vars->n.enm_y[j] - 1);
		ft_animation(vars, "./sprites/enemy/enemy_front", vars->n.enm_x[j], vars->n.enm_y[j]);
		if (i == 2)
		{
			vars->index = ++i;
			vars->n.enm_y[j] += 1;
			ft_animation(vars, "./sprites/enemy/enemy_front", vars->n.enm_x[j], vars->n.enm_y[j]);
		}
	}
	if (vars->n.x_move[j] == -1)
	{
		if (i == 4 && vars->n.x_move[j] == -1)
			ft_put_floor(vars, vars->n.enm_x[j] + 1, vars->n.enm_y[j]);
		ft_animation(vars, "./sprites/enemy/enemy_side_sx", vars->n.enm_x[j], vars->n.enm_y[j]);
		if (i == 2)
		{
			vars->index = ++i;
			vars->n.enm_x[j] -= 1;
			ft_animation(vars, "./sprites/enemy/enemy_side_sx", vars->n.enm_x[j], vars->n.enm_y[j]);
		}
	}
	if (vars->n.x_move[j] == 1)
	{
		if (i == 4 && vars->w.map[vars->n.enm_y[j]][vars->n.enm_x[j] - 1] != '1')
			ft_put_floor(vars, vars->n.enm_x[j] - 1, vars->n.enm_y[j]);
		ft_animation(vars, "./sprites/enemy/enemy_side_dx", vars->n.enm_x[j], vars->n.enm_y[j]);
		if (i == 2)
		{
			vars->index = ++i;
			vars->n.enm_x[j] += 1;
			ft_animation(vars, "./sprites/enemy/enemy_side_dx", vars->n.enm_x[j], vars->n.enm_y[j]);
		}
	}
	return (0);
}

int	ft_enemy_dir(t_vars *vars, int j, int i)
{
	if (vars->n.y_move[j] == -1)
	{
		if (vars->w.map[vars->n.enm_y[j] - 1][vars->n.enm_x[j]] == '1' && i == 0)
			return (1);
		ft_enemy_move(vars, j, i);
	}
	else if (vars->n.y_move[j] == 1)
	{
		if (vars->w.map[vars->n.enm_y[j] + 1][vars->n.enm_x[j]] == '1' && i == 0)
			return (1);
		ft_enemy_move(vars, j, i);
	}
	else if (vars->n.x_move[j] == -1)
	{
		if (vars->w.map[vars->n.enm_y[j]][vars->n.enm_x[j] - 1] == '1' && i == 0)
			return (1);
		ft_enemy_move(vars, j, i);
	}
	else if (vars->n.x_move[j] == 1)
	{
		if (vars->w.map[vars->n.enm_y[j]][vars->n.enm_x[j] + 1] == '1' && i == 0)
			return (1);
		ft_enemy_move(vars, j, i);
	}
	return (0);
}

int	ft_enemy_animation(t_vars *vars)
{
	int			j;
	static int	i;

	j = 0;
	if (i > 4)
		i = 0;
	if (ft_delay(&vars->delay4, 2000) == 1)
		return (0);
	vars->index = i;
	while (j < vars->n.enm_count)
	{
		if (vars->n.patr[j] == 1)
		{
			if (i == 0)
				ft_check_enemy_moves(vars, j);
			if (ft_enemy_dir(vars, j, i) == 1)
			{
				ft_check_enemy_moves_b(vars, j);
				if (ft_enemy_dir(vars, j, i) == 1)
					vars->n.patr[j] = -1;
			}
		}
		j++;
	}
	i++;
	return (0);
}

int	ft_enemy_patrol(t_vars *vars)
{
	int			j;
	static int	i;
	static int	x;

	j = 0;
	if (i > 4)
		i = 0;
	if (ft_delay(&vars->delay5, 2000) == 1)
		return (0);
	vars->index = i;
	while (j < vars->n.enm_count)
	{
		if (vars->n.patr[j] == -1)
		{
			if (i == 0 && x == 0)
			{
				ft_check_enemy_patr(vars, j);
				x = 1;
			}
			if (ft_enemy_dir(vars, j, i) == 1)
				ft_check_enemy_patr(vars, j);
		}
		j++;
	}
	i++;
	return (0);
}
