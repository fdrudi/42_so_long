/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:08:03 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/27 17:17:27 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_wall_help(t_env *e, int j, int i)
{
	if ((j > 0 && j < e->w.x - 1 && e->w.m[i][j - 1] != '1'
		&& e->w.m[i][j + 1] != '1') || i == 0 || i == e->w.y -1)
	{
		e->path = "./spr/w_f/wall3.xpm";
		e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
		mlx_put_image_to_window(e->mlx, e->win, e->img, j * 64, i * 64);
		// usleep(100);
	}
	else
	{
		e->path = "./spr/w_f/wall4.xpm";
		e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
		mlx_put_image_to_window(e->mlx, e->win, e->img, j * 64, i * 64);
		// usleep(100);
	}
}

void	ft_obj_pg(t_env *e, int j, int i)
{
	static int	a;

	if (e->w.m[i][j] == 'P')
	{
		e->path = "./spr/mg/mg_front0.xpm";
		e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
		mlx_put_image_to_window(e->mlx, e->win, e->img, j * 64, i * 64);
		// usleep(100);
		e->p.pg_x = j;
		e->p.pg_y = i;
	}
	else if (e->w.m[i][j] == 'C' && a < e->obj_c)
	{
		e->path = "./spr/obj/coin0.xpm";
		e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
		mlx_put_image_to_window(e->mlx, e->win, e->img, j * 64, i * 64);
		// usleep(100);
		e->obj_x[a] = j;
		e->obj_y[a] = i;
		a++;
	}
	if (a == e->obj_c)
		a = 0;
}

void	ft_enm_ext(t_env *e, int j, int i)
{
	static int	a;

	if (e->w.m[i][j] == 'E')
	{
		e->path = "./spr/door/door0.xpm";
		e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
		mlx_put_image_to_window(e->mlx, e->win, e->img, j * 64, i * 64);
		// usleep(100);
		e->ex_x = j;
		e->ex_y = i;
	}
	else if (e->w.m[i][j] == 'N' && a < e->n.n_c)
	{
		e->path = "./spr/enm/enm_back0.xpm";
		e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
		mlx_put_image_to_window(e->mlx, e->win, e->img, j * 64, i * 64);
		// usleep(100);
		e->n.n_x[a] = j;
		e->n.n_y[a] = i;
		a++;
	}
	if (a == e->n.n_c)
		a = 0;
}

void	ft_make_map(t_env *e)
{
	int	i;
	int	j;

	ft_check_map(e);
	ft_myinit3(e);
	i = -1;
	while (++i < e->w.y)
	{
		j = -1;
		while (++j < e->w.x)
		{
			if (e->w.m[i][j] == '1')
				ft_wall_help(e, j, i);
			else
			{
				ft_put_floor_map(e, j, i);
				ft_obj_pg(e, j, i);
				ft_enm_ext(e, j, i);
			}
		}
	}
	if (e->n.n_c > 0)
		e->n.n_m = 1;
}
