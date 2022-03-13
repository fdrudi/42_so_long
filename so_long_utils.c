/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:50:34 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/13 18:15:09 by fdrudi           ###   ########.fr       */
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