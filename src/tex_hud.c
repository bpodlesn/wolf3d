/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_hud.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:21:25 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/04/24 12:20:10 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	create_weapons(t_orig *orig)
{
	orig->sdl.weaponsurf = IMG_Load("images/weapons/sr.png");
	orig->sdl.axesurf = IMG_Load("images/weapons/new.png");
	orig->sdl.doubleaxesurf = IMG_Load("images/weapons/wtf.png");
	orig->sdl.hammersurf = IMG_Load("images/weapons/hammer.png");
	orig->sdl.daggersurf = IMG_Load("images/weapons/dagger.png");
	orig->sdl.firstdaggersurf = IMG_Load("images/weapons/firstdag.png");
	orig->sdl.swrdsurf = IMG_Load("images/weapons/asd.png");
	orig->sdl.weapon = SDL_CreateTextureFromSurface(RENDER, WEAPSURFACE);
	orig->sdl.axe = SDL_CreateTextureFromSurface(RENDER, orig->sdl.axesurf);
	orig->sdl.doubleaxe = SDL_CreateTextureFromSurface(RENDER, DBAXESURF);
	orig->sdl.hammer = SDL_CreateTextureFromSurface(RENDER, HAMSURF);
	orig->sdl.dagger = SDL_CreateTextureFromSurface(RENDER, DAGSURF);
	orig->sdl.firstdagger = SDL_CreateTextureFromSurface(RENDER, FDAGSURF);
	orig->sdl.swrd = SDL_CreateTextureFromSurface(RENDER, orig->sdl.swrdsurf);
}

void	create_sdl_and_hud(t_orig *orig)
{
	Uint32 render_flags;

	orig->sdl.win = SDL_CreateWindow("Hello, MY SEMPAI!",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINW, WINH, SDL_WINDOW_MAXIMIZED);
	render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	orig->sdl.renderer = SDL_CreateRenderer(orig->sdl.win, -1, render_flags);
	orig->sdl.surface = IMG_Load("images/hud/1.png");
	orig->sdl.hud2 = IMG_Load("images/hud/2.png");
	orig->sdl.hud3 = IMG_Load("images/hud/3.png");
	orig->sdl.hud4 = IMG_Load("images/hud/4.png");
	orig->sdl.hud5 = IMG_Load("images/hud/5.png");
	orig->sdl.hud6 = IMG_Load("images/hud/6.png");
	orig->sdl.tex = SDL_CreateTextureFromSurface(RENDER, orig->sdl.surface);
	orig->sdl.texhud2 = SDL_CreateTextureFromSurface(RENDER, orig->sdl.hud2);
	orig->sdl.texhud3 = SDL_CreateTextureFromSurface(RENDER, orig->sdl.hud3);
	orig->sdl.texhud4 = SDL_CreateTextureFromSurface(RENDER, orig->sdl.hud4);
	orig->sdl.texhud5 = SDL_CreateTextureFromSurface(RENDER, orig->sdl.hud5);
	orig->sdl.texhud6 = SDL_CreateTextureFromSurface(RENDER, orig->sdl.hud6);
	orig->sdl.fillscreen = SDL_CreateTexture(RENDER, SDL_PIXELFORMAT_RGB888,
		SDL_TEXTUREACCESS_TARGET, WINW, WINH);
	create_weapons(orig);
	SDL_FreeSurface(orig->sdl.surface);
}

t_orig	update_texture(t_orig orig)
{
	int i;
	int width;
	int height;

	i = 0;
	width = 0;
	height = 0;
	while (height < 600)
	{
		width = 0;
		while (width < 800)
		{
			orig.screen[i] = orig.arr[width][height];
			orig.arr[width][height] = 0;
			i++;
			width++;
		}
		height++;
	}
	SDL_UpdateTexture(orig.sdl.fillscreen, NULL, orig.screen, 800 * 4);
	bzero(orig.screen, 800 * 600);
	return (orig);
}

t_orig	set_hud(t_orig orig)
{
	if (orig.weapon == 0)
		SDL_RenderCopy(RENDERER, orig.sdl.tex, &SHUD, &DHUD);
	else if (orig.weapon == 1)
		SDL_RenderCopy(RENDERER, orig.sdl.texhud2, &SHUD, &DHUD);
	else if (orig.weapon == 2)
		SDL_RenderCopy(RENDERER, orig.sdl.texhud3, &SHUD, &DHUD);
	else if (orig.weapon == 3)
		SDL_RenderCopy(RENDERER, orig.sdl.texhud4, &SHUD, &DHUD);
	else if (orig.weapon == 4)
		SDL_RenderCopy(RENDERER, orig.sdl.texhud5, &SHUD, &DHUD);
	else if (orig.weapon == 5)
		SDL_RenderCopy(RENDERER, orig.sdl.texhud6, &SHUD, &DHUD);
	return (orig);
}

t_orig	check_weapon(t_orig orig)
{
	if (orig.weapon == 0)
		SDL_RenderCopy(RENDERER, orig.sdl.weapon, &SWEAP, &DWEAP);
	else if (orig.weapon == 1)
		SDL_RenderCopy(RENDERER, orig.sdl.axe, &SWEAP, &DWEAP);
	else if (orig.weapon == 2)
		SDL_RenderCopy(RENDERER, orig.sdl.doubleaxe, &SWEAP, &DWEAP);
	else if (orig.weapon == 3)
		SDL_RenderCopy(RENDERER, orig.sdl.hammer, &SWEAP, &DWEAP);
	else if (orig.weapon == 4)
	{
		SDL_RenderCopy(RENDERER, orig.sdl.dagger, &SDAG, &DDAG);
		SDL_RenderCopy(RENDERER, orig.sdl.firstdagger, &SFDAG, &DFDAG);
	}
	else if (orig.weapon == 5)
		SDL_RenderCopy(RENDERER, orig.sdl.swrd, &SWEAP, &DWEAP);
	orig = set_hud(orig);
	return (orig);
}
