/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 21:02:51 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/11 00:05:03 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

void	mlx_img_put(t_var *vars, int x, int y, int color)
{
	int		in;

	in = (vars->bpp >> 3) * ((y * (vars->line_siz >> 2)) + (int)x);
	if (in >= 0 && in <= (vars->bpp >> 3) * (((int)vars->ywin *
		(vars->line_siz >> 2)) + (int)vars->xwin) && in > (vars->bpp >> 3)
		* ((y * (vars->line_siz >> 2))) && in < (vars->bpp >> 3) * (((int)y *
		(vars->line_siz >> 2)) + vars->xwin))
	{
		vars->str[in + 0] = color & 0xff;
		vars->str[in + 1] = (color & 0xff00) >> 8;
		vars->str[in + 2] = (color & 0xff0000) >> 16;
	}
}

void	change_lvl(t_var *vars)
{
	int fd;

	vars->point += 100;
	vars->lvl += 1;
	if (vars->argv[vars->lvl])
	{
		ft_putstr("Next_lvl\n");
		fd = open(vars->argv[vars->lvl], O_RDONLY);
		ft_get_map(vars, vars->argv[vars->lvl], fd);
		init_var(vars);
	}
	else
	{
		ft_putstr("You win with ");
		ft_putnbr(vars->point);
		ft_putstr("points !\n");
		exit (0);
	}
}

void	clean_map(t_var *vars)
{
	int y;

	y = 0;
	while (y < vars->y_map)
	{
		free(vars->map[y]);
		vars->map[y] = NULL;
		y++;
	}
	free(vars->map);
}

void	key_space(t_var *vars)
{
	if (vars->hit == 2)
	{
		clean_map(vars);
		vars->map = NULL;
		change_lvl(vars);
	}
}
