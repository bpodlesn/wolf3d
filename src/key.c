/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:41:35 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/04/23 16:04:40 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_orig			key_up(t_orig orig)
{
	orig.worldmap[(int)(orig.player.pos_x + orig.player.dir_x *
		orig.player.movespeed)][(int)(orig.player.pos_y)] == false ?
		orig.player.pos_x += orig.player.dir_x * orig.player.movespeed : 0;
	orig.worldmap[(int)(orig.player.pos_x)][(int)(orig.player.pos_y +
		orig.player.dir_y * orig.player.movespeed)] == false ?
		orig.player.pos_y += orig.player.dir_y * orig.player.movespeed : 0;
	orig = move_weapons(orig);
	return (orig);
}

t_orig			key_down(t_orig orig)
{
	orig.worldmap[(int)(orig.player.pos_x - orig.player.dir_x *
		orig.player.movespeed)][(int)(orig.player.pos_y)] == false ?
		orig.player.pos_x -= orig.player.dir_x * orig.player.movespeed : 0;
	orig.worldmap[(int)(orig.player.pos_x)][(int)(orig.player.pos_y -
		orig.player.dir_y * orig.player.movespeed)] == false ?
	orig.player.pos_y -= orig.player.dir_y * orig.player.movespeed : 0;
	orig = move_weapons(orig);
	return (orig);
}

t_orig			key_left(t_orig orig, double oldx, double oldy)
{
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = orig.player.dir_x;
	old_plane_x = orig.player.plane_x;
	orig.player.dir_x = orig.player.dir_x * cos(orig.player.rotspeed)
		- orig.player.dir_y * sin(orig.player.rotspeed);
	orig.player.dir_y = old_dir_x * sin(orig.player.rotspeed)
		+ orig.player.dir_y * cos(orig.player.rotspeed);
	orig.player.plane_x = orig.player.plane_x * cos(orig.player.rotspeed)
		- orig.player.plane_y * sin(orig.player.rotspeed);
	orig.player.plane_y = old_plane_x * sin(orig.player.rotspeed)
		+ orig.player.plane_y * cos(orig.player.rotspeed);
	if (oldx == orig.player.pos_x || oldy == orig.player.pos_y)
		orig = move_weapons(orig);
	return (orig);
}

t_orig			key_right(t_orig orig, double oldx, double oldy)
{
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = orig.player.dir_x;
	old_plane_x = orig.player.plane_x;
	orig.player.dir_x = orig.player.dir_x * cos(-orig.player.rotspeed)
		- orig.player.dir_y * sin(-orig.player.rotspeed);
	orig.player.dir_y = old_dir_x * sin(-orig.player.rotspeed)
		+ orig.player.dir_y * cos(-orig.player.rotspeed);
	orig.player.plane_x = orig.player.plane_x * cos(-orig.player.rotspeed)
		- orig.player.plane_y * sin(-orig.player.rotspeed);
	orig.player.plane_y = old_plane_x * sin(-orig.player.rotspeed)
		+ orig.player.plane_y * cos(-orig.player.rotspeed);
	if (oldx == orig.player.pos_x || oldy == orig.player.pos_y)
		orig = move_weapons(orig);
	return (orig);
}

t_orig			key(t_orig orig, double old_x, double old_y)
{
	const Uint8	*keykey;

	keykey = SDL_GetKeyboardState(NULL);
	SDL_PollEvent(&orig.sdl.event);
	orig.sdl.event.type == SDL_QUIT ? orig = free_exit(orig) : orig;
	orig.sdl.event.key.keysym.scancode == SDL_SCANCODE_ESCAPE ?
		orig = free_exit(orig) : orig;
	orig.sdl.dweap.y <= 120 ? orig.flag = 1 : 0;
	orig.sdl.dweap.y >= 150 ? orig.flag = -1 : 0;
	orig.move_flag = 5;
	keykey[SDL_SCANCODE_UP] ? orig = key_up(orig) : orig;
	keykey[SDL_SCANCODE_DOWN] ? orig = key_down(orig) : orig;
	keykey[SDL_SCANCODE_RIGHT] ? orig = key_right(orig, old_x, old_y) : orig;
	keykey[SDL_SCANCODE_LEFT] ? orig = key_left(orig, old_x, old_y) : orig;
	keykey[SDL_SCANCODE_LSHIFT] ? orig = shift(orig, old_x, old_y) : orig;
	keykey[SDL_SCANCODE_1] ? WEAPON = 0 : 0;
	keykey[SDL_SCANCODE_2] ? WEAPON = 1 : 0;
	keykey[SDL_SCANCODE_3] ? WEAPON = 2 : 0;
	keykey[SDL_SCANCODE_4] ? WEAPON = 3 : 0;
	keykey[SDL_SCANCODE_5] ? WEAPON = 4 : 0;
	keykey[SDL_SCANCODE_6] ? WEAPON = 5 : 0;
	return (orig);
}
