/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 21:57:48 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/11 00:15:14 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

void	go_to_wall(t_var *var)
{
	while (var->hit == 0 || var->hit == 3)
	{
		if (var->side_dist_x < var->side_dist_y)
		{
			var->side_dist_x += var->delta_dist_x;
			var->mapx += var->stepx;
			if (var->raydir_x > 0)
				var->side = 0;
			else
				var->side = 1;
		}
		else
		{
			var->side_dist_y += var->delta_dist_y;
			var->mapy += var->stepy;
			if (var->raydir_y > 0)
				var->side = 2;
			else
				var->side = 3;
		}
		var->hit = var->map[var->mapy][var->mapx];
	}
}

void	size_wall(t_var *var)
{
	if (var->side == 0 || var->side == 1)
		var->perp_wall_dist = fabs((var->mapx - var->raypos_x
					+ (1 - var->stepx) / 2) / var->raydir_x);
	else
		var->perp_wall_dist = fabs((var->mapy - var->raypos_y
					+ (1 - var->stepy) / 2) / var->raydir_y);
	var->lineheight = fabs(floor(var->heigth / var->perp_wall_dist)) * 2;
	var->drawstart = -var->lineheight / 2 + var->heigth / 2;
	if (var->drawstart < 0)
		var->drawstart = 0;
	var->drawend = var->lineheight / 2 + var->heigth / 2;
	if (var->drawend >= var->heigth)
		var->drawend = var->heigth;
}

void	init_wall(t_var *var)
{
	var->currentdist = 0;
	if (var->side == 2 || var->side == 3)
		var->wallx = var->raypos_x + ((var->mapy - var->raypos_y
					+ (1 - var->stepy) / 2) / var->raydir_y) * var->raydir_x;
	else
		var->wallx = var->raypos_y + ((var->mapx - var->raypos_x
					+ (1 - var->stepx) / 2) / var->raydir_x) * var->raydir_y;
	var->wallx -= floor((var->wallx));
	var->textx =
			(int)(var->wallx * (double)(var->wall->size)) % var->wall->size;
}

void	print_pixel_wall(t_var *var, int x, int y)
{
	int color;

	if (var->hit == 2)
		color = 0x908080;
	else if (var->lvl > 1)
	{
		color = get_xpm_color(var->wall, var->textx, var->texty);
		if (var->side == 0 || var->side == 3)
			color = (color >> 1) & 8355711;
	}
	else if (var->side == 0)
	{
		color = 0x809880;
	}
	else if (var->side == 1)
		color = 0x7080C0;
	else if (var->side == 2)
		color = 0xA08080;
	else
		color = 0x996699;
	mlx_img_put(var, x, y, color);
}

void	draw_wall(t_var *var, int x)
{
	int		y;
	int		d;

	init_wall(var);
	y = var->drawstart;
	while (y < var->drawend)
	{
		d = y * 256 - var->heigth * 128 + var->lineheight * 128;
		var->texty = (int)(((d * var->wall->line_siz) / var->lineheight) / 256)
					% var->wall->size;
		if (var->floortexy >= var->floor->size)
			var->floortexy = (int)var->floortexy % var->floor->size;
		if (var->floortexx >= var->floor->size)
			var->floortexx = (int)var->floortexx % var->floor->size;
		var->currentdist = var->heigth / (2 * y - var->heigth);
		print_pixel_wall(var, x, y);
		y++;
	}
}
