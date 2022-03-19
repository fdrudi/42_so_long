/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:44:04 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/19 11:01:47 by fdrudi           ###   ########.fr       */
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
	e->index = 0;
	e->end = 0;
	e->mv = 0;
	e->obj_c = 0;
	e->n.n_c = 0;
}

int	ft_next_level(t_env *e)
{
	// ft_exit(e);
	mlx_destroy_window(e->mlx, e->win);
	e->mlx = mlx_init();
	ft_start(e);
	return (0);
}

int	ft_start(t_env *e)
{
	char	*s1;

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
	if (e->n.n_c != 0)
		free(e->n.patr);
	ft_myinit(e);
	e->win = mlx_new_window(e->mlx, e->w.x * 64, e->w.y * 64, "Window Test");
	ft_make_map(e);
	e->n.patr = (int *) malloc (sizeof(int) * e->n.n_c - 1);
	int i = -1;
	while (++i < e->n.n_c)
		e->n.patr[i] = 0;
	mlx_string_put(e->mlx, e->win, (e->w.x - 2) * 64, 20, 0xFFFFFF, "MOVES");
	mlx_string_put(e->mlx, e->win, (e->w.x - 2) * 64, 40, 0xFFFFFF, "COUNT");
	mlx_hook(e->win, 2, 1L << 0, ft_key_press, e);
	// mlx_hook(e->win, 3, 1L<<1, ft_key_release, e);
	mlx_hook(e->win, 17, 0, ft_close_win, e);
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
	ft_myinit(e);
	free(s1);
	ft_make_map(e);
	mlx_string_put(e->mlx, e->win, (e->w.x - 2) * 64, 20, 0xFFFFFF, "MOVES");
	mlx_string_put(e->mlx, e->win, (e->w.x - 2) * 64, 40, 0xFFFFFF, "COUNT");
	e->n.patr = (int *) malloc (sizeof(int) * e->n.n_c - 1);
	i = -1;
	while (++i <= e->n.n_c)
		e->n.patr[i] = -1;
	return (0);
}
