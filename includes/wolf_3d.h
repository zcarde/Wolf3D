/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 19:14:01 by mel-mouk          #+#    #+#             */
/*   Updated: 2015/03/10 23:57:36 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_3D_H
# define WOLF_3D_H
# include <math.h>
# include <stdlib.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

// # define LEFT 123
// # define RIGHT 124
// # define UP 126
// # define DOWN 125
// # define ESCAPE 53
// # define SHIFT 257
// # define SPACE 49

# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define ESCAPE 65307
# define SHIFT 65505
# define SPACE 32


typedef struct	s_xpm
{
	void		*img;
	char		*str;
	int			bpp;
	int			line_siz;
	int			endian;
	int			size;
	char		*title;
}				t_xpm;

typedef struct	s_var
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*str;
	int			bpp;
	int			line_siz;
	int			endian;
	int			**map;
	char		**argv;
	int			lvl;
	int			lvlmax;
	int			xwin;
	int			ywin;
	double		width;
	double		heigth;
	int			x_map;
	int			y_map;
	double		posy;
	double		posx;
	double		dirx;
	double		diry;
	double		move_s;
	double		turn_s;
	double		planex;
	double		planey;
	double		camerax;
	double		raypos_x;
	double		raypos_y;
	double		raydir_x;
	double		raydir_y;
	int			mapx;
	int			mapy;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	float		lineheight;
	int			drawstart;
	int			drawend;
	int			color;
	double		wallx;
	double		currentdist;
	double		dist_player;
	double		currentfloorx;
	double		currentfloory;
	double		floortexx;
	double		floortexy;
	double		floorxwall;
	double		floorywall;
	int			textx;
	int			texty;
	t_xpm		*floor;
	t_xpm		*wall;
	int			up;
	int			down;
	int			left;
	int			right;
	int			point;
}				t_var;

void			ft_get_map(t_var *var, char *str, int fd);
void			init_var(t_var *var);
void			ft_wolf_3d(t_var *var);
/*
** Fonction mlx et dessin
*/
void			mlx_img_put(t_var *vars, int x, int y, int color);
int				expose_hook(t_var *var);
int				loop_hook(t_var *vars);
int				keypressed(int keycode, t_var *vars);
int				keyreleased(int keycode, t_var *vars);
void			ft_draw(t_var *var);
void			go_to_wall(t_var *var);
void			size_wall(t_var *vars);
void			draw_wall(t_var *vars, int x);
void			draw_floor(t_var *var, int x);
void			draw_ceiling(t_var *vars, int x);
/*
** Touche du clavier
*/
void			key_up(t_var *vars);
void			key_down(t_var *vars);
void			key_left(t_var *vars);
void			key_right(t_var *vars);
void			key_esc(void);
void			key_space(t_var *vars);
/*
** Texture
*/
int				get_xpm_color(t_xpm *xpm, int x, int y);
t_xpm			*init_xpm(t_var *vars, char *file, int size);
#endif
