/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moveset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:22:54 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/27 17:43:15 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_animate_enm_mv(t_env *e, char *s2, int x, int y, int index)
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
	free(e->path);
	return (0);
}

int	ft_animate_enm_mv_b(t_env *e, char *s2, int x, int y, int index)
{
	char	*s1;
	char	*c;

	c = ft_itoa(index);
	s1 = ft_strjoin(s2, c);
	free(c);
	e->path = ft_strjoin(s1, ".xpm");
	free(s1);
	e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
	mlx_put_image_to_window(e->mlx, e->win, e->img, x * 64, y * 64);
	free(e->path);
	return (0);
}

int	ft_enemy_move_a(t_env *e, int j)
{
	if (e->n.x_m[j] == -1)
	{
		if (e->n.i[j] == 4 && ft_cond(e, e->n.n_y[j], e->n.n_x[j] + 1) == 0)
			ft_put_floor(e, e->n.n_x[j] + 1, e->n.n_y[j]);
		ft_animate_enm_mv(e, "./spr/enm/enm_sx", e->n.n_x[j], e->n.n_y[j], e->n.i[j]);
		if (e->n.i[j] == 2 && ft_cond(e, e->n.n_y[j], e->n.n_x[j] - 1) == 0)
		{
			e->w.m[e->n.n_y[j]][e->n.n_x[j]] = '0';
			e->n.i[j] += 1;
			e->n.n_x[j] -= 1;
			e->w.m[e->n.n_y[j]][e->n.n_x[j]] = 'N';
			ft_animate_enm_mv_b(e, "./spr/enm/enm_sx", e->n.n_x[j], e->n.n_y[j], e->n.i[j]);
			if (e->w.m[e->n.n_y[j]][e->n.n_x[j]] == 'P')
				ft_you_died(e);
		}
	}
	return (0);
}

int	ft_enemy_move_d(t_env *e, int j)
{
	if (e->n.x_m[j] == 1)
	{
		if (e->n.i[j] == 4 && ft_cond(e, e->n.n_y[j], e->n.n_x[j] - 1) == 0)
			ft_put_floor(e, e->n.n_x[j] - 1, e->n.n_y[j]);
		ft_animate_enm_mv(e, "./spr/enm/enm_dx", e->n.n_x[j], e->n.n_y[j], e->n.i[j]);
		if (e->n.i[j] == 2 && ft_cond(e, e->n.n_y[j], e->n.n_x[j] + 1) == 0)
		{
			e->w.m[e->n.n_y[j]][e->n.n_x[j]] = '0';
			e->n.i[j] += 1;
			e->n.n_x[j] += 1;
			e->w.m[e->n.n_y[j]][e->n.n_x[j]] = 'N';
			ft_animate_enm_mv_b(e, "./spr/enm/enm_dx", e->n.n_x[j], e->n.n_y[j], e->n.i[j]);
			if (e->w.m[e->n.n_y[j]][e->n.n_x[j]] == 'P')
				ft_you_died(e);
		}
	}
	return (0);
}

int	ft_enemy_move_w(t_env *e, int j)
{
	if (e->n.y_m[j] == -1)
	{
		if (e->n.i[j] == 4 && ft_cond(e, e->n.n_y[j] + 1, e->n.n_x[j]) == 0)
			ft_put_floor(e, e->n.n_x[j], e->n.n_y[j] + 1);
		ft_animate_enm_mv(e, "./spr/enm/enm_back", e->n.n_x[j], e->n.n_y[j], e->n.i[j]);
		if (e->n.i[j] == 2 && ft_cond(e, e->n.n_y[j] - 1, e->n.n_x[j]) == 0)
		{
			e->w.m[e->n.n_y[j]][e->n.n_x[j]] = '0';
			e->n.i[j] += 1;
			e->n.n_y[j] -= 1;
			e->w.m[e->n.n_y[j]][e->n.n_x[j]] = 'N';
			ft_animate_enm_mv_b(e, "./spr/enm/enm_back", e->n.n_x[j], e->n.n_y[j], e->n.i[j]);
			if (e->w.m[e->n.n_y[j]][e->n.n_x[j]] == 'P')
				ft_you_died(e);
		}
	}
	return (0);
}

int	ft_enemy_move_s(t_env *e, int j)
{
	if (e->n.y_m[j] == 1)
	{
		if (e->n.i[j] == 4 && ft_cond(e, e->n.n_y[j] - 1, e->n.n_x[j]) == 0)
			ft_put_floor(e, e->n.n_x[j], e->n.n_y[j] - 1);
		ft_animate_enm_mv(e, "./spr/enm/enm_fnt", e->n.n_x[j], e->n.n_y[j], e->n.i[j]);
		if (e->n.i[j] == 2 && ft_cond(e, e->n.n_y[j] + 1, e->n.n_x[j]) == 0)
		{
			e->w.m[e->n.n_y[j]][e->n.n_x[j]] = '0';
			e->n.i[j] += 1;
			e->n.n_y[j] += 1;
			e->w.m[e->n.n_y[j]][e->n.n_x[j]] = 'N';
			ft_animate_enm_mv_b(e, "./spr/enm/enm_fnt", e->n.n_x[j], e->n.n_y[j], e->n.i[j]);
			if (e->w.m[e->n.n_y[j]][e->n.n_x[j]] == 'P')
				ft_you_died(e);
		}
	}
	return (0);
}
