/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:34:58 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/27 17:43:49 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_map_path(t_env *e)
{
	char	*s1;
	char	*c;

	c = ft_itoa(e->next);
	s1 = ft_strjoin("./map/map", c);
	free(c);
	e->path = ft_strjoin(s1, ".ber");
	free(s1);
}

void	ft_myinit(t_env *e)
{
	e->d = 0;
	e->d2 = 0;
	e->d3 = 0;
	e->d4 = 0;
	e->d5 = 0;
	e->d6 = 0;
	e->p.d_mg = 0;
	e->p.d_ak = 0;
	e->end = 0;
	e->mv = 0;
	e->obj_c = 0;
	e->n.n_c = 0;
	e->lst_key = -1;
	e->p.pg_c = 0;
	e->p.x_p = 0;
	e->p.y_p = 0;
	e->p.atk = 0;
	e->p.atk_c = 0;
	e->n.n_m = 0;
}

void	ft_myinit2(t_env *e)
{
	int	i;

	e->n.x_m = (int *) malloc (sizeof(int) * e->n.n_c);
	e->n.y_m = (int *) malloc (sizeof(int) * e->n.n_c);
	e->n.patr = (int *) malloc (sizeof(int) * e->n.n_c);
	e->n.i = (int *) malloc (sizeof(int) * e->n.n_c);
	if (!e->n.patr || !e->n.i || !e->n.x_m || !e->n.y_m)
		ft_error(e, "error : allocation error\n");
	i = -1;
	while (++i < e->n.n_c)
	{
		e->n.patr[i] = 0;
		e->n.i[i] = 0;
	}
}

void	ft_myinit3(t_env *e)
{
	e->obj_x = (int *) malloc (sizeof(int) * e->obj_c);
	e->obj_y = (int *) malloc (sizeof(int) * e->obj_c);
	e->n.n_x = (int *) malloc (sizeof(int) * e->n.n_c);
	e->n.n_y = (int *) malloc (sizeof(int) * e->n.n_c);
	if (!e->obj_x || !e->obj_y || !e->n.n_x || !e->n.n_y)
		ft_error(e, "error : allocation error\n");
}
