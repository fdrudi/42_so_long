/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:06:24 by fdrudi            #+#    #+#             */
/*   Updated: 2022/01/15 12:48:48 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c < 'a' && c > 'Z') || (c < 'A') || (c > 'z'))
		return (0);
	return (1);
}
