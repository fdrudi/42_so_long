/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:08:03 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/18 19:31:33 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_make_map(t_env *e, int *img_x, int *img_y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	e->obj_c = 0;
	e->obj_x = (int *) malloc (sizeof(int) * 1);
	e->obj_y = (int *) malloc (sizeof(int) * 1);
	e->n.n_c = 0;
	e->n.n_x = (int *) malloc (sizeof(int) * 1);
	e->n.n_y = (int *) malloc (sizeof(int) * 1);
	if (!e->obj_x || !e->obj_y)
		exit(1);
	while (i < e->w.y)
	{
		j = 0;
		while (j < e->w.x)
		{
			if (e->w.m[i][j] == '1')
			{
				if ((e->w.m[i][j - 1] != '1' && e->w.m[i][j + 1] != '1' && j > 0 && j < e->w.x - 1) || i == 0 || i == e->w.y -1)
				{
					e->path = "./sprites/wall3.xpm";
					e->img = mlx_xpm_file_to_image(e->mlx, e->path, img_x, img_y);
					mlx_put_image_to_window(e->mlx, e->win, e->img, j * 64, i * 64);
				}
				else
				{
					e->path = "./sprites/wall4.xpm";
					e->img = mlx_xpm_file_to_image(e->mlx, e->path, img_x, img_y);
					mlx_put_image_to_window(e->mlx, e->win, e->img, j * 64, i * 64);
				}
			}
			else
			{
				ft_put_floor_map(e, j, i);
				if (e->w.m[i][j] == 'P')
				{
					e->path = "./sprites/player.xpm";
					e->img = mlx_xpm_file_to_image(e->mlx, e->path, img_x, img_y);
					mlx_put_image_to_window(e->mlx, e->win, e->img, j * 64, i * 64);
					e->pg_x = j;
					e->pg_y = i;
				}
				if (e->w.m[i][j] == 'C')
				{
					e->path = "./sprites/coin0.xpm";
					e->img = mlx_xpm_file_to_image(e->mlx, e->path, img_x, img_y);
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
				if (e->w.m[i][j] == 'E')
				{
					e->path = "./sprites/door0.xpm";
					e->img = mlx_xpm_file_to_image(e->mlx, e->path, img_x, img_y);
					mlx_put_image_to_window(e->mlx, e->win, e->img, j * 64, i * 64);
					e->ex_x = j;
					e->ex_y = i;
				}
				if (e->w.m[i][j] == 'N')
				{
					e->path = "./sprites/enemy/enemy_back0.xpm";
					e->img = mlx_xpm_file_to_image(e->mlx, e->path, img_x, img_y);
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
			j++;
		}
		i++;
	}
	return (0);
}
