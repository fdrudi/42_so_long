/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:23:40 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/27 17:42:51 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_animate_b(t_env *e, char *s2, int x, int y, int index)
{
	char	*s1;
	char	*c;

	c = ft_itoa(index);
	s1 = ft_strjoin(s2, c);
	free(c);
	e->path = ft_strjoin(s1, ".xpm");
	free(s1);
	e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
	mlx_put_image_to_window(e->mlx, e->win, e->img, x * 64, y * 64);
	free(e->path);
	return (0);
}

int	ft_animate(t_env *e, char *s2, int x, int y, int index)
{
	char	*s1;
	char	*c;

	ft_put_floor(e, x, y);
	c = ft_itoa(index);
	s1 = ft_strjoin(s2, c);
	free(c);
	e->path = ft_strjoin(s1, ".xpm");
	free(s1);
	e->img = mlx_xpm_file_to_image(e->mlx, e->path, &e->i_x, &e->i_y);
	mlx_put_image_to_window(e->mlx, e->win, e->img, x * 64, y * 64);
	free(e->path);
	return (0);
}

int	ft_obj_animation(t_env *e)
{
	int			j;
	static int	i;

	j = 0;
	if (i > 5)
		i = 0;
	if (ft_delay(&e->d, 1000) == 1)
		return (0);
	while (j < e->obj_c)
	{
		ft_animate(e, "./spr/obj/coin", e->obj_x[j], e->obj_y[j], i);
		j++;
	}
	i++;
	return (0);
}
