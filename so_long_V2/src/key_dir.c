/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:22:14 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/27 17:16:57 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_animate_mg_dir(t_env *e, char *s2, int x, int y, int index)
{
	char	*s1;
	char	*c;

	ft_put_floor(e, x, y);
	c = ft_itoa(index);
	s1 = ft_strjoin(s2, c);
	free(c);
	e->path = ft_strjoin(s1, ".xpm");
	free(s1);
	e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
	mlx_put_image_to_window(e->mlx, e->win, e->img, x * 64, y * 64);
	// usleep(100);
	return (0);
}

void	ft_key_act_w(t_env *e, int key)
{
	if ((key == 13 || key == 126) && e->w.m[e->p.pg_y - 1][e->p.pg_x] != '1'
			&& (e->w.m[e->p.pg_y - 1][e->p.pg_x] != 'E' || e->obj_c == -1))
	{
		if (e->lst_key == -1 && e->p.atk == 1)
			e->lst_key = 1;
		else if (e->lst_key == -1 && e->end == 0)
		{
			e->p.atk = 1;
			ft_animate_mg_dir(e, "./spr/mg/mg_back", e->p.pg_x, e->p.pg_y, 0);
		}
	}
	return ;
}

void	ft_key_act_s(t_env *e, int key)
{
	if ((key == 1 || key == 125) && e->w.m[e->p.pg_y + 1][e->p.pg_x] != '1'
		&& (e->w.m[e->p.pg_y + 1][e->p.pg_x] != 'E' || e->obj_c == -1))
	{
		if (e->lst_key == -1 && e->p.atk == 2)
			e->lst_key = 2;
		else if (e->lst_key == -1 && e->end == 0)
		{
			e->p.atk = 2;
			ft_animate_mg_dir(e, "./spr/mg/mg_front", e->p.pg_x, e->p.pg_y, 0);
		}
	}
	return ;
}

void	ft_key_act_a(t_env *e, int key)
{
	if ((key == 0 || key == 123) && e->w.m[e->p.pg_y][e->p.pg_x - 1] != '1'
		&& (e->w.m[e->p.pg_y][e->p.pg_x - 1] != 'E' || e->obj_c == -1))
	{
		if (e->lst_key == -1 && e->p.atk == 3)
			e->lst_key = 3;
		else if (e->lst_key == -1 && e->end == 0)
		{
			e->p.atk = 3;
			ft_animate_mg_dir(e, "./spr/mg/mg_sx", e->p.pg_x, e->p.pg_y, 0);
		}
	}
	return ;
}

void	ft_key_act_d(t_env *e, int key)
{
	if ((key == 2 || key == 124) && e->w.m[e->p.pg_y][e->p.pg_x + 1] != '1'
		&& (e->w.m[e->p.pg_y][e->p.pg_x + 1] != 'E' || e->obj_c == -1))
	{
		if (e->lst_key == -1 && e->p.atk == 4)
			e->lst_key = 4;
		else if (e->lst_key == -1 && e->end == 0)
		{
			e->p.atk = 4;
			ft_animate_mg_dir(e, "./spr/mg/mg_dx", e->p.pg_x, e->p.pg_y, 0);
		}
	}
	return ;
}
