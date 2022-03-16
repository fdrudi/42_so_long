/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:23:40 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/16 17:32:28 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

int	ft_put_floor_map(t_vars *vars, int x, int y)
{
	vars->path = "./sprites/floor_map.xpm";
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &vars->img_x, &vars->img_y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x * 64, y * 64);
	ft_put_floor(vars, x, y);
	return (0);
}

int	ft_put_floor(t_vars *vars, int x, int y)
{
	vars->path = "./sprites/floor.xpm";
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &vars->img_x, &vars->img_y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x * 64, y * 64);
	return (0);
}

int	ft_delay(int *delay, int time)
{
	if (*delay <= time)
	{
		*delay += 1;
		return(1);
	}
	*delay = 0;
	return (0);
}

int	ft_animation(t_vars *vars, char *s2, int x, int y)
{
	char	*s1;

	s1 = (char *) malloc (sizeof(char) * 1);
	if (!s1)
		exit(1);
	s1[0] = '\0';
	ft_put_floor(vars, x, y);
	s1 = ft_strjoin(s1, s2);
	s1 = ft_strjoin(s1, ft_itoa(vars->index));
	vars->path = ft_strjoin(s1, ".xpm");
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &vars->img_x, &vars->img_y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x * 64, y * 64);
	free(s1);
	return (0);
}

int	ft_check_enemy_moves(t_vars *vars, int j)
{
	int	x;
	int	y;
	int	x1;
	int	y1;

	x = vars->pg_x - vars->n.enm_x[j];
	y = vars->pg_y - vars->n.enm_y[j];
	x1 = x;
	y1 = y;
	if (x1 < 0)
		x1 *= -1;
	if (y1 < 0)
		y1 *= -1;
	if (x1 > y1)
	{
		if (x < 0)
			vars->n.x_move[j] = -1;
		else
			vars->n.x_move[j] = 1;
		vars->n.y_move[j] = 0;
	}
	else
	{
		if (y < 0)
			vars->n.y_move[j] = -1;
		else
			vars->n.y_move[j] = 1;
		vars->n.x_move[j] = 0;
	}
	return (0);
}

int	ft_check_enemy_moves_b(t_vars *vars, int j)
{
	int	x;
	int	y;
	int	x1;
	int	y1;

	x = vars->pg_x - vars->n.enm_x[j];
	y = vars->pg_y - vars->n.enm_y[j];
	x1 = x;
	y1 = y;
	if (x1 < 0)
		x1 *= -1;
	if (y1 < 0)
		y1 *= -1;
	if (x1 < y1)
	{
		if (x < 0)
			vars->n.x_move[j] = -1;
		else
			vars->n.x_move[j] = 1;
		vars->n.y_move[j] = 0;
	}
	else
	{
		if (y < 0)
			vars->n.y_move[j] = -1;
		else
			vars->n.y_move[j] = 1;
		vars->n.x_move[j] = 0;
	}
	return (0);
}

int	ft_enemy_dir(t_vars *vars, int j, int i)
{
	if (vars->n.y_move[j] < 0 && vars->w.map[vars->n.enm_y[j] - 1][vars->n.enm_x[j]] != '1'
			&& (vars->w.map[vars->n.enm_y[j] - 1][vars->n.enm_x[j]] != 'E') && i != 1)
	{
		if (vars->w.map[vars->n.enm_y[j] + 1][vars->n.enm_x[j]] != '1')
			ft_put_floor(vars, vars->n.enm_x[j], vars->n.enm_y[j] + 1);
		ft_animation(vars, "./sprites/enemy/enemy_back", vars->n.enm_x[j], vars->n.enm_y[j]);
		if (i == 2)
		{
			vars->index = ++i;
			ft_animation(vars, "./sprites/enemy/enemy_back", vars->n.enm_x[j], vars->n.enm_y[j] - 1);
			vars->n.enm_y[j] -= 1;
		}
		return (0) ;
	}
	if (vars->n.y_move[j] > 0 && vars->w.map[vars->n.enm_y[j] + 1][vars->n.enm_x[j]] != '1'
			&& (vars->w.map[vars->n.enm_y[j] + 1][vars->n.enm_x[j]] != 'E') && i != 1)
	{
		if (vars->w.map[vars->n.enm_y[j] - 1][vars->n.enm_x[j]] != '1')
			ft_put_floor(vars, vars->n.enm_x[j], vars->n.enm_y[j] - 1);
		ft_animation(vars, "./sprites/enemy/enemy_front", vars->n.enm_x[j], vars->n.enm_y[j]);
		if (i == 2)
		{
			vars->index = ++i;
			ft_animation(vars, "./sprites/enemy/enemy_front", vars->n.enm_x[j], vars->n.enm_y[j] + 1);
			vars->n.enm_y[j] += 1;
		}
		return (0) ;
	}
	if (vars->n.x_move[j] < 0 && vars->w.map[vars->n.enm_y[j]][vars->n.enm_x[j] - 1] != '1'
			&& (vars->w.map[vars->n.enm_y[j]][vars->n.enm_x[j] - 1] != 'E') && i != 1)
	{
		if (vars->w.map[vars->n.enm_y[j]][vars->n.enm_x[j] + 1] != '1')
			ft_put_floor(vars, vars->n.enm_x[j] + 1, vars->n.enm_y[j]);
		ft_animation(vars, "./sprites/enemy/enemy_side_sx", vars->n.enm_x[j], vars->n.enm_y[j]);
		if (i == 2)
		{
			vars->index = ++i;
			ft_animation(vars, "./sprites/enemy/enemy_side_sx", vars->n.enm_x[j] - 1, vars->n.enm_y[j]);
			vars->n.enm_x[j] -= 1;
		}
		return (0) ;
	}
	if (vars->n.x_move[j] > 0 && vars->w.map[vars->n.enm_y[j]][vars->n.enm_x[j] + 1] != '1'
			&& (vars->w.map[vars->n.enm_y[j]][vars->n.enm_x[j] + 1] != 'E') && i != 1)
	{
		if (vars->w.map[vars->n.enm_y[j]][vars->n.enm_x[j] - 1] != '1')
			ft_put_floor(vars, vars->n.enm_x[j] - 1, vars->n.enm_y[j]);
		ft_animation(vars, "./sprites/enemy/enemy_side_dx", vars->n.enm_x[j], vars->n.enm_y[j]);
		if (i == 2)
		{
			vars->index = ++i;
			ft_animation(vars, "./sprites/enemy/enemy_side_dx", vars->n.enm_x[j] + 1, vars->n.enm_y[j]);
			vars->n.enm_x[j] += 1;
		}
		return (0) ;
	}
	return (0);
}

int	ft_enemy_animation(t_vars *vars)
{
	int			j;
	static int	i;

	j = 0;
	if (i > 4)
		i = 0;
	if (ft_delay(&vars->delay4, 2000) == 1)
		return (0);
	vars->index = i;
	while (j < vars->n.enm_count)
	{
		// if (vars->w.map[vars->n.enm_y[j]][vars->n.enm_x[j] - 1] == '1' && i == 1)
		// 	return (0);
		// if (vars->w.map[vars->n.enm_y[j]][vars->n.enm_x[j] + 1] != '1')
		// 	ft_put_floor(vars, vars->n.enm_x[j] + 1, vars->n.enm_y[j]);
		// ft_animation(vars, "./sprites/enemy/enemy_side_sx", vars->n.enm_x[j], vars->n.enm_y[j]);
		// if (i == 2)
		// {
		// 	vars->index = ++i;
		// 	ft_animation(vars, "./sprites/enemy/enemy_side_sx", vars->n.enm_x[j] - 1, vars->n.enm_y[j]);
		// 	vars->n.enm_x[j] -= 1;
		// }
		if (i == 0)
			ft_check_enemy_moves(vars, j);
		ft_enemy_dir(vars, j, i);
		j++;
	}
	i++;
	return (0);
}

int	ft_obj_animation(t_vars *vars)
{
	int			j;
	static int	i;

	j = 0;
	if (i > 5)
		i = 0;
	if (ft_delay(&vars->delay, 700) == 1)
		return (0);
	vars->index = i;
	while (j < vars->obj_count)
	{
		ft_animation(vars, "./sprites/coin", vars->obj_x[j], vars->obj_y[j]);
		j++;
	}
	i++;
	return (0);
}

int	ft_fade(t_vars *vars)
{
	static int	i;

	if (ft_delay(&vars->delay3, 1000) == 1)
	{
		return (1);
	}
	if (i < 7)
	{
		vars->index = i;
		ft_animation(vars, "./sprites/pg_fade/pg_fade", vars->ex_x, vars->ex_y);
		i++;
		return (1);
	}
	ft_endgame(vars);
	vars->pg_x += 1;
	i = 0;
	return (0);
}

int	ft_move_pg(t_vars *vars, int y, int x)
{
	ft_put_floor(vars, vars->pg_x, vars->pg_y);
	vars->pg_x += x;
	vars->pg_y += y;
	if (x > 0)
	{
		ft_check_obj(vars);
		if (vars->w.map[vars->pg_y][vars->pg_x] != 'E')
			ft_put_floor(vars, vars->pg_x, vars->pg_y);
		vars->path = "./sprites/player_dx.xpm";
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &vars->img_x, &vars->img_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
		ft_endgame(vars);
	}
	if (x < 0)
	{
		ft_check_obj(vars);
		if (vars->w.map[vars->pg_y][vars->pg_x] != 'E')
			ft_put_floor(vars, vars->pg_x, vars->pg_y);
		vars->path = "./sprites/player_sx.xpm";
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &vars->img_x, &vars->img_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
		ft_endgame(vars);
	}
	if (y > 0)
	{
		ft_check_obj(vars);
		if (vars->w.map[vars->pg_y][vars->pg_x] != 'E')
			ft_put_floor(vars, vars->pg_x, vars->pg_y);
		vars->path = "./sprites/player.xpm";
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &vars->img_x, &vars->img_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
		ft_endgame(vars);
	}
	if (y < 0)
	{
		ft_check_obj(vars);
		if (vars->w.map[vars->pg_y][vars->pg_x] != 'E')
			ft_put_floor(vars, vars->pg_x, vars->pg_y);
		vars->path = "./sprites/player_back.xpm";
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &vars->img_x, &vars->img_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
		ft_endgame(vars);
	}
	return (0);
}

int	ft_move_count(t_vars *vars, t_win *map)
{
	vars->moves += 1;
	vars->path = "./sprites/wall3.xpm";
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &vars->img_x, &vars->img_y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, (map->x - 1) * 64, 0);
	mlx_string_put(vars->mlx, vars->win, (map->x - 1) * 64.5, 30, 0xFF00, ft_itoa(vars->moves));
	return (0);
}
