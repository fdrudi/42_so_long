/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:44:04 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/21 16:59:40 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	ft_myinit(e);
	ft_map_path(e);
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

int	ft_reset_b(t_env *e)
{
	ft_exit(e);
	ft_myinit(e);
	e->w.fd = open(e->w.av[e->next + 1], O_RDONLY);
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

int	ft_reset(t_env *e)
{
	ft_exit(e);
	ft_myinit(e);
	ft_map_path(e);
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
