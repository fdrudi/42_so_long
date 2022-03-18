/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:59:52 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/18 20:08:44 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_put_floor_map(t_env *e, int x, int y)
{
	e->path = "./sprites/floor_map.xpm";
	e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
	mlx_put_image_to_window(e->mlx, e->win, e->img, x * 64, y * 64);
	ft_put_floor(e, x, y);
	return (0);
}

int	ft_put_floor(t_env *e, int x, int y)
{
	e->path = "./sprites/floor.xpm";
	e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
	mlx_put_image_to_window(e->mlx, e->win, e->img, x * 64, y * 64);
	return (0);
}

int	ft_delay(int *d, int time)
{
	if (*d <= time)
	{
		*d += 1;
		return (1);
	}
	*d = 0;
	return (0);
}

int	ft_move_count(t_env *e, t_win *m)
{
	int	x;

	x = (m->x - 1) * 64.5;
	e->mv += 1;
	e->path = "./sprites/wall3.xpm";
	e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
	mlx_put_image_to_window(e->mlx, e->win, e->img, (m->x - 1) * 64, 0);
	mlx_string_put(e->mlx, e->win, x, 30, 0xFF00, ft_itoa(e->mv));
	return (0);
}

int	ft_check_exit(t_env *e)
{
	static int	i;

	if (ft_delay(&e->d2, 1000) == 1)
	{
		return (0);
	}
	if (i < 4)
	{
		e->index = i;
		ft_animation(e, "./sprites/door", e->ex_x, e->ex_y);
		i++;
		return (0);
	}
	e->obj_c = -1;
	i = 0;
	return (0);
}
