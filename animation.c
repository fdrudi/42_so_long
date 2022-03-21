/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:23:40 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/21 14:50:11 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_animation_b(t_env *e, char *s2, int x, int y)
{
	char	*s1;
	char	*c;

	c = ft_itoa(e->index);
	s1 = ft_strjoin(s2, c);
	free(c);
	e->path = s1;
	free(s1);
	s1 = ft_strjoin(e->path, ".xpm");
	e->path = s1;
	free(s1);

	e->img = mlx_xpm_file_to_image(e->mlx, s1, &e->i_x, &e->i_y);
	mlx_put_image_to_window(e->mlx, e->win, e->img, x * 64, y * 64);
	return (0);
}

int	ft_animation(t_env *e, char *s2, int x, int y)
{
	char	*s1;
	char	*c;


	ft_put_floor(e, x, y);

	c = ft_itoa(e->index);
	s1 = ft_strjoin(s2, c);
	free(c);
	e->path = s1;
	free(s1);
	s1 = ft_strjoin(e->path, ".xpm");
	e->path = s1;
	free(s1);

	e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
	mlx_put_image_to_window(e->mlx, e->win, e->img, x * 64, y * 64);
	return (0);
}

int	ft_obj_animation(t_env *e)
{
	int			j;
	static int	i;

	j = 0;
	if (i > 5)
		i = 0;
	if (ft_delay(&e->d, 1000) == 1)
		return (1);
	while (j < e->obj_c)
	{
		e->index = i;
		ft_animation(e, "./sprites/coin", e->obj_x[j], e->obj_y[j]);
		j++;
	}
	i++;
	return (0);
}

int	ft_fade(t_env *e)
{
	static int	i;

	if (ft_delay(&e->d3, 1000) == 1)
		return (1);
	if (i < 7)
	{
		e->index = i;
		ft_animation(e, "./sprites/pg_fade/pg_fade", e->ex_x, e->ex_y);
		i++;
		return (1);
	}
	ft_endgame(e);
	e->pg_x += 1;
	i = 0;
	return (0);
}

int	ft_move_pg_help(t_env *e, char *s)
{
	if (e->w.m[e->pg_y][e->pg_x] != 'E')
	{
		e->w.m[e->pg_y][e->pg_x] = 'P';
		ft_check_obj(e);
		ft_put_floor(e, e->pg_x, e->pg_y);
	}
	e->img = mlx_xpm_file_to_image(e->mlx, s, &e->i_x, &e->i_y);
	mlx_put_image_to_window(e->mlx, e->win, e->img, e->pg_x * 64, e->pg_y * 64);
	return (0);
}

int	ft_move_pg(t_env *e, int y, int x)
{
	ft_put_floor(e, e->pg_x, e->pg_y);
	e->w.m[e->pg_y][e->pg_x] = '0';
	e->pg_x += x;
	e->pg_y += y;
	if (e->w.m[e->pg_y][e->pg_x] == 'N')
	{
		e->end = -1;
		return (1);
	}
	else if (x > 0)
		ft_move_pg_help(e, "./sprites/player_dx.xpm");
	else if (x < 0)
		ft_move_pg_help(e, "./sprites/player_sx.xpm");
	else if (y > 0)
		ft_move_pg_help(e, "./sprites/player.xpm");
	else if (y < 0)
		ft_move_pg_help(e, "./sprites/player_back.xpm");
	return (0);
}
