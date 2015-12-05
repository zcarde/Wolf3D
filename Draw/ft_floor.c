/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 22:26:30 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/10 21:08:07 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

void	init_floor(t_var *vars)
{
	vars->currentdist = 0;
	vars->wallx -= floor((vars->wallx));
	if (vars->side == 0)
	{
		vars->floorxwall = vars->mapx;
		vars->floorywall = vars->mapy + vars->wallx;
	}
	else if (vars->side == 1)
	{
		vars->floorxwall = vars->mapx + 1.0;
		vars->floorywall = vars->mapy + vars->wallx;
	}
	else if (vars->side == 2)
	{
		vars->floorxwall = vars->mapx + vars->wallx;
		vars->floorywall = vars->mapy;
	}
	else
	{
		vars->floorxwall = vars->mapx + vars->wallx;
		vars->floorywall = vars->mapy + 1.0;
	}
	if (vars->drawend < 0)
		vars->drawend = vars->heigth;
}

void	draw_floor_while(t_var *vars, int y, int x)
{
	double weight;

	if (vars->lvl > 1)
	{
		vars->currentdist = 2 * (vars->heigth / (2 * y - (int)vars->heigth));
		weight = (vars->currentdist - vars->dist_player)
					/ (vars->perp_wall_dist - vars->dist_player);
		vars->currentfloorx = fabs(weight * vars->floorxwall
					+ (1.0 - weight) * vars->posx);
		vars->currentfloory = fabs(weight * vars->floorywall
					+ (1.0 - weight) * vars->posy);
		vars->floortexx = (int)(vars->currentfloorx * vars->floor->line_siz)
					% vars->floor->size;
		vars->floortexy = (int)(vars->currentfloory * vars->floor->line_siz)
					% vars->floor->size;
		mlx_img_put(vars, x, y, get_xpm_color(vars->floor,\
					vars->floortexx, vars->floortexy));
	}
	else
		mlx_img_put(vars, x, y, 0xbbbbbb);
}

void	draw_floor(t_var *vars, int x)
{
	int		y;

	init_floor(vars);
	y = vars->drawend;
	while (y < (int)vars->heigth)
	{
		draw_floor_while(vars, y, x);
		y++;
	}
}
