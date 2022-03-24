/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:08:03 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/24 18:25:25 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_wall_help(t_env *e, int j, int i)
{
	if ((e->w.m[i][j - 1] != '1' && e->w.m[i][j + 1] != '1' && j > 0
		&& j < e->w.x - 1) || i == 0 || i == e->w.y -1)
	{
		e->path = "./spr/w_f/wall3.xpm";
		e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
		mlx_put_image_to_window(e->mlx, e->win, e->img, j * 64, i * 64);
	}
	else
	{
		e->path = "./spr/w_f/wall4.xpm";
		e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
		mlx_put_image_to_window(e->mlx, e->win, e->img, j * 64, i * 64);
	}
}

void	ft_obj_pg(t_env *e, int j, int i)
{
	if (e->w.m[i][j] == 'P')
	{
		e->path = "./spr/mg/mg_front0.xpm";
		e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
		mlx_put_image_to_window(e->mlx, e->win, e->img, j * 64, i * 64);
		e->p.pg_x = j;
		e->p.pg_y = i;
	}
	if (e->w.m[i][j] == 'C')
	{
		e->path = "./spr/obj/coin0.xpm";
		e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
		mlx_put_image_to_window(e->mlx, e->win, e->img, j * 64, i * 64);
		if (e->obj_c == 0)
		{
			e->obj_x[0] = j;
			e->obj_y[0] = i;
		}
		else
		{
			e->obj_x = ft_intjoin(e->obj_x, j, e->obj_c);
			e->obj_y = ft_intjoin(e->obj_y, i, e->obj_c);
		}
		e->obj_c += 1;
	}
}

void	ft_enm_ext(t_env *e, int j, int i)
{
	if (e->w.m[i][j] == 'E')
	{
		e->path = "./spr/door/door0.xpm";
		e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
		mlx_put_image_to_window(e->mlx, e->win, e->img, j * 64, i * 64);
		e->ex_x = j;
		e->ex_y = i;
	}
	if (e->w.m[i][j] == 'N')
	{
		e->path = "./spr/enm/enm_back0.xpm";
		e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
		mlx_put_image_to_window(e->mlx, e->win, e->img, j * 64, i * 64);
		if (e->n.n_c == 0)
		{
			e->n.n_x[0] = j;
			e->n.n_y[0] = i;
		}
		else
		{
			e->n.n_x = ft_intjoin(e->n.n_x, j, e->n.n_c);
			e->n.n_y = ft_intjoin(e->n.n_y, i, e->n.n_c);
		}
		e->n.n_c += 1;
	}
}

void	ft_make_map(t_env *e)
{
	int	i;
	int	j;

	ft_check_map(e);
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
