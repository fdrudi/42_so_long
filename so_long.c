/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:50:50 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/13 12:55:57 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

int	ft_hook_loop(t_vars *vars)
{
	char *s = ft_strjoin("./sprites/floor", ft_itoa(n));
	char *s1 = ft_strjoin(s, ".xpm");
	vars->path = "./sprites/floor.xpm";
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &img_x, &img_y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
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

int	ft_move_pg(t_vars *vars, int y, int x)
{
	int	img_x;
	int	img_y;

	vars->path = "./sprites/floor.xpm";
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &img_x, &img_y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);

	vars->pg_x += x;
	vars->pg_y += y;
	if (x > 0)
	{
		vars->path = "./sprites/player_dx.xpm";
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &img_x, &img_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
	}
	if (x < 0)
	{
		vars->path = "./sprites/player_sx.xpm";
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &img_x, &img_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
	}
	if (y > 0)
	{
		vars->path = "./sprites/player.xpm";
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &img_x, &img_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
	}
	if (y < 0)
	{
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
		vars->path = "./sprites/floor.xpm";
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &img_x, &img_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
		vars->path = "./sprites/player_back.xpm";
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &img_x, &img_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
	}
	if (keycode == 1)
	{
		vars->path = "./sprites/floor.xpm";
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &img_x, &img_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
		vars->path = "./sprites/player.xpm";
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &img_x, &img_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
	}
	if (keycode == 0)
	{
		vars->path = "./sprites/floor.xpm";
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &img_x, &img_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
		vars->path = "./sprites/player_sx.xpm";
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &img_x, &img_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
	}
	if (keycode == 2)
	{
		vars->path = "./sprites/floor.xpm";
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &img_x, &img_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
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
			if (vars->map[i][j] == '0' || vars->map[i][j] == 'C' || vars->map[i][j] == 'N' || vars->map[i][j] == 'E')
			{
				vars->path = "./sprites/floor.xpm";
				vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, img_x, img_y);
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 64, i * 64);
			}
			if (vars->map[i][j] == 'P')
			{
				vars->path = "./sprites/floor.xpm";
				vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, img_x, img_y);
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 64, i * 64);
				vars->path = "./sprites/player.xpm";
				vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, img_x, img_y);
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 64, i * 64);
				vars->pg_x = j;
				vars->pg_y = i;
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
	vars.x = ft_strlen(vars.map[0]);

	vars.win = mlx_new_window(vars.mlx, vars.x * 64, vars.y * 64, "Window Test");
	vars.img = mlx_xpm_file_to_image(vars.mlx, vars.path, &img_x, &img_y);
	ft_make_map(&vars, &img_x, &img_y);
	mlx_loop_hook(vars.mlx, ft_hook_loop, &vars);
	mlx_hook(vars.win, 2, 1L<<0, ft_key_press, &vars);
	mlx_hook(vars.win, 3, 1L<<1, ft_key_release, &vars);
	mlx_loop(vars.mlx);
}
