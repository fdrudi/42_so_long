/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:06:15 by fdrudi            #+#    #+#             */
/*   Updated: 2022/01/15 12:35:04 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (c < 48 || c > 122 || (c < 'a' && c > 'Z') || (c < 65 && c > 57))
		return (0);
	return (1);
}
