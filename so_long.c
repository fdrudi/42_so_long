/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:50:50 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/13 18:32:55 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

int	ft_put_floor(t_vars *vars, int x, int y)
{
	int	img_x;
	int	img_y;

	vars->path = "./sprites/floor.xpm";
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &img_x, &img_y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x * 64, y * 64);
	return (0);
}

int	ft_hook_loop(t_vars *vars)
{
	char		*s1;
	int			img_x;
	int			img_y;
	int			j;
	static int	i;

	j = 0;
	if (i > 5)
		i = 0;
	s1 = (char *) malloc (sizeof(char) * 1);
	if (!s1)
		exit(1);
	s1[0] = '\0';
	while (j < vars->obj_count)
	{
		ft_put_floor(vars, vars->obj_x[j], vars->obj_y[j]);
		s1 = ft_strjoin(s1, "./sprites/coin");
		s1 = ft_strjoin(s1, ft_itoa(i));
		vars->path = ft_strjoin(s1, ".xpm");
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &img_x, &img_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->obj_x[j] * 64, vars->obj_y[j] * 64);
		s1 = ft_strclean(s1);
		j++;
	}
	i++;
	free(s1);
	return (0);
}

int	ft_strlen_y(char **s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
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

int	ft_move_pg(t_vars *vars, int y, int x)
{
	int	img_x;
	int	img_y;

	ft_put_floor(vars, vars->pg_x, vars->pg_y);
	vars->pg_x += x;
	vars->pg_y += y;
	if (x > 0)
	{
		ft_check_obj(vars);
		ft_put_floor(vars, vars->pg_x, vars->pg_y);
		vars->path = "./sprites/player_dx.xpm";
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &img_x, &img_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
	}
	if (x < 0)
	{
		ft_check_obj(vars);
		ft_put_floor(vars, vars->pg_x, vars->pg_y);
		vars->path = "./sprites/player_sx.xpm";
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &img_x, &img_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
	}
	if (y > 0)
	{
		ft_check_obj(vars);
		ft_put_floor(vars, vars->pg_x, vars->pg_y);
		vars->path = "./sprites/player.xpm";
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &img_x, &img_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
	}
	if (y < 0)
	{
		ft_check_obj(vars);
		ft_put_floor(vars, vars->pg_x, vars->pg_y);
		vars->path = "./sprites/player_back.xpm";
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &img_x, &img_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
	}
	return (0);

}

int	ft_key_press(int keycode, t_vars *vars)
{
	int	img_x;
	int	img_y;

	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == 13)
	{
		ft_put_floor(vars, vars->pg_x, vars->pg_y);
		vars->path = "./sprites/player_back.xpm";
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &img_x, &img_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
	}
	if (keycode == 1)
	{
		ft_put_floor(vars, vars->pg_x, vars->pg_y);
		vars->path = "./sprites/player.xpm";
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &img_x, &img_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
	}
	if (keycode == 0)
	{
		ft_put_floor(vars, vars->pg_x, vars->pg_y);
		vars->path = "./sprites/player_sx.xpm";
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &img_x, &img_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
	}
	if (keycode == 2)
	{
		ft_put_floor(vars, vars->pg_x, vars->pg_y);
		vars->path = "./sprites/player_dx.xpm";
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &img_x, &img_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
	}
	return (0);
}

int	ft_key_release(int keycode, t_vars *vars)
{
	if (keycode == 13 && vars->map[vars->pg_y - 1][vars->pg_x] != '1')
		ft_move_pg(vars, -1, 0);
	if (keycode == 1 && vars->map[vars->pg_y + 1][vars->pg_x] != '1')
		ft_move_pg(vars, 1, 0);
	if (keycode == 0 && vars->map[vars->pg_y][vars->pg_x - 1] != '1')
		ft_move_pg(vars, 0, -1);
	if (keycode == 2 && vars->map[vars->pg_y][vars->pg_x + 1] != '1')
		ft_move_pg(vars, 0, 1);
	return (0);
}

int	ft_make_map(t_vars *vars, int *img_x, int *img_y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	vars->obj_count = 0;
	vars->obj_x = (int *) malloc (sizeof(int) * 1);
	vars->obj_y = (int *) malloc (sizeof(int) * 1);
	if (!vars->obj_x || !vars->obj_y)
		exit(1);
	while (i < vars->y)
	{
		j = 0;
		while (j < vars->x)
		{
			if (vars->map[i][j] == '1')
			{
				if ((vars->map[i][j - 1] != '1' && vars->map[i][j + 1] != '1' && j > 0 && j < vars->x - 1) || i == 0 || i == vars->y -1)
				{
					vars->path = "./sprites/wall3.xpm";
					vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, img_x, img_y);
					mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 64, i * 64);
				}
				else
				{
					vars->path = "./sprites/wall4.xpm";
					vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, img_x, img_y);
					mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 64, i * 64);
				}
			}
			else
			{
				ft_put_floor(vars, j, i);
				if (vars->map[i][j] == 'P')
				{
					vars->path = "./sprites/player.xpm";
					vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, img_x, img_y);
					mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 64, i * 64);
					vars->pg_x = j;
					vars->pg_y = i;
				}
				if (vars->map[i][j] == 'C')
				{
					vars->path = "./sprites/coin0.xpm";
					vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, img_x, img_y);
					mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 64, i * 64);
					if (vars->obj_count == 0)
					{
						vars->obj_x[0] = j;
						vars->obj_y[0] = i;
					}
					else
					{
						vars->obj_x = ft_intjoin(vars->obj_x, j, vars->obj_count);
						vars->obj_y = ft_intjoin(vars->obj_y, i, vars->obj_count);
					}
					vars->obj_count += 1;
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;
	int		img_x;
	int		img_y;

	vars.mlx = mlx_init();
	vars.fd = open("./map.ber", O_RDONLY);
	vars.map = ft_get_next_matrix(vars.fd);
	vars.y = ft_strlen_y(vars.map);
	vars.x = (int) ft_strlen(vars.map[0]);

	vars.win = mlx_new_window(vars.mlx, vars.x * 64, vars.y * 64, "Window Test");
	vars.img = mlx_xpm_file_to_image(vars.mlx, vars.path, &img_x, &img_y);
	ft_make_map(&vars, &img_x, &img_y);
	mlx_loop_hook(vars.mlx, ft_hook_loop, &vars);
	mlx_hook(vars.win, 2, 1L<<0, ft_key_press, &vars);
	mlx_hook(vars.win, 3, 1L<<1, ft_key_release, &vars);
	mlx_loop(vars.mlx);
}
