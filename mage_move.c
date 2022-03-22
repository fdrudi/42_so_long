/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mage_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:03:10 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/22 15:54:17 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mage_move_help(t_env *e, char *s, int y, int x)
{
	if (e->index == 4)
	{
		ft_put_floor(e, e->pg_x, e->pg_y);
		e->pg_x = x;
		e->pg_y = y;
	}
	ft_animate(e, s, e->pg_x, e->pg_y);
	if (e->index == 1 && e->lst_key == 1)
	{
		e->index = 6;
		ft_animate_b(e, s, x, y);
	}
	if (e->index == 2)
	{
		if (e->w.m[y][x] != 'E')
		{
			e->w.m[e->pg_y][e->pg_x] = '0';
			e->w.m[y][x] = 'P';
			ft_check_obj(e, y, x);
		}
		e->pg_c += 1;
		e->index = e->pg_c;
		ft_animate_b(e, s, x, y);
		if (e->w.m[y][x] == 'E')
		{
			e->pg_c = -2;
			e->lst_key = -1;
		}
	}
	return (0);
}

int	ft_mage_move(t_env *e)
{
	if (e->pg_c > 5)
	{
		e->pg_c = 1;
	}
	if (ft_delay(&e->d_mg, 500) == 1)
		return (1);
	e->index = e->pg_c;
	if (e->pg_c == 5)
		e->index = 0;
	if (e->w.m[e->pg_y][e->pg_x] == 'N')
	{
		e->end = -1;
		return (1);
	}
	else if (e->lst_key == 1)
		ft_mage_move_help(e, "./sprites/mage/mage_back", e->pg_y - 1, e->pg_x);
	else if (e->lst_key == 2)
		ft_mage_move_help(e, "./sprites/mage/mage_front", e->pg_y + 1, e->pg_x);
	else if (e->lst_key == 3)
		ft_mage_move_help(e, "./sprites/mage/mage_sx", e->pg_y, e->pg_x - 1);
	else if (e->lst_key == 4)
		ft_mage_move_help(e, "./sprites/mage/mage_dx", e->pg_y, e->pg_x + 1);
	e->pg_c += 1;
	if (e->pg_c == -1)
		ft_put_floor(e, e->pg_x, e->pg_y);
	if (e->pg_c > 5)
	{
		e->lst_key = -1;
		ft_move_count(e, &e->w);
	}
	return (0);
}
