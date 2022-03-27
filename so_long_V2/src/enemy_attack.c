/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_attack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:48:01 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/27 11:17:38 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_enemy_dir_atk(t_env *e, int j)
{
	if (e->n.y_m[j] == -1)
	{
		ft_enemy_move_atk_w(e, j, e->n.n_y[j] - 1, e->n.n_x[j]);
		return ;
	}
	else if (e->n.y_m[j] == 1)
	{
		ft_enemy_move_atk_s(e, j, e->n.n_y[j] + 1, e->n.n_x[j]);
		return ;
	}
	else if (e->n.x_m[j] == -1)
	{
		ft_enemy_move_atk_a(e, j, e->n.n_y[j], e->n.n_x[j] - 1);
		return ;
	}
	else if (e->n.x_m[j] == 1)
	{
		ft_enemy_move_atk_d(e, j, e->n.n_y[j], e->n.n_x[j] + 1);
		return ;
	}
}

int	ft_enemy_attack(t_env *e)
{
	int	j;

	j = 0;
	if (ft_delay(&e->d6, 1000) == 1)
		return (0);
	while (j < e->n.n_c)
	{
		if (e->n.patr[j] == 2)
		{
			ft_enemy_dir_atk(e, j);
			if (e->n.i[j] == 5)
				e->n.patr[j] = -1;
			else
				e->n.i[j] += 1;
		}
		j++;
	}
	return (0);
}
