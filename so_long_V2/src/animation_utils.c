/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:59:52 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/27 17:19:39 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_put_floor_map(t_env *e, int x, int y)
{
	e->path = "./spr/w_f/floor_map.xpm";
	e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
	mlx_put_image_to_window(e->mlx, e->win, e->img, x * 64, y * 64);
	usleep(100);
	ft_put_floor(e, x, y);
	return (0);
}

int	ft_put_floor(t_env *e, int x, int y)
{
	e->path = "./spr/w_f/floor.xpm";
	e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
	mlx_put_image_to_window(e->mlx, e->win, e->img, x * 64, y * 64);
	usleep(100);
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
	int		x;
	char	*c;

	x = (m->x - 1) * 64.5;
	e->mv += 1;
	e->path = "./spr/w_f/wall3.xpm";
	c = ft_itoa(e->mv);
	e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
	mlx_put_image_to_window(e->mlx, e->win, e->img, (m->x - 1) * 64, 0);
	mlx_string_put(e->mlx, e->win, x, 30, 0xFF00, c);
	free(c);
	return (0);
}

int	ft_check_exit(t_env *e)
{
	static int	i;

	if (ft_delay(&e->d2, 1000) == 1)
		return (0);
	if (i < 4)
	{
		ft_animate(e, "./spr/door/door", e->ex_x, e->ex_y, i);
		i++;
		return (0);
	}
	e->obj_c = -1;
	i = 0;
	return (0);
}
