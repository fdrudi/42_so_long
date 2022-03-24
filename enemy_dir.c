/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:06:47 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/24 13:06:58 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_enemy_dir_help(t_env *e, int j)
{
	if (e->n.x_m[j] == -1)
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
	else if (ft_enemy_dir_help(e, j) == 0)
		return (0);
	return (1);
}
