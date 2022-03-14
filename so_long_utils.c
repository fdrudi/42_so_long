/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:50:34 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/14 16:53:13 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*ft_intjoin(int *str, int new, int size)
{
	int	*dst;
	int	i;

	i = 0;
	if (!str)
		return (0);
	dst = (int *) malloc (sizeof(int) * size + 1);
	if (!dst)
		return (0);
	while (i < size)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = new;
	free(str);
	return (dst);
}

char	*ft_strclean(char *str)
{
	char	*new;

	new = (char *) malloc (sizeof(char) * 1);
	if (!new)
		return (0);
	new[0] = '\0';
	free(str);
	return(new);
}

int	ft_move_count(t_vars *vars, t_win *map)
{
	static int	moves;

	moves += 1;
	vars->path = "./sprites/wall3.xpm";
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path, &vars->img_x, &vars->img_y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, (map->x - 1) * 64, 0);
	mlx_string_put(vars->mlx, vars->win, (map->x - 1) * 64.5, 30, 0xFF00, ft_itoa(moves));
	return (0);
}

int	*ft_int_trim(int *str, int pos, int size)
{
	int	i;
	int	j;
	int	*dst;

	i = 0;
	j = 0;
	dst = (int *) malloc (sizeof(int) * size - 1);
	if (!dst)
		return (0);
	while (i < size - 1)
	{
		if (i == pos)
			j++;
		dst[i] = str[j];
		i++;
		j++;
	}
	free(str);
	return (dst);
}
