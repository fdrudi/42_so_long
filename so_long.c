/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:50:50 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/16 16:34:28 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

int	ft_hook_loop(t_vars *vars)
{
	ft_enemy_animation(vars);
	ft_obj_animation(vars);
	if (vars->obj_count == 0)
		ft_check_exit(vars);
	if (vars->w.map[vars->pg_y][vars->pg_x] == 'E')
		ft_fade(vars);
	return (0);
}

int	ft_close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	// ft_exit(vars);
	exit(0);
	return (0);
}

int	ft_start(t_vars *vars)
{
	char	*s1;

	s1 = (char *) malloc (sizeof(char) * 1);
	if (!s1)
		exit(1);
	s1[0] = '\0';
	s1 = ft_strjoin(s1, "./map");
	s1 = ft_strjoin(s1, ft_itoa(vars->next));
	s1 = ft_strjoin(s1, ".ber");
	vars->w.fd = open(s1, O_RDONLY);
	vars->w.map = ft_get_next_matrix(vars->w.fd);
	vars->w.y = ft_strlen_y(vars->w.map);
	vars->w.x = (int) ft_strlen(vars->w.map[0]);
	close(vars->w.fd);
	vars->delay = 0;
	vars->delay2 = 0;
	vars->delay3 = 0;
	vars->delay4 = 0;
	vars->index = 0;
	vars->end = 0;
	vars->moves = 0;
	vars->win = mlx_new_window(vars->mlx, vars->w.x * 64, vars->w.y * 64, "Window Test");
	ft_make_map(vars, &vars->img_x, &vars->img_y);
	mlx_string_put(vars->mlx, vars->win, (vars->w.x - 2) * 64, 20, 0xFFFFFF, "MOVES");
	mlx_string_put(vars->mlx, vars->win, (vars->w.x - 2) * 64, 40, 0xFFFFFF, "COUNT");
	mlx_hook(vars->win, 2, 1L<<0, ft_key_press, vars);
	mlx_hook(vars->win, 3, 1L<<1, ft_key_release, vars);
	mlx_hook(vars->win, 17, 0, ft_close_win, vars);
	return (0);
}

int	ft_next_level(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	vars->mlx = mlx_init();
	ft_start(vars);
	return (0);
}

int	ft_reset(t_vars *vars, int n)
{
	char	*s1;

	s1 = (char *) malloc (sizeof(char) * 1);
	if (!s1)
		exit(1);
	s1[0] = '\0';
	s1 = ft_strjoin(s1, "./map");
	s1 = ft_strjoin(s1, ft_itoa(n));
	s1 = ft_strjoin(s1, ".ber");
	vars->w.fd = open(s1, O_RDONLY);
	vars->w.map = ft_get_next_matrix(vars->w.fd);
	vars->w.y = ft_strlen_y(vars->w.map);
	vars->w.x = (int) ft_strlen(vars->w.map[0]);
	close(vars->w.fd);
	vars->delay = 0;
	vars->delay2 = 0;
	vars->delay3 = 0;
	vars->delay4 = 0;
	vars->index = 0;
	vars->end = 0;
	vars->moves = 0;
	free(s1);
	ft_make_map(vars, &vars->img_x, &vars->img_y);
	mlx_string_put(vars->mlx, vars->win, (vars->w.x - 2) * 64, 20, 0xFFFFFF, "MOVES");
	mlx_string_put(vars->mlx, vars->win, (vars->w.x - 2) * 64, 40, 0xFFFFFF, "COUNT");
	return (0);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	ft_exit(t_vars *vars)
{
	free_matrix(vars->w.map);
	free(vars->obj_x);
	free(vars->obj_y);
	// free(vars->path);
	free(vars->n.enm_x);
	free(vars->n.enm_y);
	free(vars->img);
	free(vars->win);
	free(vars->mlx);

}

int	ft_key_press(int keycode, t_vars *vars)
{
	if (keycode == 53)
		ft_close_win(vars);
	if (keycode == 15)
	{
		ft_reset(vars, vars->next);
		return (1);
	}
	if (vars->end == 1)
	{
		if (keycode == 36)
		{
			vars->next += 1;
			ft_next_level(vars);
			return (0);
		}
	}
	if (vars->end == 0)
	{
		if (keycode == 13 || keycode == 126)
		{
			ft_put_floor(vars, vars->pg_x, vars->pg_y);
			vars->path = "./sprites/player_back.xpm";
			vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &vars->img_x, &vars->img_y);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
		}
			if (keycode == 1 || keycode == 125)
		{
			ft_put_floor(vars, vars->pg_x, vars->pg_y);
			vars->path = "./sprites/player.xpm";
			vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &vars->img_x, &vars->img_y);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
		}
		if (keycode == 0 || keycode == 123)
		{
			ft_put_floor(vars, vars->pg_x, vars->pg_y);
			vars->path = "./sprites/player_sx.xpm";
			vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &vars->img_x, &vars->img_y);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
		}
		if (keycode == 2 || keycode == 124)
		{
			ft_put_floor(vars, vars->pg_x, vars->pg_y);
			vars->path = "./sprites/player_dx.xpm";
			vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &vars->img_x, &vars->img_y);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->pg_x * 64, vars->pg_y * 64);
		}
	}
	return (0);
}

int	ft_key_release(int keycode, t_vars *vars)
{
	if (vars->end == 0)
	{
		if ((keycode == 13 || keycode == 126) && vars->w.map[vars->pg_y - 1][vars->pg_x] != '1'
			&& (vars->w.map[vars->pg_y - 1][vars->pg_x] != 'E' || vars->obj_count == -1))
		{
			if (vars->lst_key != 1)
			{
				vars->lst_key = 1;
				return (0);
			}
			ft_move_pg(vars, -1, 0);
			ft_move_count(vars, &vars->w);
			vars->lst_key = 1;

		}
		if ((keycode == 1 || keycode == 125) && vars->w.map[vars->pg_y + 1][vars->pg_x] != '1'
			&& (vars->w.map[vars->pg_y + 1][vars->pg_x] != 'E' || vars->obj_count == -1))
		{
			if (vars->lst_key != 2)
			{
				vars->lst_key = 2;
				return (0);
			}
			ft_move_pg(vars, 1, 0);
			ft_move_count(vars, &vars->w);
			vars->lst_key = 2;

		}
		if ((keycode == 0 || keycode == 123) && vars->w.map[vars->pg_y][vars->pg_x - 1] != '1'
			&& (vars->w.map[vars->pg_y][vars->pg_x - 1] != 'E' || vars->obj_count == -1))
		{
			if (vars->lst_key != 3)
			{
				vars->lst_key = 3;
				return (0);
			}
			ft_move_pg(vars, 0, -1);
			ft_move_count(vars, &vars->w);
			vars->lst_key = 3;
		}
		if ((keycode == 2 || keycode == 124) && vars->w.map[vars->pg_y][vars->pg_x + 1] != '1'
			&& (vars->w.map[vars->pg_y][vars->pg_x + 1] != 'E' || vars->obj_count == -1))
		{
			if (vars->lst_key != 4)
			{
				vars->lst_key = 4;
				return (0);
			}
			ft_move_pg(vars, 0, 1);
			ft_move_count(vars, &vars->w);
			vars->lst_key = 4;
		}
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.next = 0;
	vars.n.x_move = (int *) malloc (sizeof(int) * 1);
	vars.n.y_move = (int *) malloc (sizeof(int) * 1);
	ft_start(&vars);

	mlx_loop_hook(vars.mlx, ft_hook_loop, &vars);
	mlx_hook(vars.win, 17, 0, ft_close_win, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
