/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 23:05:30 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/10 21:07:32 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

int			check_last_lane(char *line, int jmax)
{
	int		j;
	char	**split;

	j = 0;
	split = ft_strsplit(line, ' ');
	while (split[j] != 0)
		j++;
	if (j != jmax && j != 0)
	{
		ft_putstr("Map error\n");
		exit(-1);
	}
	j = 0;
	while (split[j])
	{
		free(split[j]);
		j++;
	}
	free(split);
	return (j == 0 ? 0 : 1);
}

void		get_map_size(int fd, int *x_map, int *y_map)
{
	int		j;
	char	*line;
	char	**split;

	*x_map = 0;
	*y_map = 0;
	while (get_next_line(fd, &line) == 1)
	{
		j = 0;
		split = ft_strsplit_pp(line, &ft_isspace);
		while (split[j] != 0)
			j++;
		if (*y_map != 0 && j != *x_map)
		{
			ft_putstr("Map error\n");
			exit(-1);
		}
		*x_map = j;
		(*y_map)++;
		free(line);
		free(split);
	}
	*y_map += check_last_lane(line, *x_map);
	free(line);
}

void		ft_get_map(t_var *var, char *str, int fd)
{
	int		y;
	int		x;
	char	*line;
	char	**split;
	int		j;

	get_map_size(fd, &(var->x_map), &(var->y_map));
	close(fd);
	fd = open(str, O_RDONLY);
	var->map = (int **)malloc(sizeof(int *) * (var->y_map));
	y = 0;
	while (y < var->y_map)
	{
		var->map[y] = (int *)malloc(sizeof(int) * (var->x_map));
		get_next_line(fd, &line);
		split = ft_strsplit_pp(line, &ft_isspace);
		x = -1;
		while (++x < var->x_map)
			var->map[y][x] = ft_atoi(split[x]);
		free(split);
		free(line);
		y++;
	}
	close(fd);
}
