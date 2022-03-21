/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <fdrudi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:50:50 by fdrudi            #+#    #+#             */
/*   Updated: 2022/03/21 17:44:37 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_hook_loop(t_env *e)
{
	if (e->win != NULL)
	{
		ft_obj_animation(e);
		if (e->end == 0)
		{
			ft_enemy_patrol(e);
			ft_enemy_animation(e);
			ft_enemy_attack(e);
		}
		if (e->obj_c == 0)
			ft_check_exit(e);
		if (e->w.m[e->pg_y][e->pg_x] == 'E')
			ft_fade(e);
	}
	return (0);
}

int	ft_key_act(t_env *e, int key)
{
	if ((key == 13 || key == 126) && e->w.m[e->pg_y - 1][e->pg_x] != '1'
			&& (e->w.m[e->pg_y - 1][e->pg_x] != 'E' || e->obj_c == -1))
	{
		ft_move_pg(e, -1, 0);
		ft_move_count(e, &e->w);
	}
	if ((key == 1 || key == 125) && e->w.m[e->pg_y + 1][e->pg_x] != '1'
		&& (e->w.m[e->pg_y + 1][e->pg_x] != 'E' || e->obj_c == -1))
	{
		ft_move_pg(e, 1, 0);
		ft_move_count(e, &e->w);
	}
	if ((key == 0 || key == 123) && e->w.m[e->pg_y][e->pg_x - 1] != '1'
		&& (e->w.m[e->pg_y][e->pg_x - 1] != 'E' || e->obj_c == -1))
	{
		ft_move_pg(e, 0, -1);
		ft_move_count(e, &e->w);
	}
	if ((key == 2 || key == 124) && e->w.m[e->pg_y][e->pg_x + 1] != '1'
		&& (e->w.m[e->pg_y][e->pg_x + 1] != 'E' || e->obj_c == -1))
	{
		ft_move_pg(e, 0, 1);
		ft_move_count(e, &e->w);
	}
	return (0);
}

int	ft_key_press(int key, t_env *e)
{
	if (key == 53)
		ft_close_win(e);
	else if (key == 15)
	{
		if (e->end == 2)
		{
			e->next = 0;
			ft_next_level(e);
		}
		else if (e->w.ac > 1)
			ft_reset_b(e);
		else
			ft_reset(e);
	}
	else if (e->end == 1)
	{
		if (key == 36)
		{
			e->next += 1;
			ft_next_level(e);
		}
	}
	else if (e->end == 0)
		ft_key_act(e, key);
	return (0);
}

// int	ft_key_release(int key, t_env *e)
// {
// 	if (e->end == 0)
// 	{
// 		if ((key == 13 || key == 126) && e->w.m[e->pg_y - 1][e->pg_x] != '1'
// 			&& (e->w.m[e->pg_y - 1][e->pg_x] != 'E' || e->obj_c == -1))
// 		{
// 			if (e->lst_key != 1)
// 			{
// 				e->lst_key = 1;
// 				return (0);
// 			}
// 			ft_move_pg(e, -1, 0);
// 			ft_move_count(e, &e->w);
// 			e->lst_key = 1;

// 		}
// 		if ((key == 1 || key == 125) && e->w.m[e->pg_y + 1][e->pg_x] != '1'
// 			&& (e->w.m[e->pg_y + 1][e->pg_x] != 'E' || e->obj_c == -1))
// 		{
// 			if (e->lst_key != 2)
// 			{
// 				e->lst_key = 2;
// 				return (0);
// 			}
// 			ft_move_pg(e, 1, 0);
// 			ft_move_count(e, &e->w);
// 			e->lst_key = 2;

// 		}
// 		if ((key == 0 || key == 123) && e->w.m[e->pg_y][e->pg_x - 1] != '1'
// 			&& (e->w.m[e->pg_y][e->pg_x - 1] != 'E' || e->obj_c == -1))
// 		{
// 			if (e->lst_key != 3)
// 			{
// 				e->lst_key = 3;
// 				return (0);
// 			}
// 			ft_move_pg(e, 0, -1);
// 			ft_move_count(e, &e->w);
// 			e->lst_key = 3;
// 		}
// 		if ((key == 2 || key == 124) && e->w.m[e->pg_y][e->pg_x + 1] != '1'
// 			&& (e->w.m[e->pg_y][e->pg_x + 1] != 'E' || e->obj_c == -1))
// 		{
// 			if (e->lst_key != 4)
// 			{
// 				e->lst_key = 4;
// 				return (0);
// 			}
// 			ft_move_pg(e, 0, 1);
// 			ft_move_count(e, &e->w);
// 			e->lst_key = 4;
// 		}
// 	}
// 	return (0);
// }

int	ft_set_av_ac(t_env *e, int argc, char **argv)
{
	int	i;

	i = 0;
	e->w.ac = argc;
	e->w.av = (char **) malloc (sizeof(char) * argc);
	if (!e->w.av)
		exit(1);
	while (i < argc)
	{
		e->w.av[i] = ft_substr(argv[i], 0, ft_strlen(argv[i]));
		i++;
	}
	e->w.av[i] = 0;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_env	e;

	e.mlx = mlx_init();
	if (e.mlx == NULL)
		ft_error(&e, "error : allocation error\n");
	e.next = 0;
	if (argc > 1)
	{
		ft_set_av_ac(&e, argc, argv);
		ft_start_b(&e);
	}
	else
	{
		e.w.ac = 1;
		ft_start(&e);
	}
	mlx_loop_hook(e.mlx, ft_hook_loop, &e);
	mlx_hook(e.win, 17, 0, ft_close_win, &e);
	mlx_loop(e.mlx);
	return (0);
}
