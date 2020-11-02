/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exercise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoukim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:06:00 by kyoukim           #+#    #+#             */
/*   Updated: 2020/11/02 16:11:24 by kyoukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "incs/cub3d.h"
#include "incs/key_macos.h"
#include <stdio.h>
#define MAP_WID 10
#define MAP_HEI 8

int map[MAP_HEI][MAP_WID] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 0, 0, 0, 1, 1, 0, 1},
	{1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 'E', 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int	init_player(t_player *p)
{
	int x;
	int y;

	p->pos.x = 4;
	p->pos.y = 4;
	p->move_speed = 0.1;
	p->rot_speed = 0.1;
	x = p->pos.x;
	y = p->pos.y;
	if (map[y][x] == 'E' || map[y][x] == 'W')
	{
		map[y][x] == 'E' ? (p->dir.x = 1) : (p->dir.x = -1);
		p->dir.y = 0;
		p->cam_plane.x = 0;
		map[y][x] == 'E' ? (p->cam_plane.y = FOV) : (p->cam_plane.y = -FOV);
	}
	else if (map[y][x] == 'N' || map[y][x] == 'S')
	{
		p->dir.x = 0;
		map[y][x] == 'N' ? (p->dir.y = -1) : (p->dir.y = 1);
		map[y][x] == 'N' ? (p->cam_plane.x = FOV) : (p->cam_plane.x = -FOV);
		p->cam_plane.y = 0;
	}
	else
		return (ERROR);
	map[(int)p->pos.y][(int)p->pos.x] = 0;
	return (SUCCESS);
}

void init_raycast(t_raycast *ray)
{
	ray->camera_x = 0.0;
	ray->ray_dir.x = 0;
	ray->ray_dir.y = 0;
	ray->side_dist.x = 0;
	ray->side_dist.y = 0;
	ray->delta_dist.x = 0;
	ray->delta_dist.y = 0;
	ray->dist_to_wall = 0.0;
	ray->step.x = 0;
	ray->step.y = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->box.x = 0;
	ray->box.y = 0;
}

void init_screen(t_screen *scr)
{
	scr->line_height = 0;
	scr->draw_start = 0;
	scr->draw_end = 0;
}

int verLine(t_vars *vars, int x, int draw_s, int draw_e, int color)
{
	int y;

	y = draw_s;
	while (y <= draw_e)
	{
		mlx_pixel_put(vars->mlx_ptr, vars->mlx_win, x, y, color);
		y++;
	}
	return (SUCCESS);
}

void raycast(t_all *all)
{
	int i;
	t_raycast ray;
	t_player p;
	t_screen scr;

	p = all->player;
	i = 0;
	while (i < SCR_WID)
	{
		init_raycast(&(all->ray));
		ray = all->ray;
		ray.camera_x = 2 * i / (double)SCR_WID - 1;
		ray.ray_dir.x = p.dir.x + p.cam_plane.x * ray.camera_x;
		ray.ray_dir.y = p.dir.y + p.cam_plane.y * ray.camera_x;
			
		ray.box.x = (int)p.pos.x;
		ray.box.y = (int)p.pos.y;

		ray.delta_dist.x = fabs(1 / ray.ray_dir.x);
		ray.delta_dist.y = fabs(1 / ray.ray_dir.y);

		if (ray.ray_dir.x < 0)
		{
			ray.step.x = -1;
			ray.side_dist.x = (p.pos.x - ray.box.x) * ray.delta_dist.x;
		}
		else
		{
			ray.step.x = 1;
			ray.side_dist.x = (ray.box.x + 1.0 - p.pos.x) * ray.delta_dist.x;
		}
		if (ray.ray_dir.y < 0)
		{
			ray.step.y = -1;
			ray.side_dist.y = (p.pos.y - ray.box.y) * ray.delta_dist.y;
		}
		else
		{
			ray.step.y = 1;
			ray.side_dist.y = (ray.box.y + 1.0 - p.pos.y) * ray.delta_dist.y;
		}

		while (ray.hit == 0)
		{
			if (ray.side_dist.x < ray.side_dist.y)
			{
				ray.side_dist.x += ray.delta_dist.x;
				ray.box.x += ray.step.x;
				ray.side = 0;
			}
			else
			{
				ray.side_dist.y += ray.delta_dist.y;
				ray.box.y += ray.step.y;
				ray.side = 1;
			}
			if (map[ray.box.y][ray.box.x] == 1)
				ray.hit = 1;
		}
		if (ray.side == 0)
			ray.dist_to_wall = (ray.box.x - p.pos.x + (1 - ray.step.x) / 2) / ray.ray_dir.x;
		else
			ray.dist_to_wall = (ray.box.y - p.pos.y + (1 - ray.step.y) / 2) / ray.ray_dir.y;

		init_screen(&(all->scr));
		scr = all->scr;
		scr.line_height = (int)(SCR_HEI / ray.dist_to_wall);
		scr.draw_start = SCR_HEI / 2 - scr.line_height / 2;
		if (scr.draw_start < 0)
			scr.draw_start = 0;
		scr.draw_end = SCR_HEI / 2 + scr.line_height / 2;
		if (scr.draw_end >= SCR_HEI)
			scr.draw_end = SCR_HEI - 1;
		if (map[ray.box.y][ray.box.x] == 1)
		{
			if (ray.side == 0)
			{
				verLine(&(all->vars), i, scr.draw_start, scr.draw_end, 0x0000FF);
				verLine(&(all->vars), i, 0, scr.draw_start, 0x000000);
				verLine(&(all->vars), i, scr.draw_end, SCR_HEI, 0x000000);
			}
			else
			{
				verLine(&(all->vars), i, scr.draw_start, scr.draw_end, 0x0000FF / 2);
				verLine(&(all->vars), i, 0, scr.draw_start, 0x000000);
				verLine(&(all->vars), i, scr.draw_end, SCR_HEI, 0x000000);
			}
		}
		i++;
	}
}

int key_press(int key, t_player *p)
{
	double dir_x;
	double cam_plane_x;

	if (key == K_W)
	{
		if (!map[(int)p->pos.y][(int)(p->pos.x + p->dir.x * p->move_speed)])
			p->pos.x += p->dir.x * p->move_speed;
		if (!map[(int)(p->pos.y + p->dir.y * p->move_speed)][(int)p->pos.x])
			p->pos.y += p->dir.y * p->move_speed;
	}
	if (key == K_S)
	{
		if (!map[(int)p->pos.y][(int)(p->pos.x + p->dir.x * p->move_speed)])
			p->pos.x -= p->dir.x * p->move_speed;
		if (!map[(int)(p->pos.y + p->dir.y * p->move_speed)][(int)p->pos.x])
			p->pos.y -= p->dir.y * p->move_speed;
	}
	if (key == K_D)
	{
		if (!map[(int)p->pos.y][(int)(p->pos.x - p->dir.y * p->move_speed)])
			p->pos.x -= p->dir.y * p->move_speed;
		if (!map[(int)(p->pos.y + p->dir.x * p->move_speed)][(int)p->pos.x])
			p->pos.y += p->dir.x * p->move_speed;
	}
	if (key == K_A)
	{
		if (!map[(int)p->pos.y][(int)(p->pos.x + p->dir.y * p->move_speed)])
			p->pos.x += p->dir.y * p->move_speed;
		if (!map[(int)(p->pos.y - p->dir.x * p->move_speed)][(int)p->pos.x])
			p->pos.y -= p->dir.x * p->move_speed;
	}
	if (key == K_AR_R)
	{
		dir_x = p->dir.x;
		p->dir.x = p->dir.x * cos(p->rot_speed) - p->dir.y * sin(p->rot_speed);
		p->dir.y = dir_x * sin(p->rot_speed) + p->dir.y * cos(p->rot_speed);
		cam_plane_x = p->cam_plane.x;
		p->cam_plane.x = p->cam_plane.x * cos(p->rot_speed) - p->cam_plane.y * sin(p->rot_speed);
		p->cam_plane.y = cam_plane_x * sin(p->rot_speed) + p->cam_plane.y * cos(p->rot_speed);
	}
	if (key == K_AR_L)
	{
		dir_x = p->dir.x;
		p->dir.x = p->dir.x * cos(-p->rot_speed) - p->dir.y * sin(-p->rot_speed);
		p->dir.y = dir_x * sin(-p->rot_speed) + p->dir.y * cos(-p->rot_speed);
		cam_plane_x = p->cam_plane.x;
		p->cam_plane.x = p->cam_plane.x * cos(-p->rot_speed) - p->cam_plane.y * sin(-p->rot_speed);
		p->cam_plane.y = cam_plane_x * sin(-p->rot_speed) + p->cam_plane.y * cos(-p->rot_speed);
	}
	if (key == K_ESC)
		exit(0);
	return (0);
}

int main_loop(t_all *all)
{
	raycast(all);
	return (0);
}


int main(void)
{
	t_all all;

	all.vars.mlx_ptr = mlx_init();
	all.vars.mlx_win = mlx_new_window(all.vars.mlx_ptr, SCR_WID, SCR_HEI, "Tony's CUB3D");
	init_player(&all.player);
	mlx_loop_hook(all.vars.mlx_ptr, &main_loop, &all);
	mlx_hook(all.vars.mlx_win, 2, 1L<<0, &key_press, &(all.player));	
	mlx_loop(all.vars.mlx_ptr);
}
