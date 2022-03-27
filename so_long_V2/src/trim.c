int	*ft_int_dup(int *str, int size)
{
	int	*dst;
	int	i;

	i = -1;
	dst = (int *) malloc (sizeof(int) * size);
	if (!dst)
		exit (1);
	while (++i < size)
		dst[i] = str[i];
	return (dst);
}

int	*ft_trim(int *str, int pos, int size)
{
	int	i;
	int	j;
	int	*dst;

	i = 0;
	j = 0;
	dst = (int *) malloc (sizeof(int) * size - 1);
	if (!dst)
		exit(1);
	while (i < size - 1)
	{
		if (i == pos)
			j++;
		dst[i] = str[j];
		i++;
		j++;
	}
	return (dst);
}

void	ft_int_trim_obj_y(t_env *e, int pos, int size)
{
	int	*dst;

	dst = ft_int_dup(e->obj_y, size);
	if (!dst)
		exit(1);
	free(e->obj_y);
	e->obj_y = ft_trim(dst, pos, size);
	free(dst);
}

void	ft_int_trim_obj_x(t_env *e, int pos, int size)
{
	int	*dst;

	dst = ft_int_dup(e->obj_x, size);
	if (!dst)
		exit(1);
	free(e->obj_x);
	e->obj_x = ft_trim(dst, pos, size);
	free(dst);
}
