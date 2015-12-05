/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 21:51:11 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/10 21:07:56 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

void	ft_init_ray(t_var *vars, int x)
{
	vars->camerax = 2 * x / vars->width - 1;
	vars->raypos_x = vars->posx;
	vars->raypos_y = vars->posy;
	vars->raydir_x = vars->dirx + vars->planex * vars->camerax;
	vars->raydir_y = vars->diry + vars->planey * vars->camerax;
	vars->mapx = floor(vars->raypos_x);
	vars->mapy = floor(vars->raypos_y);
	vars->delta_dist_x = sqrt(1 + (vars->raydir_y * vars->raydir_y)
			/ (vars->raydir_x * vars->raydir_x));
	vars->delta_dist_y = sqrt(1 + (vars->raydir_x * vars->raydir_x)
			/ (vars->raydir_y * vars->raydir_y));
	vars->hit = 0;
}

void	ft_init_step(t_var *vars)
{
	if (vars->raydir_x < 0)
	{
		vars->stepx = -1;
		vars->side_dist_x = (vars->raypos_x - vars->mapx) * vars->delta_dist_x;
	}
	else
	{
		vars->stepx = 1;
		vars->side_dist_x = (vars->mapx + 1.0 - vars->raypos_x)
			* vars->delta_dist_x;
	}
	if (vars->raydir_y < 0)
	{
		vars->stepy = -1;
		vars->side_dist_y = (vars->raypos_y - vars->mapy)
			* vars->delta_dist_y;
	}
	else
	{
		vars->stepy = 1;
		vars->side_dist_y = (vars->mapy + 1.0 - vars->raypos_y)
			* vars->delta_dist_y;
	}
}

void	ft_draw(t_var *var)
{
	int x;

	x = 0;
	while (x < var->width)
	{
		ft_init_ray(var, x);
		ft_init_step(var);
		go_to_wall(var);
		size_wall(var);
		draw_wall(var, x);
		draw_ceiling(var, x);
		draw_floor(var, x);
		x++;
	}
}
