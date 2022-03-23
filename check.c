/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:22:08 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/23 15:40:44 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_endgame(t_env *e)
{
	int	x;
	int	y;

	if (e->w.m[e->p.pg_y][e->p.pg_x] == 'E')
	{
		if (ft_check_next_map(e) == 1)
		{
			e->end = 2;
			ft_check_size_map2(e, &y, &x);
			e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
			mlx_put_image_to_window(e->mlx, e->win, e->img, x, y);
		}
		else
		{
			e->end = 1;
			ft_check_size_map(e, &y, &x);
			e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
			mlx_put_image_to_window(e->mlx, e->win, e->img, x, y);
		}
	}
	return (0);
}

int	ft_check_obj(t_env *e, int y, int x)
{
	int	i;

	i = 0;
	while (i < e->obj_c)
	{
		if (e->w.m[y][x] == e->w.m[e->obj_y[i]][e->obj_x[i]])
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
	char	*c;
	int		fd;

	fd = 0;
	if (e->w.ac == 1)
	{
		c = ft_itoa(e->next + 1);
		s1 = ft_strjoin("./map", c);
		free(c);
		e->path = s1;
		free(s1);
		s1 = ft_strjoin(e->path, ".ber");
		e->path = s1;
		free(s1);
		fd = open(e->path, O_RDONLY);
	}
	else
		fd = open(e->w.av[e->next + 2], O_RDONLY);
	close(fd);
	if (fd == -1)
		return (1);
	return (0);
}
