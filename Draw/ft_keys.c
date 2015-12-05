/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 22:52:06 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/10 21:08:16 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

void	key_up(t_var *vars)
{
	if (vars->map[(int)floor(vars->posy)][(int)floor(vars->posx + vars->dirx *
		vars->move_s)] == 0 || vars->map[(int)floor(vars->posy)]
		[(int)floor(vars->posx + vars->dirx * vars->move_s)] == 3)
		vars->posx += vars->dirx * vars->move_s;
	if (vars->map[(int)floor(vars->posy + vars->diry * vars->move_s)]
		[(int)floor(vars->posx)] == 0 || vars->map[(int)floor(vars->posy +
		vars->diry * vars->move_s)][(int)floor(vars->posx)] == 3)
		vars->posy += vars->diry * vars->move_s;
	if (vars->map[(int)floor(vars->posy + vars->diry * vars->move_s)]
			[(int)floor(vars->posx)] == 3)
	{
		vars->map[(int)floor(vars->posy + vars->diry * vars->move_s)]
			[(int)floor(vars->posx)] = 0;
		vars->point += 10;
	}
}

void	key_down(t_var *vars)
{
	if (vars->map[(int)floor(vars->posy)][(int)floor(vars->posx - vars->dirx *
		vars->move_s)] == 0 || vars->map[(int)floor(vars->posy)]
		[(int)floor(vars->posx - vars->dirx * vars->move_s)] == 3)
		vars->posx -= vars->dirx * vars->move_s;
	if (vars->map[(int)floor(vars->posy - vars->diry * vars->move_s)]
			[(int)floor(vars->posx)] == 0 || vars->map[(int)floor(vars->posy -
			vars->diry * vars->move_s)][(int)floor(vars->posx)] == 3)
		vars->posy -= vars->diry * vars->move_s;
	if (vars->map[(int)floor(vars->posy + vars->diry * vars->move_s)]
			[(int)floor(vars->posx)] == 3)
	{
		vars->map[(int)floor(vars->posy + vars->diry * vars->move_s)]
		[(int)floor(vars->posx)] = 0;
		vars->point += 10;
	}
}

void	key_left(t_var *vars)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = vars->dirx;
	vars->dirx = vars->dirx * cos(vars->turn_s)
		- vars->diry * sin(vars->turn_s);
	vars->diry = old_dir_x * sin(vars->turn_s)
		+ vars->diry * cos(vars->turn_s);
	old_plane_x = vars->planex;
	vars->planex = vars->planex * cos(vars->turn_s)
		- vars->planey * sin(vars->turn_s);
	vars->planey = old_plane_x * sin(vars->turn_s)
		+ vars->planey * cos(vars->turn_s);
}

void	key_right(t_var *vars)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = vars->dirx;
	vars->dirx = vars->dirx * cos(-vars->turn_s)
		- vars->diry * sin(-vars->turn_s);
	vars->diry = old_dir_x * sin(-vars->turn_s)
		+ vars->diry * cos(-vars->turn_s);
	old_plane_x = vars->planex;
	vars->planex = vars->planex * cos(-vars->turn_s)
		- vars->planey * sin(-vars->turn_s);
	vars->planey = old_plane_x * sin(-vars->turn_s)
		+ vars->planey * cos(-vars->turn_s);
}

void	key_esc(void)
{
	exit(0);
}
