/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:50:50 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/18 19:35:15 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

int	ft_hook_loop(t_env *e)
{
	ft_obj_animation(e);
	ft_enemy_patrol(e);
	ft_enemy_animation(e);
	if (e->obj_c == 0)
		ft_check_exit(e);
	if (e->w.m[e->pg_y][e->pg_x] == 'E')
		ft_fade(e);
	return (0);
}

int	ft_close_win(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	// ft_exit(e);
	exit(0);
	return (0);
}

int	ft_start(t_env *e)
{
	char	*s1;
	// int		i;

	s1 = (char *) malloc (sizeof(char) * 1);
	if (!s1)
		exit(1);
	s1[0] = '\0';
	s1 = ft_strjoin(s1, "./map");
	s1 = ft_strjoin(s1, ft_itoa(e->next));
	s1 = ft_strjoin(s1, ".ber");
	e->w.fd = open(s1, O_RDONLY);
	e->w.m = ft_get_next_matrix(e->w.fd);
	e->w.y = ft_strlen_y(e->w.m);
	e->w.x = (int) ft_strlen(e->w.m[0]);
	close(e->w.fd);
	e->d = 0;
	e->d2 = 0;
	e->d3 = 0;
	e->d4 = 0;
	e->d5 = 0;
	e->index = 0;
	e->end = 0;
	e->mv = 0;
	e->win = mlx_new_window(e->mlx, e->w.x * 64, e->w.y * 64, "Window Test");
	ft_make_map(e, &e->img_x, &e->img_y);
	mlx_string_put(e->mlx, e->win, (e->w.x - 2) * 64, 20, 0xFFFFFF, "MOVES");
	mlx_string_put(e->mlx, e->win, (e->w.x - 2) * 64, 40, 0xFFFFFF, "COUNT");
	// e->n.patr = (int *) malloc (sizeof(int) * e->n.n_c - 1);
	// i = -1;
	// while (++i <= e->n.n_c)
	// 	e->n.patr[i] = -1;
	mlx_hook(e->win, 2, 1L<<0, ft_key_press, e);
	// mlx_hook(e->win, 3, 1L<<1, ft_key_release, e);
	mlx_hook(e->win, 17, 0, ft_close_win, e);
	return (0);
}

int	ft_next_level(t_env *e)
{
	// ft_exit(e);
	mlx_destroy_window(e->mlx, e->win);
	e->mlx = mlx_init();
	ft_start(e);
	return (0);
}

int	ft_reset(t_env *e, int n)
{
	char	*s1;
	int		i;

	s1 = (char *) malloc (sizeof(char) * 1);
	if (!s1)
		exit(1);
	s1[0] = '\0';
	s1 = ft_strjoin(s1, "./map");
	s1 = ft_strjoin(s1, ft_itoa(n));
	s1 = ft_strjoin(s1, ".ber");
	e->w.fd = open(s1, O_RDONLY);
	e->w.m = ft_get_next_matrix(e->w.fd);
	e->w.y = ft_strlen_y(e->w.m);
	e->w.x = (int) ft_strlen(e->w.m[0]);
	close(e->w.fd);
	e->d = 0;
	e->d2 = 0;
	e->d3 = 0;
	e->d4 = 0;
	e->d5 = 0;
	e->index = 0;
	e->end = 0;
	e->mv = 0;
	free(s1);
	ft_make_map(e, &e->img_x, &e->img_y);
	mlx_string_put(e->mlx, e->win, (e->w.x - 2) * 64, 20, 0xFFFFFF, "MOVES");
	mlx_string_put(e->mlx, e->win, (e->w.x - 2) * 64, 40, 0xFFFFFF, "COUNT");
	e->n.patr = (int *) malloc (sizeof(int) * e->n.n_c - 1);
	i = -1;
	while (++i <= e->n.n_c)
		e->n.patr[i] = -1;
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

void	ft_exit(t_env *e)
{
	free_matrix(e->w.m);
	free(e->obj_x);
	free(e->obj_y);
	// free(e->path);
	free(e->n.n_x);
	free(e->n.n_y);
	free(e->img);
	free(e->win);
	free(e->mlx);
	free(e->n.n_x);
	free(e->n.n_y);
	// free(e->n.patr);
	free(e->n.x_m);
	free(e->n.y_m);
}

int	ft_key_act(t_env *e, int key)
{
	if ((key == 13 || key == 126) && e->w.m[e->pg_y - 1][e->pg_x] != '1'
			&& (e->w.m[e->pg_y - 1][e->pg_x] != 'E' || e->obj_c == -1))
	{
		ft_move_pg(e, -1, 0);
		ft_move_count(e, &e->w);
	}
	if ((key == 1 || key == 125) && e->w.m[e->pg_y + 1][e->pg_x] != '1'
		&& (e->w.m[e->pg_y + 1][e->pg_x] != 'E' || e->obj_c == -1))
	{
		ft_move_pg(e, 1, 0);
		ft_move_count(e, &e->w);
	}
	if ((key == 0 || key == 123) && e->w.m[e->pg_y][e->pg_x - 1] != '1'
		&& (e->w.m[e->pg_y][e->pg_x - 1] != 'E' || e->obj_c == -1))
	{
		ft_move_pg(e, 0, -1);
		ft_move_count(e, &e->w);

	}
	if ((key == 2 || key == 124) && e->w.m[e->pg_y][e->pg_x + 1] != '1'
		&& (e->w.m[e->pg_y][e->pg_x + 1] != 'E' || e->obj_c == -1))
	{
		ft_move_pg(e, 0, 1);
		ft_move_count(e, &e->w);
	}
	return (0);
}

int	ft_key_press(int key, t_env *e)
{
	if (key == 53)
		ft_close_win(e);
	if (key == 15)
	{
		ft_reset(e, e->next);
		return (1);
	}
	if (e->end == 1)
	{
		if (key == 36)
		{
			e->next += 1;
			ft_next_level(e);
			return (0);
		}
	}
	if (e->end == 0)
		ft_key_act(e, key);
	return (0);
}

// int	ft_key_release(int key, t_env *e)
// {
// 	if (e->end == 0)
// 	{
// 		if ((key == 13 || key == 126) && e->w.m[e->pg_y - 1][e->pg_x] != '1'
// 			&& (e->w.m[e->pg_y - 1][e->pg_x] != 'E' || e->obj_c == -1))
// 		{
// 			if (e->lst_key != 1)
// 			{
// 				e->lst_key = 1;
// 				return (0);
// 			}
// 			ft_move_pg(e, -1, 0);
// 			ft_move_count(e, &e->w);
// 			e->lst_key = 1;

// 		}
// 		if ((key == 1 || key == 125) && e->w.m[e->pg_y + 1][e->pg_x] != '1'
// 			&& (e->w.m[e->pg_y + 1][e->pg_x] != 'E' || e->obj_c == -1))
// 		{
// 			if (e->lst_key != 2)
// 			{
// 				e->lst_key = 2;
// 				return (0);
// 			}
// 			ft_move_pg(e, 1, 0);
// 			ft_move_count(e, &e->w);
// 			e->lst_key = 2;

// 		}
// 		if ((key == 0 || key == 123) && e->w.m[e->pg_y][e->pg_x - 1] != '1'
// 			&& (e->w.m[e->pg_y][e->pg_x - 1] != 'E' || e->obj_c == -1))
// 		{
// 			if (e->lst_key != 3)
// 			{
// 				e->lst_key = 3;
// 				return (0);
// 			}
// 			ft_move_pg(e, 0, -1);
// 			ft_move_count(e, &e->w);
// 			e->lst_key = 3;
// 		}
// 		if ((key == 2 || key == 124) && e->w.m[e->pg_y][e->pg_x + 1] != '1'
// 			&& (e->w.m[e->pg_y][e->pg_x + 1] != 'E' || e->obj_c == -1))
// 		{
// 			if (e->lst_key != 4)
// 			{
// 				e->lst_key = 4;
// 				return (0);
// 			}
// 			ft_move_pg(e, 0, 1);
// 			ft_move_count(e, &e->w);
// 			e->lst_key = 4;
// 		}
// 	}
// 	return (0);
// }

int	main(void)
{
	t_env	e;

	e.mlx = mlx_init();
	e.next = 0;
	e.n.x_m = (int *) malloc (sizeof(int) * 1);
	e.n.y_m = (int *) malloc (sizeof(int) * 1);

	ft_start(&e);
	e.n.patr = (int *) malloc (sizeof(int) * e.n.n_c - 1);
	int i = -1;
	while (++i <= e.n.n_c)
		e.n.patr[i] = -1;
	mlx_loop_hook(e.mlx, ft_hook_loop, &e);
	mlx_hook(e.win, 17, 0, ft_close_win, &e);
	mlx_loop(e.mlx);
	return (0);
}
