/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_attack_moveset.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:39:57 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/27 17:19:18 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_animate_enm_atk(t_env *e, char *s2, int x, int y, int index)
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
	return (0);
}

int	ft_animate_enm_atk_b(t_env *e, char *s2, int x, int y, int index)
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
	return (0);
}

void	ft_enemy_move_atk_a(t_env *e, int j, int y, int x)
{
	if (e->w.m[e->n.n_y[j]][e->n.n_x[j]] == 'P')
		ft_you_died(e);
	if (e->n.x_m[j] == -1)
	{
		ft_animate_enm_atk(e, "./spr/enm/atk/enm_atk_sx", x + 1, y, e->n.i[j]);
		if (e->n.i[j] == 5)
		{
			ft_put_floor(e, x, y);
			if (e->w.m[y][x] == 'P')
				ft_you_died(e);
		}
		else if (e->n.i[j] == 1)
		{
			e->n.i[j] += 1;
			ft_animate_enm_atk_b(e, "./spr/enm/atk/enm_atk_sx", x, y, e->n.i[j]);
		}
		else if (e->n.i[j] == 3)
		{
			ft_put_floor(e, x, y);
			e->n.i[j] += 1;
			ft_animate_enm_atk(e, "./spr/enm/atk/enm_atk_sx", x, y, e->n.i[j]);
		}
	}
}

void	ft_enemy_move_atk_d(t_env *e, int j, int y, int x)
{
	if (e->w.m[e->n.n_y[j]][e->n.n_x[j]] == 'P')
		ft_you_died(e);
	if (e->n.x_m[j] == 1)
	{
		ft_animate_enm_atk(e, "./spr/enm/atk/enm_atk_dx", x - 1, y, e->n.i[j]);
		if (e->n.i[j] == 5)
		{
			ft_put_floor(e, x, y);
			if (e->w.m[y][x] == 'P')
				ft_you_died(e);
		}
		else if (e->n.i[j] == 1)
		{
			e->n.i[j] += 1;
			ft_animate_enm_atk_b(e, "./spr/enm/atk/enm_atk_dx", x, y, e->n.i[j]);
		}
		else if (e->n.i[j] == 3)
		{
			ft_put_floor(e, x, y);
			e->n.i[j] += 1;
			ft_animate_enm_atk(e, "./spr/enm/atk/enm_atk_dx", x, y, e->n.i[j]);
		}
	}
}

void	ft_enemy_move_atk_w(t_env *e, int j, int y, int x)
{
	if (e->w.m[e->n.n_y[j]][e->n.n_x[j]] == 'P')
		ft_you_died(e);
	if (e->n.y_m[j] == -1)
	{
		ft_animate_enm_atk(e, "./spr/enm/atk/enm_atk_back", x, y + 1, e->n.i[j]);
		if (e->n.i[j] == 5)
		{
			ft_put_floor(e, x, y);
			if (e->w.m[y][x] == 'P')
				ft_you_died(e);
		}
		else if (e->n.i[j] == 1)
		{
			e->n.i[j] += 1;
			ft_animate_enm_atk_b(e, "./spr/enm/atk/enm_atk_back", x, y, e->n.i[j]);
		}
		else if (e->n.i[j] == 3)
		{
			ft_put_floor(e, x, y);
			e->n.i[j] += 1;
			ft_animate_enm_atk(e, "./spr/enm/atk/enm_atk_back", x, y, e->n.i[j]);
		}
	}
}

void	ft_enemy_move_atk_s(t_env *e, int j, int y, int x)
{
	if (e->w.m[e->n.n_y[j]][e->n.n_x[j]] == 'P')
		ft_you_died(e);
	if (e->n.y_m[j] == 1)
	{
		ft_animate_enm_atk(e, "./spr/enm/atk/enm_atk_front", x, y - 1, e->n.i[j]);
		if (e->n.i[j] == 5)
		{
			ft_put_floor(e, x, y);
			if (e->w.m[y][x] == 'P')
				ft_you_died(e);
		}
		else if (e->n.i[j] == 1)
		{
			e->n.i[j] += 1;
			ft_animate_enm_atk_b(e, "./spr/enm/atk/enm_atk_front", x, y, e->n.i[j]);
		}
		else if (e->n.i[j] == 3)
		{
			ft_put_floor(e, x, y);
			e->n.i[j] += 1;
			ft_animate_enm_atk(e, "./spr/enm/atk/enm_atk_front", x, y, e->n.i[j]);
		}
	}
}
