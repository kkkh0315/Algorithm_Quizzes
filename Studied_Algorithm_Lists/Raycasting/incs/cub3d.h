/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoukim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:49:56 by kyoukim           #+#    #+#             */
/*   Updated: 2020/10/27 19:13:01 by kyoukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>


# define SCR_WID 640
# define SCR_HEI 480
# define FOV 0.66
# define SUCCESS 0
# define ERROR -1

typedef struct	s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct	s_ivector
{
	int			x;
	int			y;
}				t_ivector;

typedef struct	s_screen
{
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_screen;

typedef struct	s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	cam_plane;
	double		move_speed;
	double		rot_speed;
}				t_player;

typedef struct	s_raycast
{
	double		camera_x;
	t_vector	ray_dir;
	t_vector	side_dist;
	t_vector	delta_dist;
	double		dist_to_wall;
	t_ivector	step;
	int			hit;
	int			side;
	t_ivector	box;
}				t_raycast;

typedef struct	s_vars
{
	void		*mlx_ptr;
	void		*mlx_win;
}				t_vars;

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_all
{
	t_vector	vec;
	t_screen	scr;
	t_player	player;
	t_raycast	ray;
	t_vars		vars;
	t_data		data;
}				t_all;

#endif
