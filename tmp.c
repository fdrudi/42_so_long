int	ft_check_enemy_moves(t_vars *vars, int i)
{
	int	x;
	int	y;
	int	x1;
	int	y1;

	x = vars->pg_x - vars->n.enm_x[i];
	y = vars->pg_y - vars->n.enm_y[i];
	x1 = x;
	y1 = y;
	if (x1 < 0)
		x1 *= -1;
	if (y1 < 0)
		y1 *= -1;
	if (x1 > y1)
	{
		if (x < 0)
			vars->n.x_move = -1;
		else
			vars->n.x_move = 1;
		vars->n.y_move = 0;
	}
	if (y1 > x1)
	{
		if (y < 0)
			vars->n.y_move = -1;
		else
			vars->n.y_move = 1;
		vars->n.x_move = 0;
	}
	return (0);
}

int	ft_enemy_dir(t_vars *vars, int j, int i)
{
	if (vars->n.y_move[j] < 0 && vars->w.map[vars->n.enm_y[j] - 1][vars->n.enm_x[j]] != '1'
			&& (vars->w.map[vars->n.enm_y[j] - 1][vars->n.enm_x[j]] != 'E') && i == 1)
	{
		if (vars->w.map[vars->n.enm_y[j] + 1][vars->n.enm_x[j]] != '1')
			ft_put_floor(vars, vars->n.enm_x[j], vars->n.enm_y[j] + 1);
		if (i == 2)
		{
			ft_animation(vars, "./sprites/enemy/enemy_back", vars->n.enm_x[j], vars->n.enm_y[j]);
			i++;
			vars->index = i;
			ft_animation(vars, "./sprites/enemy/enemy_back", vars->n.enm_x[j], vars->n.enm_y[j] - 1);
			vars->n.enm_y[j] -= 1;
		}
		else
			ft_animation(vars, "./sprites/enemy/enemy_back", vars->n.enm_x[j], vars->n.enm_y[j]);
	}
	if (vars->n.y_move[j] > 0 && vars->w.map[vars->n.enm_y[j] + 1][vars->n.enm_x[j]] != '1'
			&& (vars->w.map[vars->n.enm_y[j] + 1][vars->n.enm_x[j]] != 'E'))
	{
		if (vars->w.map[vars->n.enm_y[j] - 1][vars->n.enm_x[j]] != '1')
			ft_put_floor(vars, vars->n.enm_x[j], vars->n.enm_y[j] - 1);
		if (i == 2)
		{
			ft_animation(vars, "./sprites/enemy/enemy_back", vars->n.enm_x[j], vars->n.enm_y[j]);
			i++;
			vars->index = i;
			ft_animation(vars, "./sprites/enemy/enemy_back", vars->n.enm_x[j], vars->n.enm_y[j] - 1);
			vars->n.enm_y[j] -= 1;
		}
		else
			ft_animation(vars, "./sprites/enemy/enemy_back", vars->n.enm_x[j], vars->n.enm_y[j]);
	}
	if (vars->n.x_move[i] < 0 && vars->w.map[vars->n.enm_y[j]][vars->n.enm_x[j] - 1] != '1'
			&& (vars->w.map[vars->n.enm_y[j]][vars->n.enm_x[j] - 1] != 'E'))
	{

	}
	if (vars->n.x_move[i] > 0 && vars->w.map[vars->n.enm_y[j]][vars->n.enm_x[j] + 1] != '1'
			&& (vars->w.map[vars->n.enm_y[j]][vars->n.enm_x[j] + 1] != 'E'))
	{

	}
	return (0);
}
