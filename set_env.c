/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:44:04 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/21 16:24:21 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_myinit(t_env *e)
{
	e->d = 0;
	e->d2 = 0;
	e->d3 = 0;
	e->d4 = 0;
	e->d5 = 0;
	e->d6 = 0;
	e->index = 0;
	e->end = 0;
	e->mv = 0;
	e->obj_c = 0;
	e->n.n_c = 0;
}

void	ft_myinit2(t_env *e)
{
	int	i;

	e->n.x_m = (int *) malloc (sizeof(int) * e->n.n_c - 1);
	e->n.y_m = (int *) malloc (sizeof(int) * e->n.n_c - 1);
	e->n.patr = (int *) malloc (sizeof(int) * e->n.n_c - 1);
	e->n.i = (int *) malloc (sizeof(int) * e->n.n_c - 1);
	if (!e->n.patr || !e->n.i || !e->n.x_m || !e->n.y_m)
		ft_error(e, "error : allocation error\n");
	i = -1;
	while (++i <= e->n.n_c)
	{
		e->n.patr[i] = 0;
		e->n.i[i] = 0;
	}
}

void	ft_myinit3(t_env *e)
{
	e->obj_x = (int *) malloc (sizeof(int) * 1);
	e->obj_y = (int *) malloc (sizeof(int) * 1);
	e->n.n_x = (int *) malloc (sizeof(int) * 1);
	e->n.n_y = (int *) malloc (sizeof(int) * 1);
	if (!e->obj_x || !e->obj_y || !e->n.n_x || !e->n.n_y)
		ft_error(e, "error : allocation error\n");
}

int	ft_next_level(t_env *e)
{
	ft_exit(e);
	mlx_destroy_window(e->mlx, e->win);
	e->mlx = mlx_init();
	if (!e->mlx)
		ft_error(e, "error : allocation error\n");
	if (e->w.ac == 1)
		ft_start(e);
	else
		ft_start_b(e);
	return (0);
}

int	ft_start_b(t_env *e)
{
	int	i;

	ft_myinit(e);
	e->w.fd = open(e->w.av[e->next + 1], O_RDONLY);
	e->w.m = ft_get_next_matrix(e->w.fd);
	e->w.y = ft_strlen_y(e->w.m);
	e->w.x = (int) ft_strlen(e->w.m[0]);
	close(e->w.fd);
	e->win = mlx_new_window(e->mlx, e->w.x * 64, e->w.y * 64, "Window Test");
	if (e->win == NULL)
	{
		free(e->win);
		ft_error(e, "error : allocation error\n");
	}
	ft_myinit3(e);
	ft_make_map(e);
	if (e->n.n_c > 0)
		ft_myinit2(e);
	mlx_string_put(e->mlx, e->win, (e->w.x - 2) * 64, 20, 0xFFFFFF, "MOVES");
	mlx_string_put(e->mlx, e->win, (e->w.x - 2) * 64, 40, 0xFFFFFF, "COUNT");
	mlx_hook(e->win, 2, 1L << 0, ft_key_press, e);
	// mlx_hook(e->win, 3, 1L<<1, ft_key_release, e);
	mlx_hook(e->win, 17, 0, ft_close_win, e);
	return (0);
}

int	ft_start(t_env *e)
{
	char	*s1;
	char	*c;

	ft_myinit(e);
	c = ft_itoa(e->next);
	s1 = ft_strjoin("./map", c);
	free(c);
	e->path = s1;
	free(s1);
	s1 = ft_strjoin(e->path, ".ber");
	e->path = s1;
	free(s1);
	e->w.fd = open(e->path, O_RDONLY);
	e->w.m = ft_get_next_matrix(e->w.fd);
	e->w.y = ft_strlen_y(e->w.m);
	e->w.x = (int) ft_strlen(e->w.m[0]);
	close(e->w.fd);
	e->win = mlx_new_window(e->mlx, e->w.x * 64, e->w.y * 64, "Window Test");
	if (e->win == NULL)
	{
		free(e->win);
		ft_error(e, "error : allocation error\n");
	}
	ft_myinit3(e);
	ft_make_map(e);
	if (e->n.n_c > 0)
		ft_myinit2(e);
	mlx_string_put(e->mlx, e->win, (e->w.x - 2) * 64, 20, 0xFFFFFF, "MOVES");
	mlx_string_put(e->mlx, e->win, (e->w.x - 2) * 64, 40, 0xFFFFFF, "COUNT");
	mlx_hook(e->win, 2, 1L << 0, ft_key_press, e);
	// mlx_hook(e->win, 3, 1L<<1, ft_key_release, e);
	mlx_hook(e->win, 17, 0, ft_close_win, e);
	return (0);
}

int	ft_reset_b(t_env *e, int n)
{

	ft_exit(e);
	ft_myinit(e);
	e->w.fd = open(e->w.av[n + 1], O_RDONLY);
	e->w.m = ft_get_next_matrix(e->w.fd);
	e->w.y = ft_strlen_y(e->w.m);
	e->w.x = (int) ft_strlen(e->w.m[0]);
	close(e->w.fd);
	ft_myinit3(e);
	ft_make_map(e);
	if (e->n.n_c > 0)
		ft_myinit2(e);
	mlx_string_put(e->mlx, e->win, (e->w.x - 2) * 64, 20, 0xFFFFFF, "MOVES");
	mlx_string_put(e->mlx, e->win, (e->w.x - 2) * 64, 40, 0xFFFFFF, "COUNT");
	return (0);
}

int	ft_reset(t_env *e, int n)
{
	char	*s1;
	char	*c;

	ft_exit(e);
	ft_myinit(e);
	c = ft_itoa(e->next);
	s1 = ft_strjoin("./map", c);
	free(c);
	e->path = s1;
	free(s1);
	s1 = ft_strjoin(e->path, ".ber");
	e->path = s1;
	free(s1);
	e->w.fd = open(e->path, O_RDONLY);
	e->w.m = ft_get_next_matrix(e->w.fd);
	e->w.y = ft_strlen_y(e->w.m);
	e->w.x = (int) ft_strlen(e->w.m[0]);
	close(e->w.fd);
	ft_myinit3(e);
	ft_make_map(e);
	if (e->n.n_c > 0)
		ft_myinit2(e);
	mlx_string_put(e->mlx, e->win, (e->w.x - 2) * 64, 20, 0xFFFFFF, "MOVES");
	mlx_string_put(e->mlx, e->win, (e->w.x - 2) * 64, 40, 0xFFFFFF, "COUNT");
	return (0);
}
