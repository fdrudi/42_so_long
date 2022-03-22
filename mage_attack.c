/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mage_attack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:23:36 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/22 19:22:31 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_cond_mage(t_env *e)
{
	if (e->p.atk == 1 && e->w.m[e->p.pg_y - 1][e->p.pg_x] != '1'
			&& e->w.m[e->p.pg_y - 1][e->p.pg_x] != 'E')
		return (0);
	else if (e->p.atk == 2 && e->w.m[e->p.pg_y + 1][e->p.pg_x] != '1'
		&& e->w.m[e->p.pg_y + 1][e->p.pg_x] != 'E')
		return (0);
	else if (e->p.atk == 3 && e->w.m[e->p.pg_y][e->p.pg_x - 1] != '1'
		&& e->w.m[e->p.pg_y][e->p.pg_x - 1] != 'E')
		return (0);
	else if (e->p.atk == 4 && e->w.m[e->p.pg_y][e->p.pg_x + 1] != '1'
		&& e->w.m[e->p.pg_y][e->p.pg_x + 1] != 'E')
		return (0);
	return (1);
}

int	ft_mage_atk_help(t_env *e, char *s, int y, int x)
{
	if (e->p.atk_c <= 1 || e->p.atk_c == 3 || e->p.atk_c == 7)
		ft_animate(e, s, e->p.pg_x, e->p.pg_y);
	if (e->p.atk_c == 1 || e->p.atk_c == 3 || e->p.atk_c == 7)
	{
		e->p.atk_c += 1;
		e->index = e->p.pg_c;
		ft_animate_b(e, s, x, y);
	}
	else if (e->p.atk_c == 5 || e->p.atk_c == 6)
		ft_animate_b(e, s, x, y);
	else if (e->p.atk_c > 8)
		ft_animate(e, s, x, y);
	return (0);
}

int	ft_mage_attack(t_env *e)
{
	if (ft_delay(&e->p.d_ak, 1000) == 1)
		return (1);
	e->index = e->p.atk_c;
	if (e->p.atk == 1)
		ft_mage_atk_help(e, "./sprites/mage_atk/mage_atk_back", e->p.pg_y - 1, e->p.pg_x);
	else if (e->p.atk == 2)
		ft_mage_atk_help(e, "./sprites/mage_atk/mage_atk_front", e->p.pg_y + 1, e->p.pg_x);
	else if (e->p.atk == 3)
		ft_mage_atk_help(e, "./sprites/mage_atk/mage_atk_sx", e->p.pg_y, e->p.pg_x - 1);
	else if (e->p.atk == 4)
		ft_mage_atk_help(e, "./sprites/mage_atk/mage_atk_dx", e->p.pg_y, e->p.pg_x + 1);
	e->p.atk_c += 1;
	if (e->p.atk_c > 10)
	{
		e->p.atk_c = 0;
		e->lst_key = -1;
	}
	return (0);
}
