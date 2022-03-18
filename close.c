/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:45:56 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/18 19:46:30 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_win(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	// ft_exit(e);
	exit(0);
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
