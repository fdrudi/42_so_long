/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:50:50 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/11 20:03:33 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*path;
}				t_vars;

typedef struct s_win
{
	int		x;
	int		y;
	int		fd;
	char	**bool;
}				t_win;

int	ft_hook_loop(void *data)
{
	return (0);
}

int	ft_key_print(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	printf("Working !\n%d\n", keycode);
	return (0);
}

int	ft_mouse_print(int button, int x, int y, t_vars *vars)
{
	printf("Mouse Printing !\n%d\n", button);
	return (0);
}

int	ft_make_map(t_vars vars, t_win win_size, int img_x, int img_y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= win_size.y)
	{
		j = 0;
		while (j <= win_size.x)
		{
			if (win_size.bool[i][j] == 1)
			{
				vars.img = mlx_xpm_file_to_image(vars.mlx, vars.path, &img_x, &img_y);
				mlx_put_image_to_window(vars.mlx, vars.win, vars.img, i * 64, j * 64);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_win	win_size;
	int		img_x;
	int		img_y;

	vars.path = "./wall.xpm";
	vars.mlx = mlx_init();
	win_size.fd = open("./map.ber", O_RDONLY);
	win_size.bool[win_size.y] = "a";
	win_size.x = 0;
	win_size.y = 0;
	while (win_size.bool[win_size.y] != NULL)
	{
		win_size.bool[win_size.y] = ft_get_next_line(win_size.fd);
		if (win_size.bool[win_size.y] == NULL)
			break ;
		if (win_size.x == 0)
			win_size.x = ft_strlen(win_size.bool[win_size.y]);
		win_size.y++;
	}
	vars.win = mlx_new_window(vars.mlx, win_size.x * 64, win_size.y * 64, "Window Test");
	ft_make_map(vars, win_size, img_x, img_y);
	mlx_loop_hook(vars.mlx, ft_hook_loop, &vars);
	mlx_key_hook(vars.win, ft_key_print, &vars);
	mlx_mouse_hook(vars.win, ft_mouse_print, &vars);
	mlx_loop(vars.mlx);
}
