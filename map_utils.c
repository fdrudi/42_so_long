/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:08:03 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/15 19:36:06 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_make_map(t_vars *vars, int *img_x, int *img_y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	vars->obj_count = 0;
	vars->obj_x = (int *) malloc (sizeof(int) * 1);
	vars->obj_y = (int *) malloc (sizeof(int) * 1);
	vars->n.enm_count = 0;
	vars->n.enm_x = (int *) malloc (sizeof(int) * 1);
	vars->n.enm_y = (int *) malloc (sizeof(int) * 1);
	if (!vars->obj_x || !vars->obj_y)
		exit(1);
	while (i < vars->w.y)
	{
		j = 0;
		while (j < vars->w.x)
		{
			if (vars->w.map[i][j] == '1')
			{
				if ((vars->w.map[i][j - 1] != '1' && vars->w.map[i][j + 1] != '1' && j > 0 && j < vars->w.x - 1) || i == 0 || i == vars->w.y -1)
				{
					vars->path = "./sprites/wall3.xpm";
					vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, img_x, img_y);
					mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 64, i * 64);
				}
				else
				{
					vars->path = "./sprites/wall4.xpm";
					vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, img_x, img_y);
					mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 64, i * 64);
				}
			}
			else
			{
				ft_put_floor(vars, j, i);
				if (vars->w.map[i][j] == 'P')
				{
					vars->path = "./sprites/player.xpm";
					vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, img_x, img_y);
					mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 64, i * 64);
					vars->pg_x = j;
					vars->pg_y = i;
				}
				if (vars->w.map[i][j] == 'C')
				{
					vars->path = "./sprites/coin0.xpm";
					vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, img_x, img_y);
					mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 64, i * 64);
					if (vars->obj_count == 0)
					{
						vars->obj_x[0] = j;
						vars->obj_y[0] = i;
					}
					else
					{
						vars->obj_x = ft_intjoin(vars->obj_x, j, vars->obj_count);
						vars->obj_y = ft_intjoin(vars->obj_y, i, vars->obj_count);
					}
					vars->obj_count += 1;
				}
				if (vars->w.map[i][j] == 'E')
				{
					vars->path = "./sprites/door0.xpm";
					vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, img_x, img_y);
					mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 64, i * 64);
					vars->ex_x = j;
					vars->ex_y = i;
				}
				if (vars->w.map[i][j] == 'N')
				{
					vars->path = "./sprites/enemy/golem_back0.xpm";
					vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, img_x, img_y);
					mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 64, i * 64);
					if (vars->n.enm_count == 0)
					{
						vars->n.enm_x[0] = j;
						vars->n.enm_y[0] = i;
					}
					else
					{
						vars->n.enm_x = ft_intjoin(vars->n.enm_x, j, vars->n.enm_count);
						vars->n.enm_y = ft_intjoin(vars->n.enm_y, i, vars->n.enm_count);
					}
					vars->n.enm_count += 1;
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}
