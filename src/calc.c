/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:13:50 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/04/23 16:22:17 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_orig			dda_perform(t_orig orig)
{
	while (orig.hit == 0)
	{
		if (orig.ray.side_dis_x < orig.ray.side_dis_y)
		{
			orig.ray.side_dis_x += orig.ray.del_dis_x;
			RAY_MAP_X += STEP_X;
			SIDE = 0;
		}
		else
		{
			orig.ray.side_dis_y += orig.ray.del_dis_y;
			RAY_MAP_Y += STEP_Y;
			SIDE = 1;
		}
		orig.worldmap[RAY_MAP_X][RAY_MAP_Y] > 0 ? orig.hit = 1 : 0;
	}
	SIDE0 ? WALL_DIS = ((RAY_MAP_X - POS_X + (1 - STEP_X) / 2) / RAYDIRX) : 0;
	SIDEN ? WALL_DIS = ((RAY_MAP_Y - POS_Y + (1 - STEP_Y) / 2) / RAYDIRY) : 0;
	WALL_DIS += 0.01;
	orig.ray.line_height = (int)(WINH / WALL_DIS);
	DRAWSTR = -orig.ray.line_height / 2 + WINH / 2;
	DRAWSTR < 0 ? DRAWSTR = 0 : 0;
	DRAWEND = orig.ray.line_height / 2 + WINH / 2;
	DRAWEND >= WINH ? DRAWEND = WINH - 1 : 0;
	return (orig);
}

t_orig			stepby_and_disray(t_orig orig)
{
	if (RAYDIRX < 0)
	{
		STEP_X = -1;
		orig.ray.side_dis_x = (POS_X - RAY_MAP_X) * orig.ray.del_dis_x;
	}
	else
	{
		STEP_X = 1;
		orig.ray.side_dis_x = (RAY_MAP_X + 1.0 - POS_X) * orig.ray.del_dis_x;
	}
	if (RAYDIRY < 0)
	{
		STEP_Y = -1;
		orig.ray.side_dis_y = (POS_Y - RAY_MAP_Y) * orig.ray.del_dis_y;
	}
	else
	{
		STEP_Y = 1;
		orig.ray.side_dis_y = (RAY_MAP_Y + 1.0 - POS_Y) * orig.ray.del_dis_y;
	}
	return (orig);
}

t_orig			calc_raydir_pos(t_orig orig, int x)
{
	double		camera_x;

	camera_x = 2 * x / (double)(WINW) - 1;
	RAYDIRX = orig.player.dir_x + orig.player.plane_x * camera_x;
	RAYDIRY = orig.player.dir_y + orig.player.plane_y * camera_x;
	RAY_MAP_X = (int)POS_X;
	RAY_MAP_Y = (int)POS_Y;
	orig.ray.del_dis_x = fabs(1 / RAYDIRX);
	orig.ray.del_dis_y = fabs(1 / RAYDIRY);
	orig.hit = 0;
	return (orig);
}
