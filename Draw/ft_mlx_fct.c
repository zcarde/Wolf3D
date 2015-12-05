/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_fct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 21:42:13 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/11 00:09:53 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

void	check_mouvement(t_var *vars)
{
	if (vars->up == 1)
		key_up(vars);
	if (vars->down == 1)
		key_down(vars);
	if (vars->left == 1)
		key_left(vars);
	if (vars->right == 1)
		key_right(vars);
}

int		loop_hook(t_var *vars)
{
	char *text;
	char *str;

	ft_draw(vars);
	check_mouvement(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	str = ft_itoa(vars->point);
	text = ft_strjoin("Score : ", str);
	mlx_string_put(vars->mlx, vars->win, 900, 550, 0xffffff, text);
	free(text);
	free(str);
	str = ft_itoa(vars->lvl);
	text = ft_strjoin("Level : ", str);
	mlx_string_put(vars->mlx, vars->win, 100, 550, 0xffffff, text);
	free(str);
	free(text);
	return (0);
}

int		expose_hook(t_var *var)
{
	mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
	return (0);
}

int		keypressed(int keycode, t_var *vars)
{
	if (keycode == UP)
		vars->up = 1;
	if (keycode == DOWN)
		vars->down = 1;
	if (keycode == LEFT)
		vars->left = 1;
	if (keycode == RIGHT)
		vars->right = 1;
	if (keycode == ESCAPE)
		key_esc();
	if (keycode == SHIFT)
		vars->move_s = 0.2;
	if (keycode == SPACE)
		key_space(vars);
	return (0);
}

int		keyreleased(int keycode, t_var *vars)
{
	if (keycode == UP)
		vars->up = 0;
	if (keycode == DOWN)
		vars->down = 0;
	if (keycode == LEFT)
		vars->left = 0;
	if (keycode == RIGHT)
		vars->right = 0;
	if (keycode == 65505)
		vars->move_s = 0.1;
	return (0);
}
