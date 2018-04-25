/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_par.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 11:24:30 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/04/23 16:10:53 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_orig	set_texture_params(t_orig orig)
{
	orig.sdl.srcrect.w = 800;
	orig.sdl.srcrect.h = 600;
	orig.sdl.dstrect.w = 800;
	orig.sdl.dstrect.h = 600;
	orig.sdl.shud.y = 70;
	orig.sdl.shud.w = 1000;
	orig.sdl.shud.h = 2000;
	orig.sdl.dhud.y = 500;
	orig.sdl.dhud.w = 800;
	orig.sdl.dhud.h = 100;
	orig.sdl.sweap.w = 1000;
	orig.sdl.sweap.h = 1000;
	orig.sdl.dweap.x = 200;
	orig.sdl.dweap.y = 150;
	orig.sdl.dweap.w = 400;
	orig.sdl.dweap.h = 500;
	orig = set_tex_params_2(orig);
	return (orig);
}

t_orig	set_tex_params_2(t_orig orig)
{
	orig.sdl.sdag.w = 1000;
	orig.sdl.sdag.h = 1000;
	orig.sdl.ddag.x = 400;
	orig.sdl.ddag.y = 120;
	orig.sdl.ddag.w = 300;
	orig.sdl.ddag.h = 600;
	orig.sdl.sfdag.w = 1000;
	orig.sdl.sfdag.h = 1000;
	orig.sdl.dfdag.x = 100;
	orig.sdl.dfdag.y = 150;
	orig.sdl.dfdag.w = 300;
	orig.sdl.dfdag.h = 600;
	return (orig);
}

t_orig	set_values(t_orig orig)
{
	int i1;

	i1 = 0;
	orig.done = 0;
	orig.player.dir_x = -1;
	orig.player.dir_y = 0;
	orig.player.plane_x = 0;
	orig.player.plane_y = 0.66;
	orig.frame.time = 0;
	orig.frame.oldtime = 0;
	orig.weapon = 0;
	orig.tic = 0;
	orig.flag = 0;
	orig.arr = (int**)malloc(sizeof(int*) * (WINW));
	orig.screen = (int*)malloc(sizeof(int*) * (WINH * WINW));
	while (i1 < WINW)
	{
		orig.arr[i1] = (int*)malloc(sizeof(int) * (WINH));
		i1++;
	}
	return (orig);
}

void	set_tex_color(t_orig *orig)
{
	if (orig->worldmap[orig->ray.map_x][orig->ray.map_y] == 3)
		orig->texcolor = 0;
	else if (orig->worldmap[orig->ray.map_x][orig->ray.map_y] == 1)
		orig->texcolor = 4;
	else if (orig->worldmap[orig->ray.map_x][orig->ray.map_y] == 2)
		orig->texcolor = 5;
	else if (orig->worldmap[orig->ray.map_x][orig->ray.map_y] == 4)
		orig->texcolor = 6;
	else if (orig->worldmap[orig->ray.map_x][orig->ray.map_y] == 5)
		orig->texcolor = 7;
	else if (orig->worldmap[orig->ray.map_x][orig->ray.map_y] == 6)
		orig->texcolor = 8;
	else if (orig->worldmap[orig->ray.map_x][orig->ray.map_y] == 7)
		orig->texcolor = 9;
	else
		set_tex_color2(orig);
}

void	set_tex_color2(t_orig *orig)
{
	if (orig->worldmap[orig->ray.map_x][orig->ray.map_y] == 8)
		orig->texcolor = 10;
	else if (orig->worldmap[orig->ray.map_x][orig->ray.map_y] == 9)
		orig->texcolor = 11;
	else if (orig->worldmap[orig->ray.map_x][orig->ray.map_y] == 10)
		orig->texcolor = 12;
	else if (orig->worldmap[orig->ray.map_x][orig->ray.map_y] == 11)
		orig->texcolor = 13;
	else if (orig->worldmap[orig->ray.map_x][orig->ray.map_y] == 12)
		orig->texcolor = 14;
	else if (orig->worldmap[orig->ray.map_x][orig->ray.map_y] == 13)
		orig->texcolor = 15;
	else if (orig->worldmap[orig->ray.map_x][orig->ray.map_y] == 14)
		orig->texcolor = 16;
}
