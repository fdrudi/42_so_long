/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:22:08 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/15 19:34:24 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

int	ft_min_nbr(int a, int b)
{
	if (a < 0 || b < 0)
		exit(1);
	if (a < b)
		return (a);
	if (b < a)
		return (b);
	else
		return (a);
}

int	ft_check_size_map(t_vars *vars)
{
	if (ft_min_nbr(vars->w.x, vars->w.y) >= 17)
		vars->path = "./sprites/next_level/next_level_21.xpm";
	else if (ft_min_nbr(vars->w.x, vars->w.y) >= 15)
		vars->path = "./sprites/next_level/next_level_17.xpm";
	else if (ft_min_nbr(vars->w.x, vars->w.y) >= 10)
		vars->path = "./sprites/next_level/next_level_15.xpm";
	else if (ft_min_nbr(vars->w.x, vars->w.y) >= 7)
		vars->path = "./sprites/next_level/next_level_10.xpm";
	else if (ft_min_nbr(vars->w.x, vars->w.y) >= 5)
		vars->path = "./sprites/next_level/next_level_7.xpm";
	else if (ft_min_nbr(vars->w.x, vars->w.y) >= 3)
		vars->path = "./sprites/next_level/next_level_5.xpm";
	return (0);
}

int	ft_check_size_map2(t_vars *vars)
{
	if (ft_min_nbr(vars->w.x, vars->w.y) >= 17)
		vars->path = "./sprites/game_over/game_over_21.xpm";
	else if (ft_min_nbr(vars->w.x, vars->w.y) >= 15)
		vars->path = "./sprites/game_over/game_over_17.xpm";
	else if (ft_min_nbr(vars->w.x, vars->w.y) >= 10)
		vars->path = "./sprites/game_over/game_over_15.xpm";
	else if (ft_min_nbr(vars->w.x, vars->w.y) >= 7)
		vars->path = "./sprites/game_over/game_over_10.xpm";
	else if (ft_min_nbr(vars->w.x, vars->w.y) >= 5)
		vars->path = "./sprites/game_over/game_over_7.xpm";
	else if (ft_min_nbr(vars->w.x, vars->w.y) >= 3)
		vars->path = "./sprites/game_over/game_over_5.xpm";
	return (0);
}

int	ft_endgame(t_vars *vars)
{
	if (vars->w.map[vars->pg_y][vars->pg_x] == 'E')
	{
		if (ft_check_next_map(vars) == 1)
		{
			vars->end = 2;
			ft_check_size_map2(vars);
			vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &vars->img_x, &vars->img_y);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, (vars->w.x / 3) * 64, (vars->w.y / 3) * 64);
		}
		else
		{
			vars->end = 1;
			ft_check_size_map(vars);
			vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &vars->img_x, &vars->img_y);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, ((vars->w.x / 2) - (vars->w.x / 3)) * 64, 64);
		}
	}
	return (0);
}

int	ft_check_exit(t_vars *vars)
{
	static int	i;

	if (ft_delay(&vars->delay2, 1000) == 1)
	{
		return (0);
	}
	if (i < 4)
	{
		vars->index = i;
		ft_animation(vars, "./sprites/door", vars->ex_x, vars->ex_y);
		i++;
		return (0);
	}
	vars->obj_count = -1;
	i = 0;
	return (0);
}

int	ft_check_obj(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->obj_count)
	{
		if (vars->pg_x == vars->obj_x[i] && vars->pg_y == vars->obj_y[i])
		{
			vars->obj_x = ft_int_trim(vars->obj_x, i, vars->obj_count);
			vars->obj_y = ft_int_trim(vars->obj_y, i, vars->obj_count);
			vars->obj_count -= 1;
			return (0);
		}
		i++;
	}
	return (0);
}

int	ft_check_next_map(t_vars *vars)
{
	char	*s1;
	int		fd;

	fd = 0;
	s1 = (char *) malloc (sizeof(char) * 1);
	if (!s1)
		exit(1);
	s1[0] = '\0';
	s1 = ft_strjoin(s1, "./map");
	s1 = ft_strjoin(s1, ft_itoa(vars->next + 1));
	s1 = ft_strjoin(s1, ".ber");
	fd = open(s1, O_RDONLY);
	free(s1);
	if (fd == -1)
		return (1);
	return (0);
}
