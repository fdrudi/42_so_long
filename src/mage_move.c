/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mage_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:03:10 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/24 15:47:14 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_fade(t_env *e)
{
	static int	i;

	e->end = -1;
	if (ft_delay(&e->d3, 1000) == 1)
		return (1);
	if (i < 8)
	{
		e->index = i;
		ft_animate(e, "./spr/mg_fade/mg_fade", e->ex_x, e->ex_y);
		i++;
		if (e->p.pg_x != e->p.x_p || e->p.pg_y != e->p.y_p)
		{
			ft_put_floor(e, e->p.pg_x, e->p.pg_y);
			e->p.pg_x = e->ex_x;
			e->p.pg_y = e->ex_y;
		}
		return (1);
	}
	ft_endgame(e);
	e->p.x_p += 1;
	i = 0;
	return (0);
}

void	ft_mg_move_help2(t_env *e, char *s, int y, int x)
{
	if (e->w.m[y][x] != 'E')
	{
		e->w.m[e->p.pg_y][e->p.pg_x] = '0';
		e->w.m[y][x] = 'P';
		ft_check_obj(e, y, x);
	}
	e->p.pg_c += 1;
	e->index = e->p.pg_c;
	ft_animate_b(e, s, x, y);
	if (e->w.m[y][x] == 'E')
	{
		e->p.y_p = y;
		e->p.x_p = x;
		e->lst_key = -1;
	}
}

int	ft_mg_move_help(t_env *e, char *s, int y, int x)
{
	if (e->p.pg_c == 4)
	{
		ft_put_floor(e, e->p.pg_x, e->p.pg_y);
		e->p.pg_x = x;
		e->p.pg_y = y;
	}
	ft_animate(e, s, e->p.pg_x, e->p.pg_y);
	if (e->p.pg_c == 1 && e->lst_key == 1)
	{
		e->index = 6;
		ft_animate_b(e, s, x, y);
	}
	if (e->p.pg_c == 2)
		ft_mg_move_help2(e, s, y, x);
	return (0);
}

int	ft_mg_move(t_env *e)
{
	if (e->p.pg_c > 5)
		e->p.pg_c = 1;
	if (e->p.pg_c > 1 && ft_delay(&e->p.d_mg, 500) == 1)
		return (1);
	e->index = e->p.pg_c;
	if (e->p.pg_c == 5)
		e->index = 0;
	if (e->w.m[e->p.pg_y][e->p.pg_x] == 'N')
		ft_you_died(e);
	else if (e->lst_key == 1)
		ft_mg_move_help(e, "./spr/mg/mg_back", e->p.pg_y - 1, e->p.pg_x);
	else if (e->lst_key == 2)
		ft_mg_move_help(e, "./spr/mg/mg_front", e->p.pg_y + 1, e->p.pg_x);
	else if (e->lst_key == 3)
		ft_mg_move_help(e, "./spr/mg/mg_sx", e->p.pg_y, e->p.pg_x - 1);
	else if (e->lst_key == 4)
		ft_mg_move_help(e, "./spr/mg/mg_dx", e->p.pg_y, e->p.pg_x + 1);
	e->p.pg_c += 1;
	if (e->p.pg_c > 5)
	{
		e->p.atk = e->lst_key;
		e->lst_key = -1;
		ft_move_count(e, &e->w);
	}
	return (0);
}
