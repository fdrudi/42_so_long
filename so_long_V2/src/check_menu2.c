/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_menu2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:09:19 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/24 15:46:21 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_size_map3_help(t_env *e, int *y, int *x)
{
	if (ft_min_nbr(e->w.x, e->w.y) >= 7)
	{
		*x = ((e->w.x / 2) * 64) - (640 / 2);
		*y = ((e->w.y / 2) * 64) - (360 / 2);
		e->path = "./spr/you_died/you_died_10.xpm";
	}
	else if (ft_min_nbr(e->w.x, e->w.y) >= 5)
	{
		*x = ((e->w.x / 2) * 64) - (448 / 2);
		*y = ((e->w.y / 2) * 64) - (252 / 2);
		e->path = "./spr/you_died/you_died_7.xpm";
	}
	else if (ft_min_nbr(e->w.x, e->w.y) >= 3)
	{
		*x = ((e->w.x / 2) * 64) - (320 / 2);
		*y = ((e->w.y / 2) * 64) - (180 / 2);
		e->path = "./spr/you_died/you_died_5.xpm";
	}
}

void	ft_check_size_map3(t_env *e, int *y, int *x)
{
	if (ft_min_nbr(e->w.x, e->w.y) >= 17)
	{
		*x = ((e->w.x / 2) * 64) - (1344 / 2);
		*y = ((e->w.y / 2) * 64) - (756 / 2);
		e->path = "./spr/you_died/you_died_21.xpm";
	}
	else if (ft_min_nbr(e->w.x, e->w.y) >= 15)
	{
		*x = ((e->w.x / 2) * 64) - (1088 / 2);
		*y = ((e->w.y / 2) * 64) - (612 / 2);
		e->path = "./spr/you_died/you_died_17.xpm";
	}
	else if (ft_min_nbr(e->w.x, e->w.y) >= 10)
	{
		*x = ((e->w.x / 2) * 64) - (960 / 2);
		*y = ((e->w.y / 2) * 64) - (540 / 2);
		e->path = "./spr/you_died/you_died_15.xpm";
	}
	else
		ft_check_size_map3_help(e, y, x);
}
