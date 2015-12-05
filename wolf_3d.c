/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 21:29:27 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/10 22:59:37 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

int		get_xpm_color(t_xpm *xpm, int x, int y)
{
	int color;
	int in;

	in = (xpm->bpp >> 3) * ((y * (xpm->line_siz >> 2)) + x);
	color = xpm->str[in + 0];
	color += xpm->str[in + 1] << 8;
	color += xpm->str[in + 2] << 16;
	return (color);
}

t_xpm	*init_xpm(t_var *vars, char *file, int size)
{
	t_xpm	*xpm;

	xpm = (t_xpm *)malloc(sizeof(t_xpm) * 1);
	xpm->size = size;
	xpm->title = file;
	xpm->img = mlx_xpm_file_to_image(vars->mlx,
								file, &(xpm->size), &(xpm->size));
	xpm->str = mlx_get_data_addr(xpm->img,
								&(xpm->bpp), &(xpm->line_siz), &(xpm->endian));
	return (xpm);
}

void	init_var(t_var *var)
{
	var->width = 1024;
	var->heigth = 568;
	var->xwin = 1024;
	var->ywin = 568;
	var->img = mlx_new_image(var->mlx, var->xwin, var->ywin);
	var->str = mlx_get_data_addr(var->img, &(var->bpp),
			&(var->line_siz), &(var->endian));
	var->posx = 9;
	var->posy = 2;
	var->dirx = -0.0707;
	var->diry = 0.9974;
	var->planex = 0.658347;
	var->planey = 0.046687;
	var->move_s = 0.1;
	var->turn_s = 0.1;
	var->dist_player = 0.0;
}

void	ft_wolf_3d(t_var *var)
{
	var->point = 0;
	ft_draw(var);
	mlx_expose_hook(var->win, &expose_hook, var);
	mlx_loop_hook(var->mlx, &loop_hook, var);
	mlx_hook(var->win, 2, (1L << 0), &keypressed, var);
	mlx_hook(var->win, 3, (1L << 1), &keyreleased, var);
	mlx_loop(var->mlx);
}
