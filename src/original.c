/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   original.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:46:51 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/04/24 12:18:25 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_orig			sdl_render(t_orig orig)
{
	orig.frame.oldtime = orig.frame.time;
	orig.frame.time = SDL_GetTicks();
	orig.frame.frametime = (orig.frame.time - orig.frame.oldtime) / 1000.0;
	SDL_SetRenderDrawColor(RENDERER, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderCopy(RENDERER, orig.sdl.fillscreen, &orig.sdl.srcrect,
		&orig.sdl.dstrect);
	orig = check_weapon(orig);
	SDL_RenderPresent(RENDERER);
	SDL_RenderClear(RENDERER);
	orig.player.movespeed = orig.frame.frametime * orig.move_flag;
	orig.player.rotspeed = orig.frame.frametime * 3.0;
	return (orig);
}

void			fill_4side_wall(t_orig *orig, int count, int x)
{
	orig->side == 1 && orig->ray.ray_dir_y > 0 ?
		orig->arr[x][orig->ray.drawstart] =
		((orig->texture[orig->texcolor][count])) : 0;
	orig->side == 1 && orig->ray.ray_dir_y < 0 ?
		orig->arr[x][orig->ray.drawstart] =
		((orig->texture[orig->texcolor + 1][count])) : 0;
	orig->side == 0 && orig->ray.ray_dir_x > 0 ?
		orig->arr[x][orig->ray.drawstart] =
		((orig->texture[orig->texcolor + 2][count])) : 0;
	orig->side == 0 && orig->ray.ray_dir_x < 0 ?
		orig->arr[x][orig->ray.drawstart] =
		((orig->texture[orig->texcolor + 3][count])) : 0;
}

t_orig			fill_textures(t_orig orig, int count, int x, int tex_x)
{
	int			aaa;
	int			d;
	int			tex_y;

	aaa = -1;
	while (++aaa < WINH / 2)
		ARR[x][aaa] = orig.skybox[count += 800] + orig.tic;
	while (++aaa < WINH)
		ARR[x][aaa] = 2039583;
	while (++DRAWSTR < DRAWEND)
	{
		d = DRAWSTR * 256 - WINH * 128 + orig.ray.line_height * 128;
		tex_y = ((d * TEXH) / orig.ray.line_height) / 256;
		count = (TEXH * tex_y + tex_x);
		set_tex_color(&orig);
		SIDE == 0 ? ARR[x][DRAWSTR] = ((TEX[TEXCOL][count])) : 0;
		SIDE == 1 ? ARR[x][DRAWSTR] = ((TEX[TEXCOL][count]) >> 1) & 8355711 : 0;
		if (TEXCOL == 0)
			fill_4side_wall(&orig, count, x);
	}
	return (orig);
}

void			wolf(t_orig orig, int x, int count)
{
	double		wall_x;
	int			tex_x;

	while (!orig.done)
	{
		x = -1;
		count = 0;
		while (++x < WINW && count++ > -1)
		{
			orig = calc_raydir_pos(orig, x);
			orig = stepby_and_disray(orig);
			orig = dda_perform(orig);
			(SIDE == 0) ? wall_x = POS_Y + WALL_DIS * RAYDIRY : 0;
			(SIDE != 0) ? wall_x = POS_X + WALL_DIS * RAYDIRX : 0;
			wall_x -= floor((wall_x));
			tex_x = (int)(wall_x * (double)(TEXW));
			SIDE == 0 && RAYDIRX > 0 ? tex_x = TEXW - tex_x - 1 : 0;
			SIDE == 1 && RAYDIRY < 0 ? tex_x = TEXW - tex_x - 1 : 0;
			orig = fill_textures(orig, count, x, tex_x);
		}
		orig = update_sky(orig);
		orig = update_texture(orig);
		orig = sdl_render(orig);
		orig = key(orig, orig.player.pos_x, orig.player.pos_y);
	}
}
