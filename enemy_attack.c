/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_attack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:48:01 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/19 18:36:23 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_enemy_move_atk_b(t_env *e, int j, int i)
{
	if (e->n.x_m[j] == -1)
	{
		ft_animation(e, "./sprites/enm/atk/enm_atk_sx", e->n.n_x[j], e->n.n_y[j]);
		if (i == 1)
		{
			e->index = ++i;
			ft_animation_b(e, "./sprites/enm/atk/enm_atk_sx", e->n.n_x[j] - 1, e->n.n_y[j]);
		}
		else if (i == 3)
		{
			e->index = ++i;
			ft_animation(e, "./sprites/enm/atk/enm_atk_sx", e->n.n_x[j] - 1, e->n.n_y[j]);
		}
		return ;
	}
	else if (e->n.x_m[j] == 1)
	{
		ft_animation(e, "./sprites/enm/atk/enm_atk_dx", e->n.n_x[j], e->n.n_y[j]);
		if (i == 1)
		{
			e->index = ++i;
			ft_animation_b(e, "./sprites/enm/atk/enm_atk_dx", e->n.n_x[j] + 1, e->n.n_y[j]);
		}
		else if (i == 3)
		{
			e->index = ++i;
			ft_animation(e, "./sprites/enm/atk/enm_atk_dx", e->n.n_x[j] + 1, e->n.n_y[j]);
		}
		return ;
	}
	return ;
}

void	ft_enemy_move_atk(t_env *e, int j, int i)
{
	if (e->n.y_m[j] == -1)
	{
		ft_animation(e, "./sprites/enm/atk/enm_atk_back", e->n.n_x[j], e->n.n_y[j]);
		if (i == 1)
		{
			e->index = ++i;
			ft_animation_b(e, "./sprites/enm/atk/enm_atk_back", e->n.n_x[j], e->n.n_y[j] - 1);
		}
		else if (i == 3)
		{
			e->index = ++i;
			ft_animation(e, "./sprites/enm/atk/enm_atk_back", e->n.n_x[j], e->n.n_y[j] - 1);
		}
		return ;
	}
	else if (e->n.y_m[j] == 1)
	{
		ft_animation(e, "./sprites/enm/atk/enm_atk_front", e->n.n_x[j], e->n.n_y[j]);
		if (i == 1)
		{
			e->index = ++i;
			ft_animation_b(e, "./sprites/enm/atk/enm_atk_front", e->n.n_x[j], e->n.n_y[j] + 1);
		}
		else if (i == 3)
		{
			e->index = ++i;
			ft_animation(e, "./sprites/enm/atk/enm_atk_front", e->n.n_x[j], e->n.n_y[j] + 1);
		}
		return ;
	}
	else
		ft_enemy_move_atk_b(e, j, i);
	return ;
}

void	ft_enemy_dir_atk(t_env *e, int j, int i)
{
	if (e->n.y_m[j] == -1)
	{
		ft_enemy_move_atk(e, j, i);
		return ;
	}
	else if (e->n.y_m[j] == 1)
	{
		ft_enemy_move_atk(e, j, i);
		return ;
	}
	else if (e->n.x_m[j] == -1)
	{
		ft_enemy_move_atk(e, j, i);
		return ;
	}
	else if (e->n.x_m[j] == 1)
	{
		ft_enemy_move_atk(e, j, i);
		return ;
	}
}

int	ft_enemy_attack(t_env *e)
{
	int			j;
	static int	i;

	j = -1;
	if (i > 5)
		i = 0;
	if (ft_delay(&e->d6, 4000) == 1)
		return (0);
	while (++j < e->n.n_c)
	{
		e->index = i;
		if (e->n.patr[j] == 2)
		{
			ft_enemy_dir_atk(e, j, i);
			if (i == 5)
				e->n.patr[j] = 1;
		}
	}
	i++;
	return (0);
}
