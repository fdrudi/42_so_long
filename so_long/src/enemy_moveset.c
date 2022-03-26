/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moveset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:22:54 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/24 15:46:58 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_enemy_move_a(t_env *e, int j)
{
	if (e->n.x_m[j] == -1)
	{
		if (e->n.i[j] == 4 && ft_cond(e, e->n.n_y[j], e->n.n_x[j] + 1) == 0)
			ft_put_floor(e, e->n.n_x[j] + 1, e->n.n_y[j]);
		ft_animate(e, "./spr/enm/enm_sx", e->n.n_x[j], e->n.n_y[j]);
		if (e->n.i[j] == 2 && ft_cond(e, e->n.n_y[j], e->n.n_x[j] - 1) == 0)
		{
			e->w.m[e->n.n_y[j]][e->n.n_x[j]] = '0';
			e->n.i[j] += 1;
			e->index = e->n.i[j];
			e->n.n_x[j] -= 1;
			e->w.m[e->n.n_y[j]][e->n.n_x[j]] = 'N';
			ft_animate_b(e, "./spr/enm/enm_sx", e->n.n_x[j], e->n.n_y[j]);
		}
	}
	return (0);
}

int	ft_enemy_move_d(t_env *e, int j)
{
	if (e->n.x_m[j] == 1)
	{
		if (e->n.i[j] == 4 && ft_cond(e, e->n.n_y[j], e->n.n_x[j] - 1) == 0)
			ft_put_floor(e, e->n.n_x[j] - 1, e->n.n_y[j]);
		ft_animate(e, "./spr/enm/enm_dx", e->n.n_x[j], e->n.n_y[j]);
		if (e->n.i[j] == 2 && ft_cond(e, e->n.n_y[j], e->n.n_x[j] + 1) == 0)
		{
			e->w.m[e->n.n_y[j]][e->n.n_x[j]] = '0';
			e->n.i[j] += 1;
			e->index = e->n.i[j];
			e->n.n_x[j] += 1;
			e->w.m[e->n.n_y[j]][e->n.n_x[j]] = 'N';
			ft_animate_b(e, "./spr/enm/enm_dx", e->n.n_x[j], e->n.n_y[j]);
		}
	}
	return (0);
}

int	ft_enemy_move_w(t_env *e, int j)
{
	if (e->n.y_m[j] == -1)
	{
		if (e->n.i[j] == 4 && ft_cond(e, e->n.n_y[j] + 1, e->n.n_x[j]) == 0)
			ft_put_floor(e, e->n.n_x[j], e->n.n_y[j] + 1);
		ft_animate(e, "./spr/enm/enm_back", e->n.n_x[j], e->n.n_y[j]);
		if (e->n.i[j] == 2 && ft_cond(e, e->n.n_y[j] - 1, e->n.n_x[j]) == 0)
		{
			e->w.m[e->n.n_y[j]][e->n.n_x[j]] = '0';
			e->n.i[j] += 1;
			e->index = e->n.i[j];
			e->n.n_y[j] -= 1;
			e->w.m[e->n.n_y[j]][e->n.n_x[j]] = 'N';
			ft_animate_b(e, "./spr/enm/enm_back", e->n.n_x[j], e->n.n_y[j]);
		}
	}
	return (0);
}

int	ft_enemy_move_s(t_env *e, int j)
{
	if (e->n.y_m[j] == 1)
	{
		if (e->n.i[j] == 4 && ft_cond(e, e->n.n_y[j] - 1, e->n.n_x[j]) == 0)
			ft_put_floor(e, e->n.n_x[j], e->n.n_y[j] - 1);
		ft_animate(e, "./spr/enm/enm_fnt", e->n.n_x[j], e->n.n_y[j]);
		if (e->n.i[j] == 2 && ft_cond(e, e->n.n_y[j] + 1, e->n.n_x[j]) == 0)
		{
			e->w.m[e->n.n_y[j]][e->n.n_x[j]] = '0';
			e->n.i[j] += 1;
			e->index = e->n.i[j];
			e->n.n_y[j] += 1;
			e->w.m[e->n.n_y[j]][e->n.n_x[j]] = 'N';
			ft_animate_b(e, "./spr/enm/enm_fnt", e->n.n_x[j], e->n.n_y[j]);
		}
	}
	return (0);
}
