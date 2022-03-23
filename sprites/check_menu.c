/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:39:59 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/23 15:44:46 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_size_map3(t_env *e, int *y, int *x)
{
	if (ft_min_nbr(e->w.x, e->w.y) >= 17)
	{
		*x = ((e->w.x / 2) * 64) - (1344 / 2);
		*y = ((e->w.y / 2) * 64) - (756 / 2);
		e->path = "./sprites/you_died/you_died_21.xpm";
	}
	else if (ft_min_nbr(e->w.x, e->w.y) >= 15)
	{
		*x = ((e->w.x / 2) * 64) - (1088 / 2);
		*y = ((e->w.y / 2) * 64) - (612 / 2);
		e->path = "./sprites/you_died/you_died_17.xpm";
	}
	else if (ft_min_nbr(e->w.x, e->w.y) >= 10)
	{
		*x = ((e->w.x / 2) * 64) - (960 / 2);
		*y = ((e->w.y / 2) * 64) - ( / 2);
		e->path = "./sprites/you_died/you_died_15.xpm";
	}
	else if (ft_min_nbr(e->w.x, e->w.y) >= 7)
	{
		*x = ((e->w.x / 2) * 64) - (640 / 2);
		*y = ((e->w.y / 2) * 64) - (447 / 2);
		e->path = "./sprites/you_died/you_died_10.xpm";
	}
	else if (ft_min_nbr(e->w.x, e->w.y) >= 5)
	{
		*x = ((e->w.x / 2) * 64) - (448 / 2);
		*y = ((e->w.y / 2) * 64) - (313 / 2);
		e->path = "./sprites/you_died/you_died_7.xpm";
	}
	else if (ft_min_nbr(e->w.x, e->w.y) >= 3)
	{
		*x = ((e->w.x / 2) * 64) - (320 / 2);
		*y = ((e->w.y / 2) * 64) - (224 / 2);
		e->path = "./sprites/you_died/you_died_5.xpm";
	}
}

void	ft_check_size_map(t_env *e, int *y, int *x)
{
	if (ft_min_nbr(e->w.x, e->w.y) >= 17)
	{
		*x = ((e->w.x / 2) * 64) - (1344 / 2);
		*y = ((e->w.y / 2) * 64) - (939 / 2);
		e->path = "./sprites/next_level/next_level_21.xpm";
	}
	else if (ft_min_nbr(e->w.x, e->w.y) >= 15)
	{
		*x = ((e->w.x / 2) * 64) - (1088 / 2);
		*y = ((e->w.y / 2) * 64) - (760 / 2);
		e->path = "./sprites/next_level/next_level_17.xpm";
	}
	else if (ft_min_nbr(e->w.x, e->w.y) >= 10)
	{
		*x = ((e->w.x / 2) * 64) - (960 / 2);
		*y = ((e->w.y / 2) * 64) - (671 / 2);
		e->path = "./sprites/next_level/next_level_15.xpm";
	}
	else if (ft_min_nbr(e->w.x, e->w.y) >= 7)
	{
		*x = ((e->w.x / 2) * 64) - (640 / 2);
		*y = ((e->w.y / 2) * 64) - (447 / 2);
		e->path = "./sprites/next_level/next_level_10.xpm";
	}
	else if (ft_min_nbr(e->w.x, e->w.y) >= 5)
	{
		*x = ((e->w.x / 2) * 64) - (448 / 2);
		*y = ((e->w.y / 2) * 64) - (313 / 2);
		e->path = "./sprites/next_level/next_level_7.xpm";
	}
	else if (ft_min_nbr(e->w.x, e->w.y) >= 3)
	{
		*x = ((e->w.x / 2) * 64) - (320 / 2);
		*y = ((e->w.y / 2) * 64) - (224 / 2);
		e->path = "./sprites/next_level/next_level_5.xpm";
	}
}

void	ft_check_size_map2(t_env *e, int *y, int *x)
{
	if (ft_min_nbr(e->w.x, e->w.y) >= 17)
	{
		*x = ((e->w.x / 2) * 64) - (1344 / 2);
		*y = ((e->w.y / 2) * 64) - (756 / 2);
		e->path = "./sprites/game_over/game_over_21.xpm";
	}
	else if (ft_min_nbr(e->w.x, e->w.y) >= 15)
	{
		*x = ((e->w.x / 2) * 64) - (1088 / 2);
		*y = ((e->w.y / 2) * 64) - (612 / 2);
		e->path = "./sprites/game_over/game_over_17.xpm";
	}
	else if (ft_min_nbr(e->w.x, e->w.y) >= 10)
	{
		*x = ((e->w.x / 2) * 64) - (960 / 2);
		*y = ((e->w.y / 2) * 64) - (540 / 2);
		e->path = "./sprites/game_over/game_over_15.xpm";
	}
	else if (ft_min_nbr(e->w.x, e->w.y) >= 7)
	{
		*x = ((e->w.x / 2) * 64) - (640 / 2);
		*y = ((e->w.y / 2) * 64) - (360 / 2);
		e->path = "./sprites/game_over/game_over_10.xpm";
	}
	else if (ft_min_nbr(e->w.x, e->w.y) >= 5)
	{
		*x = ((e->w.x / 2) * 64) - (448 / 2);
		*y = ((e->w.y / 2) * 64) - (252 / 2);
		e->path = "./sprites/game_over/game_over_7.xpm";
	}
	else if (ft_min_nbr(e->w.x, e->w.y) >= 3)
	{
		*x = ((e->w.x / 2) * 64) - (320 / 2);
		*y = ((e->w.y / 2) * 64) - (180 / 2);
		e->path = "./sprites/game_over/game_over_5.xpm";
	}
}
