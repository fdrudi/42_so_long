/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:50:34 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/27 17:09:25 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_set_av_ac(t_env *e, int argc, char **argv)
{
	int	i;

	i = 0;
	e->w.ac = argc;
	e->w.av = (char **) malloc (sizeof(char *) * argc);
	if (!e->w.av)
		ft_error(e, "error : allocation error\n");
	while (i < argc)
	{
		e->w.av[i] = ft_strdup(argv[i]);
		i++;
	}
	return (0);
}

int	ft_min_nbr(int a, int b)
{
	if (a < 0 || b < 0)
		exit(1);
	if (a < b)
		return (a);
	if (b < a)
		return (b);
	else
		return (a);
}

char	*ft_strclean(char *str)
{
	char	*new;

	new = (char *) malloc (sizeof(char) * 1);
	if (!new)
		return (0);
	new[0] = '\0';
	free(str);
	return (new);
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
