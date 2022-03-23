/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pg_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:42:59 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/23 11:36:21 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_fade(t_env *e)
{
	static int	i;

	e->end = -1;
	if (ft_delay(&e->d3, 1000) == 1)
		return (1);
	if (i < 8)
	{
		e->index = i;
		ft_animate(e, "./sprites/mage_fade/mage_fade", e->ex_x, e->ex_y);
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

// int	ft_move_pg_help(t_env *e, char *s)
// {
// 	if (e->w.m[e->p.pg_y][e->p.pg_x] != 'E')
// 	{
// 		e->w.m[e->p.pg_y][e->p.pg_x] = 'P';
// 		ft_check_obj(e, e->p.pg_y, e->p.pg_x);
// 		ft_put_floor(e, e->p.pg_x, e->p.pg_y);
// 	}
// 	e->img = mlx_xpm_file_to_image(e->mlx, s, &e->i_x, &e->i_y);
// 	mlx_put_image_to_window(e->mlx, e->win, e->img, e->p.pg_x * 64, e->p.pg_y * 64);
// 	return (0);
// }

// int	ft_move_pg(t_env *e, int y, int x)
// {
// 	ft_put_floor(e, e->p.pg_x, e->p.pg_y);
// 	e->w.m[e->p.pg_y][e->p.pg_x] = '0';
// 	e->p.pg_x += x;
// 	e->p.pg_y += y;
// 	if (e->w.m[e->p.pg_y][e->p.pg_x] == 'N')
// 	{
// 		e->end = -1;
// 		return (1);
// 	}
// 	else if (x > 0)
// 		ft_move_pg_help(e, "./sprites/player_dx.xpm");
// 	else if (x < 0)
// 		ft_move_pg_help(e, "./sprites/player_sx.xpm");
// 	else if (y > 0)
// 		ft_move_pg_help(e, "./sprites/player.xpm");
// 	else if (y < 0)
// 		ft_move_pg_help(e, "./sprites/player_back.xpm");
// 	return (0);
// }
