/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:13:22 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/25 11:00:27 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

char	*ft_read_line(t_env *e, char *dst)
{
	int		len;
	char	buf;
	int		i;

	i = 0;
	len = 1;
	while (len != 0)
	{
		len = read(e->w.fd, &buf, 1);
		if (len == -1)
			ft_error(e, "error : read error\n");
		if (buf == '\n')
			i = 1;
		if (i == 0)
			e->w.x += 1;
		dst = ft_strjoin_gnl(dst, buf);
	}
	if (!dst[1])
		return (NULL);
	return (dst);
}

void	ft_get_next_matrix(t_env *e)
{
	char	*tmp;

	if (e->w.fd < 0)
		ft_error(e, "error : invalid map\n");
	tmp = (char *) malloc (sizeof(char) * 1);
	if (!tmp)
		ft_error(e, "error : allocation error\n");
	tmp[0] = '\0';
	tmp = ft_read_line(e, tmp);
	if (!tmp)
		ft_error(e, "error : allocation error\n");
	e->w.y = ft_nb_words(tmp, '\n');
	e->w.m = ft_split(tmp, '\n');
	free(tmp);
	return ;
}
