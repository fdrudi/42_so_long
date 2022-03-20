/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:22:08 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/20 14:53:53 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_size_map(t_env *e)
{
	if (ft_min_nbr(e->w.x, e->w.y) >= 17)
		e->path = "./sprites/next_level/next_level_21.xpm";
	else if (ft_min_nbr(e->w.x, e->w.y) >= 15)
		e->path = "./sprites/next_level/next_level_17.xpm";
	else if (ft_min_nbr(e->w.x, e->w.y) >= 10)
		e->path = "./sprites/next_level/next_level_15.xpm";
	else if (ft_min_nbr(e->w.x, e->w.y) >= 7)
		e->path = "./sprites/next_level/next_level_10.xpm";
	else if (ft_min_nbr(e->w.x, e->w.y) >= 5)
		e->path = "./sprites/next_level/next_level_7.xpm";
	else if (ft_min_nbr(e->w.x, e->w.y) >= 3)
		e->path = "./sprites/next_level/next_level_5.xpm";
	return (0);
}

int	ft_check_size_map2(t_env *e)
{
	if (ft_min_nbr(e->w.x, e->w.y) >= 17)
		e->path = "./sprites/game_over/game_over_21.xpm";
	else if (ft_min_nbr(e->w.x, e->w.y) >= 15)
		e->path = "./sprites/game_over/game_over_17.xpm";
	else if (ft_min_nbr(e->w.x, e->w.y) >= 10)
		e->path = "./sprites/game_over/game_over_15.xpm";
	else if (ft_min_nbr(e->w.x, e->w.y) >= 7)
		e->path = "./sprites/game_over/game_over_10.xpm";
	else if (ft_min_nbr(e->w.x, e->w.y) >= 5)
		e->path = "./sprites/game_over/game_over_7.xpm";
	else if (ft_min_nbr(e->w.x, e->w.y) >= 3)
		e->path = "./sprites/game_over/game_over_5.xpm";
	return (0);
}

int	ft_endgame(t_env *e)
{
	int	x;
	int	y;

	if (e->w.m[e->pg_y][e->pg_x] == 'E')
	{
		if (ft_check_next_map(e) == 1)
		{
			e->end = 2;
			ft_check_size_map2(e);
			x = (e->w.x / 3) * 64;
			y = (e->w.y / 3) * 64;
			e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
			mlx_put_image_to_window(e->mlx, e->win, e->img, x, y);
		}
		else
		{
			e->end = 1;
			ft_check_size_map(e);
			x = ((e->w.x / 2) - (e->w.x / 3)) * 64;
			e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
			mlx_put_image_to_window(e->mlx, e->win, e->img, x, 64);
		}
	}
	return (0);
}

int	ft_check_obj(t_env *e)
{
	int	i;

	i = 0;
	while (i < e->obj_c)
	{
		if (e->w.m[e->pg_y][e->pg_x] == e->w.m[e->obj_y[i]][e->obj_x[i]])
		{
			e->obj_x = ft_int_trim(e->obj_x, i, e->obj_c);
			e->obj_y = ft_int_trim(e->obj_y, i, e->obj_c);
			e->obj_c -= 1;
			return (0);
		}
		i++;
	}
	return (0);
}

int	ft_check_next_map(t_env *e)
{
	char	*s1;
	int		fd;

	fd = 0;
	if (e->w.ac == 1)
	{
		s1 = (char *) malloc (sizeof(char) * 1);
		if (!s1)
			exit(1);
		s1[0] = '\0';
		s1 = ft_strjoin(s1, "./map");
		s1 = ft_strjoin(s1, ft_itoa(e->next + 1));
		s1 = ft_strjoin(s1, ".ber");
		fd = open(s1, O_RDONLY);
		free(s1);
	}
	else
		fd = open(e->w.av[e->next + 2], O_RDONLY);
	if (fd == -1)
		return (1);
	return (0);
}
