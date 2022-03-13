/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:13:22 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/13 14:49:32 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s, char c)
{
	int		i;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	new = (char *) malloc (sizeof(char) * (ft_strlen_gnl(s) + 2));
	if (!new)
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i++] = c;
	new[i] = '\0';
	free(s);
	return (new);
}

char	*ft_read_line(int fd, char *dst)
{
	int		len;
	char	buf;

	len = 1;
	while (len != 0)
	{
		len = read(fd, &buf, 1);
		if (len == -1)
			return (NULL);
		dst = ft_strjoin_gnl(dst, buf);
	}
	if (!dst[1])
		return (NULL);
	return (dst);
}

char	**ft_get_next_matrix(int fd)
{
	char	**dst;
	char	*tmp;

	if (fd < 0)
		return (NULL);
	tmp = (char *) malloc (sizeof(char) * 1);
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	tmp = ft_read_line(fd, tmp);
	if (!tmp)
		return (NULL);
	dst = ft_split(tmp, '\n');
	free(tmp);
	return (dst);
}
