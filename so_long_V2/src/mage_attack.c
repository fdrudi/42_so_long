/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mage_attack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:23:36 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/27 11:52:27 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_animate_mg_atk(t_env *e, char *s2, int x, int y, int index)
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
	usleep(100);
	return (0);
}

int	ft_animate_mg_b(t_env *e, char *s2, int x, int y, int index)
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
	usleep(100);
	return (0);
}

int	ft_cond_mg(t_env *e)
{
	if (e->p.atk == 1 && e->w.m[e->p.pg_y - 1][e->p.pg_x] != '1'
			&& e->w.m[e->p.pg_y - 1][e->p.pg_x] != 'E'
			&& e->w.m[e->p.pg_y - 1][e->p.pg_x] != 'C')
		return (0);
	else if (e->p.atk == 2 && e->w.m[e->p.pg_y + 1][e->p.pg_x] != '1'
		&& e->w.m[e->p.pg_y + 1][e->p.pg_x] != 'E'
		&& e->w.m[e->p.pg_y + 1][e->p.pg_x] != 'C')
		return (0);
	else if (e->p.atk == 3 && e->w.m[e->p.pg_y][e->p.pg_x - 1] != '1'
		&& e->w.m[e->p.pg_y][e->p.pg_x - 1] != 'E'
		&& e->w.m[e->p.pg_y][e->p.pg_x - 1] != 'C')
		return (0);
	else if (e->p.atk == 4 && e->w.m[e->p.pg_y][e->p.pg_x + 1] != '1'
		&& e->w.m[e->p.pg_y][e->p.pg_x + 1] != 'E'
		&& e->w.m[e->p.pg_y][e->p.pg_x + 1] != 'C')
		return (0);
	return (1);
}

int	ft_check_enm(t_env *e, int y, int x)
{
	int	i;

	i = 0;
	while (i < e->n.n_c)
	{
		if (e->w.m[y][x] == e->w.m[e->n.n_y[i]][e->n.n_x[i]]
			&& e->n.patr[i] == 2)
		{
			e->w.m[e->n.n_y[i]][e->n.n_x[i]] = '0';
			e->n.n_x = ft_int_trim(e->n.n_x, i, e->n.n_c);
			e->n.n_y = ft_int_trim(e->n.n_y, i, e->n.n_c);
			e->n.i = ft_int_trim(e->n.i, i, e->n.n_c);
			e->n.patr = ft_int_trim(e->n.patr, i, e->n.n_c);
			e->n.y_m = ft_int_trim(e->n.y_m, i, e->n.n_c);
			e->n.x_m = ft_int_trim(e->n.x_m, i, e->n.n_c);
			e->n.n_c -= 1;
			return (0);
		}
		i++;
	}
	return (0);
}

int	ft_mg_atk_b(t_env *e, char *s, int y, int x)
{
	ft_check_enm(e, y, x);
	if (e->p.atk_c <= 1 || e->p.atk_c == 3 || e->p.atk_c == 8)
		ft_animate_mg_atk(e, s, e->p.pg_x, e->p.pg_y, e->p.atk_c);
	if (e->p.atk_c == 1 || e->p.atk_c == 3 || e->p.atk_c == 8)
	{
		e->p.atk_c += 1;
		ft_animate_mg_b(e, s, x, y, e->p.atk_c);
	}
	else if (e->p.atk_c == 5 || e->p.atk_c == 6 || e->p.atk_c == 7)
		ft_animate_mg_b(e, s, x, y, e->p.atk_c);
	else if (e->p.atk_c > 9)
		ft_animate_mg_atk(e, s, x, y, e->p.atk_c);
	return (0);
}

int	ft_mg_attack(t_env *e)
{
	if (ft_delay(&e->p.d_ak, 1000) == 1)
		return (0);
	if (e->p.pg_x != 0 && e->p.pg_y != 0)
	{
		e->p.t_x = e->p.pg_x;
		e->p.t_y = e->p.pg_y;
	}
	if (e->end == 0 || (e->p.atk_c > 1 && e->p.atk_c != 3 && e->p.atk_c != 8))
	{
		if (e->p.atk == 1)
			ft_mg_atk_b(e, "./spr/mg_atk/mg_atk_bk", e->p.t_y - 1, e->p.t_x);
		else if (e->p.atk == 2)
			ft_mg_atk_b(e, "./spr/mg_atk/mg_atk_fr", e->p.t_y + 1, e->p.t_x);
		else if (e->p.atk == 3)
			ft_mg_atk_b(e, "./spr/mg_atk/mg_atk_sx", e->p.t_y, e->p.t_x - 1);
		else if (e->p.atk == 4)
			ft_mg_atk_b(e, "./spr/mg_atk/mg_atk_dx", e->p.t_y, e->p.t_x + 1);
	}
	e->p.atk_c += 1;
	if (e->p.atk_c > 12)
	{
		e->p.atk_c = 0;
		e->lst_key = -1;
	}
	return (0);
}
