/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_attack_moveset.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:39:57 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/24 12:27:55 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_enemy_move_atk_a(t_env *e, int j, int y, int x)
{
	if (e->n.x_m[j] == -1)
	{
		ft_animate(e, "./spr/enm/atk/enm_atk_sx", x + 1, y);
		if (e->n.i[j] == 5)
		{
			ft_put_floor(e, x, y);
			if (e->w.m[y][x] == 'P')
				ft_you_died(e);
		}
		else if (e->n.i[j] == 1)
		{
			e->n.i[j] += 1;
			e->index = e->n.i[j];
			ft_animate_b(e, "./spr/enm/atk/enm_atk_sx", x, y);
		}
		else if (e->n.i[j] == 3)
		{
			ft_put_floor(e, x, y);
			e->n.i[j] += 1;
			e->index = e->n.i[j];
			ft_animate(e, "./spr/enm/atk/enm_atk_sx", x, y);
		}
		return ;
	}
	return ;
}

void	ft_enemy_move_atk_d(t_env *e, int j, int y, int x)
{
	if (e->n.x_m[j] == 1)
	{
		ft_animate(e, "./spr/enm/atk/enm_atk_dx", x - 1, y);
		if (e->n.i[j] == 5)
		{
			ft_put_floor(e, x, y);
			if (e->w.m[y][x] == 'P')
				ft_you_died(e);
		}
		else if (e->n.i[j] == 1)
		{
			e->n.i[j] += 1;
			e->index = e->n.i[j];
			ft_animate_b(e, "./spr/enm/atk/enm_atk_dx", x, y);
		}
		else if (e->n.i[j] == 3)
		{
			ft_put_floor(e, x, y);
			e->n.i[j] += 1;
			e->index = e->n.i[j];
			ft_animate(e, "./spr/enm/atk/enm_atk_dx", x, y);
		}
		return ;
	}
	return ;
}

void	ft_enemy_move_atk_w(t_env *e, int j, int y, int x)
{
	if (e->n.y_m[j] == -1)
	{
		ft_animate(e, "./spr/enm/atk/enm_atk_back", x, y + 1);
		if (e->n.i[j] == 5)
		{
			ft_put_floor(e, x, y);
			if (e->w.m[y][x] == 'P')
				ft_you_died(e);
		}
		else if (e->n.i[j] == 1)
		{
			e->n.i[j] += 1;
			e->index = e->n.i[j];
			ft_animate_b(e, "./spr/enm/atk/enm_atk_back", x, y);
		}
		else if (e->n.i[j] == 3)
		{
			ft_put_floor(e, x, y);
			e->n.i[j] += 1;
			e->index = e->n.i[j];
			ft_animate(e, "./spr/enm/atk/enm_atk_back", x, y);
		}
		return ;
	}
	return ;
}

void	ft_enemy_move_atk_s(t_env *e, int j, int y, int x)
{
	if (e->n.y_m[j] == 1)
	{
		ft_animate(e, "./spr/enm/atk/enm_atk_front", x, y - 1);
		if (e->n.i[j] == 5)
		{
			ft_put_floor(e, x, y);
			if (e->w.m[y][x] == 'P')
				ft_you_died(e);
		}
		else if (e->n.i[j] == 1)
		{
			e->n.i[j] += 1;
			e->index = e->n.i[j];
			ft_animate_b(e, "./spr/enm/atk/enm_atk_front", x, y);
		}
		else if (e->n.i[j] == 3)
		{
			ft_put_floor(e, x, y);
			e->n.i[j] += 1;
			e->index = e->n.i[j];
			ft_animate(e, "./spr/enm/atk/enm_atk_front", x, y);
		}
		return ;
	}
	return ;
}
