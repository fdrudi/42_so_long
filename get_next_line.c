/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:13:22 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/11 18:14:04 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 42

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s, char c)
{
	int		i;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	new = (char *) malloc (sizeof(char) * (ft_strlen(s) + 2));
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
	while (len != 0 && buf != '\n')
	{
		len = read(fd, &buf, BUFFER_SIZE * 0 + 1);
		if (len == -1)
			return (NULL);
		dst = ft_strjoin(dst, buf);
	}
	if (dst[0] == '\n')
		return ("\n");
	if (!dst[1])
		return (NULL);
	return (dst);
}

char	*ft_get_next_line(int fd)
{
	char	*dst;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	dst = (char *) malloc (sizeof(char) * 1);
	if (!dst)
		return (NULL);
	dst[0] = '\0';
	dst = ft_read_line(fd, dst);
	if (!dst)
		return (NULL);
	return (dst);
}
