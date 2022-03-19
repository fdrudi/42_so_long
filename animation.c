/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:23:40 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/19 18:19:40 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_animation_b(t_env *e, char *s2, int x, int y)
{
	char	*s1;

	s1 = (char *) malloc (sizeof(char) * 1);
	if (!s1)
		exit(1);
	s1[0] = '\0';
	s1 = ft_strjoin(s1, s2);
	s1 = ft_strjoin(s1, ft_itoa(e->index));
	e->path = ft_strjoin(s1, ".xpm");
	e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
	mlx_put_image_to_window(e->mlx, e->win, e->img, x * 64, y * 64);
	free(s1);
	return (0);
}

int	ft_animation(t_env *e, char *s2, int x, int y)
{
	char	*s1;

	s1 = (char *) malloc (sizeof(char) * 1);
	if (!s1)
		exit(1);
	s1[0] = '\0';
	ft_put_floor(e, x, y);
	s1 = ft_strjoin(s1, s2);
	s1 = ft_strjoin(s1, ft_itoa(e->index));
	e->path = ft_strjoin(s1, ".xpm");
	e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
	mlx_put_image_to_window(e->mlx, e->win, e->img, x * 64, y * 64);
	free(s1);
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
		return (0);
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
	ft_check_obj(e);
	if (e->w.m[e->pg_y][e->pg_x] != 'E')
		ft_put_floor(e, e->pg_x, e->pg_y);
	e->img = mlx_xpm_file_to_image(e->mlx, s, &e->i_x, &e->i_y);
	mlx_put_image_to_window(e->mlx, e->win, e->img, e->pg_x * 64, e->pg_y * 64);
	ft_endgame(e);
	return (0);
}

int	ft_move_pg(t_env *e, int y, int x)
{
	ft_put_floor(e, e->pg_x, e->pg_y);
	e->pg_x += x;
	e->pg_y += y;
	if (x > 0)
		ft_move_pg_help(e, "./sprites/player_dx.xpm");
	else if (x < 0)
		ft_move_pg_help(e, "./sprites/player_sx.xpm");
	else if (y > 0)
		ft_move_pg_help(e, "./sprites/player.xpm");
	else if (y < 0)
		ft_move_pg_help(e, "./sprites/player_back.xpm");
	return (0);
}
