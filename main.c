/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 03:54:38 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/10 22:59:46 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

int	main(int argc, char **argv)
{
	t_var	var;
	int		fd;

	var.argv = argv;
	if (argc >= 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			ft_putstr("Le fichier n'existe pas\n");
		else
		{
			var.mlx = mlx_init();
			var.win = mlx_new_window(var.mlx, 1024, 568, "Wolf 3d");
			var.lvl = 1;
			var.floor = init_xpm(&var, "grass.xpm", 64);
			var.wall = init_xpm(&var, "plank.xpm", 64);
			ft_get_map(&var, argv[1], fd);
			init_var(&var);
			ft_wolf_3d(&var);
		}
	}
	else
		ft_putstr("usage : ./wolf_3d [maps lvl1, lvl2 ...]\n");
	return (0);
}
