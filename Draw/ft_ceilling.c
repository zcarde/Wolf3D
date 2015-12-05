/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceilling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 22:36:36 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/10 21:07:45 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

void	draw_ceiling(t_var *vars, int x)
{
	int y;

	y = 0;
	while (y < vars->drawstart)
	{
		mlx_img_put(vars, x, y, 0x7ec0ee);
		y++;
	}
}
