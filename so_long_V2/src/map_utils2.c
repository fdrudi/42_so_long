/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:05:49 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/24 15:47:25 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_map2(t_env *e)
{
	int	x;
	int	y;

	y = 0;
	while (y < e->w.y)
	{
		x = 0;
		while (ft_isalnum(e->w.m[y][x]))
		{
			if (e->w.m[y][x] != '1' && e->w.m[y][x] != '0'
					&& e->w.m[y][x] != 'N' && e->w.m[y][x] != 'P'
					&& e->w.m[y][x] != 'C' && e->w.m[y][x] != 'E')
				ft_error(e, "error : invalid map (invalid set)\n");
			x++;
		}
		if (x != e->w.x)
			ft_error(e, "error : invalid map (map is not rectangular)\n");
		y++;
	}
}

void	ft_check_map(t_env *e)
{
	int	i;
	int	j;

	ft_check_map2(e);
	i = -1;
	while (++i < e->w.y)
	{
		j = -1;
		while (++j < e->w.x)
		{
			if ((i == 0 || i == e->w.y - 1 || j == 0 || j == e->w.x - 1)
				&& e->w.m[i][j] != '1')
				ft_error(e, "error : invalid map (wall incomplete)\n");
			else if (e->w.m[i][j] == 'C')
				e->obj_c = 1;
			else if (e->w.m[i][j] == 'E')
				e->ex_x = 1;
			else if (e->w.m[i][j] == 'P')
				e->p.pg_x = 1;
		}
	}
	if (e->ex_x != 1 || e->obj_c != 1 || e->p.pg_x != 1)
		ft_error(e, "error : invalid map (missing set)\n");
	else
		ft_myinit(e);
}
