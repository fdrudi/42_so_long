/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:44:04 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/28 12:18:18 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	ft_myinit(e);
	e->w.y = 0;
	e->w.x = 0;
	e->w.fd = open(e->w.av[e->next + 1], O_RDONLY);
	ft_get_next_matrix(e);
	close(e->w.fd);
	e->win = mlx_new_window(e->mlx, e->w.x * 64, e->w.y * 64, "Lost Dungeon");
	if (e->win == NULL)
	{
		free(e->win);
		ft_error(e, "error : allocation error\n");
	}
	ft_make_map(e);
	if (e->n.n_c > 0)
		ft_myinit2(e);
	mlx_string_put(e->mlx, e->win, (e->w.x - 2) * 64, 20, 0xFFFFFF, "MOVES");
	mlx_string_put(e->mlx, e->win, (e->w.x - 2) * 64, 40, 0xFFFFFF, "COUNT");
	mlx_hook(e->win, 2, 1L << 0, ft_key_press, e);
	mlx_hook(e->win, 17, 0, ft_close_win, e);
	return (0);
}

int	ft_start(t_env *e)
{
	ft_myinit(e);
	e->w.y = 0;
	e->w.x = 0;
	ft_map_path(e);
	e->w.fd = open(e->path, O_RDONLY);
	ft_get_next_matrix(e);
	close(e->w.fd);
	free(e->path);
	e->win = mlx_new_window(e->mlx, e->w.x * 64, e->w.y * 64, "Lost Dungeon");
	if (e->win == NULL)
	{
		free(e->win);
		ft_error(e, "error : allocation error\n");
	}
	ft_make_map(e);
	if (e->n.n_c > 0)
		ft_myinit2(e);
	mlx_string_put(e->mlx, e->win, (e->w.x - 2) * 64, 20, 0xFFFFFF, "MOVES");
	mlx_string_put(e->mlx, e->win, (e->w.x - 2) * 64, 40, 0xFFFFFF, "COUNT");
	mlx_hook(e->win, 2, 1L << 0, ft_key_press, e);
	mlx_hook(e->win, 17, 0, ft_close_win, e);
	return (0);
}

int	ft_reset_b(t_env *e)
{
	ft_exit(e);
	ft_myinit(e);
	e->w.y = 0;
	e->w.x = 0;
	e->w.fd = open(e->w.av[e->next + 1], O_RDONLY);
	ft_get_next_matrix(e);
	close(e->w.fd);
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
	e->w.y = 0;
	e->w.x = 0;
	ft_map_path(e);
	e->w.fd = open(e->path, O_RDONLY);
	ft_get_next_matrix(e);
	close(e->w.fd);
	free(e->path);
	ft_make_map(e);
	if (e->n.n_c > 0)
		ft_myinit2(e);
	mlx_string_put(e->mlx, e->win, (e->w.x - 2) * 64, 20, 0xFFFFFF, "MOVES");
	mlx_string_put(e->mlx, e->win, (e->w.x - 2) * 64, 40, 0xFFFFFF, "COUNT");
	return (0);
}
