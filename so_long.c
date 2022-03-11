/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:50:50 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/11 14:25:06 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*path;
}				t_vars;

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

int	main(void)
{
	t_vars	vars;
	int		img_x;
	int		img_y;

	vars.path = "./file1.xpm";
	vars.mlx = mlx_init();
	vars.img = mlx_xpm_file_to_image(vars.mlx, vars.path, &img_x, &img_y);
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Window Test");
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 500, 500);
	mlx_loop_hook(vars.mlx, ft_hook_loop, &vars);
	mlx_key_hook(vars.win, ft_key_print, &vars);
	mlx_mouse_hook(vars.win, ft_mouse_print, &vars);
	mlx_loop(vars.mlx);
}
