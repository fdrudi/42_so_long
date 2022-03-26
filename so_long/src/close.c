/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:45:56 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/25 12:28:50 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(t_env *e, char *s)
{
	ft_putstr_fd(s, 2);
	ft_exit(e);
	exit(1);
}

void	ft_you_died(t_env *e)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	e->end = -1;
	e->w.m[e->p.pg_y][e->p.pg_x] = '0';
	e->p.pg_x = 0;
	e->p.pg_y = 0;
	while (i < e->n.n_c)
	{
		e->n.patr[i] = 0;
		i++;
	}
	ft_check_size_map3(e, &y, &x);
	e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
	mlx_put_image_to_window(e->mlx, e->win, e->img, x, y);
}

int	ft_close_win(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	ft_exit(e);
	exit(0);
	return (0);
}

void	ft_free_matrix(char **matrix, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	ft_exit(t_env *e)
{
	ft_free_matrix(e->w.m, e->w.y);
	free(e->obj_x);
	free(e->obj_y);
	free(e->n.n_x);
	free(e->n.n_y);
	if (e->n.n_m == 1)
	{
		free(e->n.patr);
		free(e->n.x_m);
		free(e->n.y_m);
		free(e->n.i);
	}
}
