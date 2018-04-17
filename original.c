/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   original.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:46:51 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/04/17 16:53:45 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"


void	create_sdl(t_orig *orig)
{
	orig->sdl.win = SDL_CreateWindow("Hello, MY SEMPAI!",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		winW, winH, SDL_WINDOW_FULLSCREEN);
	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	orig->sdl.renderer = SDL_CreateRenderer(orig->sdl.win, -1, render_flags);
	orig->sdl.surface = IMG_Load("images/hud/doom-hud1.png");
	orig->sdl.weaponsurf = IMG_Load("images/sr.png");
	orig->sdl.axesurf = IMG_Load("images/axe.png");
	orig->sdl.doubleaxesurf = IMG_Load("images/wtf.png");
	orig->sdl.hammersurf = IMG_Load("images/hammer.png");
	orig->sdl.daggersurf = IMG_Load("images/dagger.png");
	orig->sdl.firstdaggersurf = IMG_Load("images/firstdag.png");
	orig->sdl.tex = SDL_CreateTextureFromSurface(orig->sdl.renderer, orig->sdl.surface);
	orig->sdl.fillscreen = SDL_CreateTexture(orig->sdl.renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_TARGET, winW, winH);
	orig->sdl.weapon = SDL_CreateTextureFromSurface(orig->sdl.renderer, orig->sdl.weaponsurf);
	orig->sdl.axe = SDL_CreateTextureFromSurface(orig->sdl.renderer, orig->sdl.axesurf);
	orig->sdl.doubleaxe = SDL_CreateTextureFromSurface(orig->sdl.renderer, orig->sdl.doubleaxesurf);
	orig->sdl.hammer = SDL_CreateTextureFromSurface(orig->sdl.renderer, orig->sdl.hammersurf);
	orig->sdl.dagger = SDL_CreateTextureFromSurface(orig->sdl.renderer, orig->sdl.daggersurf);
	orig->sdl.firstdagger = SDL_CreateTextureFromSurface(orig->sdl.renderer, orig->sdl.firstdaggersurf);
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
		while(width < 800)
		{
			orig.screen[i] = orig.arr[width][height];
			orig.arr[width][height] = 0;
			i++;
			width++;
		}
		height++;
	}
	SDL_UpdateTexture(orig.sdl.fillscreen, NULL, orig.screen, 800*4);
	bzero(orig.screen, 800*600);
	return (orig);
}

t_orig	sdl_render(t_orig orig)
{
	orig.frame.oldtime = orig.frame.time;
	orig.frame.time = SDL_GetTicks();
	orig.frame.frameTime = (orig.frame.time - orig.frame.oldtime) / 1000.0;
	// printf("%fframe\n", orig.frame.frameTime);
	SDL_SetRenderDrawColor(orig.sdl.renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderCopy(orig.sdl.renderer, orig.sdl.fillscreen, &orig.sdl.srcrect, &orig.sdl.dstrect);
	if (orig.weapon == 0)
		SDL_RenderCopy(orig.sdl.renderer, orig.sdl.weapon, &orig.sdl.sWEAP, &orig.sdl.dWEAP);
	if (orig.weapon == 1)
		SDL_RenderCopy(orig.sdl.renderer, orig.sdl.axe, &orig.sdl.sWEAP, &orig.sdl.dWEAP);
	if (orig.weapon == 2)
		SDL_RenderCopy(orig.sdl.renderer, orig.sdl.doubleaxe, &orig.sdl.sWEAP, &orig.sdl.dWEAP);
	if (orig.weapon == 3)
		SDL_RenderCopy(orig.sdl.renderer, orig.sdl.hammer, &orig.sdl.sWEAP, &orig.sdl.dWEAP);
	if (orig.weapon == 4)
	{
		SDL_RenderCopy(orig.sdl.renderer, orig.sdl.dagger, &orig.sdl.sdag, &orig.sdl.ddag);
		SDL_RenderCopy(orig.sdl.renderer, orig.sdl.firstdagger, &orig.sdl.sfdag, &orig.sdl.dfdag);
	}
	SDL_RenderCopy(orig.sdl.renderer, orig.sdl.tex, &orig.sdl.sHUD, &orig.sdl.dHUD);
	SDL_RenderPresent(orig.sdl.renderer);		
	SDL_RenderClear(orig.sdl.renderer);
	orig.player.moveSpeed = orig.frame.frameTime * 5.0;
	orig.player.rotSpeed = orig.frame.frameTime * 3.0;
	return (orig);
}

t_orig	fill_textures(t_orig orig, int count, int x, int texcolor, int texX)
{
	int aaa = -1;
    int i = 0;

    while(++aaa < winH/2)
    {
    	orig.arr[x][aaa] = orig.skybox[count] + orig.tic;
    	count+=800;
    }
    while (++aaa < winH)
    	orig.arr[x][aaa] = 2039583;
    while(orig.ray.drawStart < orig.ray.drawEnd)
    {
    	int d = orig.ray.drawStart * 256 - winH * 128 + orig.ray.lineHeight * 128;
    	int texY = ((d * texH) / orig.ray.lineHeight) / 256;
    	count = (texH * texY + texX);
    	if (orig.worldMap[orig.ray.mapX][orig.ray.mapY] == 3)
    		texcolor = 0;
		else if (orig.worldMap[orig.ray.mapX][orig.ray.mapY] == 1)
			texcolor = 4;
		else if (orig.worldMap[orig.ray.mapX][orig.ray.mapY] == 2)
			texcolor = 5;
		else if (orig.worldMap[orig.ray.mapX][orig.ray.mapY] == 4)
			texcolor = 6;
		else if (orig.worldMap[orig.ray.mapX][orig.ray.mapY] == 5)
			texcolor = 7;
		else if (orig.worldMap[orig.ray.mapX][orig.ray.mapY] == 6)
			texcolor = 8;
		else if (orig.worldMap[orig.ray.mapX][orig.ray.mapY] == 7)
			texcolor = 9;
		else if (orig.worldMap[orig.ray.mapX][orig.ray.mapY] == 8)
			texcolor = 10;
		else if (orig.worldMap[orig.ray.mapX][orig.ray.mapY] == 9)
			texcolor = 11;
		else if (orig.worldMap[orig.ray.mapX][orig.ray.mapY] == 10)
			texcolor = 12;
		else if (orig.worldMap[orig.ray.mapX][orig.ray.mapY] == 11)
			texcolor = 13;
		else if (orig.worldMap[orig.ray.mapX][orig.ray.mapY] == 12)
			texcolor = 14;
		else if (orig.worldMap[orig.ray.mapX][orig.ray.mapY] == 13)
			texcolor = 15;
		else if (orig.worldMap[orig.ray.mapX][orig.ray.mapY] == 14)
			texcolor = 16;
		orig.arr[x][orig.ray.drawStart] = 0;
		orig.side == 0 ? orig.arr[x][orig.ray.drawStart] = ((orig.texture[texcolor][count])) : 0;
		orig.side == 1 ? orig.arr[x][orig.ray.drawStart] = ((orig.texture[texcolor][count]) >> 1) & 8355711 : 0;
		orig.side == 1 && texcolor == 0 && orig.ray.rayDirY > 0? orig.arr[x][orig.ray.drawStart] = ((orig.texture[texcolor][count])) : 0;
		orig.side == 1 && texcolor == 0 && orig.ray.rayDirY < 0? orig.arr[x][orig.ray.drawStart] = ((orig.texture[texcolor + 1][count])) : 0;
		orig.side == 0 && texcolor == 0 && orig.ray.rayDirX > 0? orig.arr[x][orig.ray.drawStart] = ((orig.texture[texcolor + 2][count])) : 0;
		orig.side == 0 && texcolor == 0 && orig.ray.rayDirX < 0? orig.arr[x][orig.ray.drawStart] = ((orig.texture[texcolor + 3][count])) : 0;
		orig.ray.drawStart++;
	}
	return (orig);
}

t_orig	DDA_perform(t_orig orig)
{
	while (orig.hit == 0)
	{
		if (orig.ray.sideDisX < orig.ray.sideDisY)
		{
			orig.ray.sideDisX += orig.ray.delDisX;
			orig.ray.mapX += orig.ray.stepbyX;
			orig.side = 0;
		}
		else
		{
			orig.ray.sideDisY += orig.ray.delDisY;
			orig.ray.mapY += orig.ray.stepbyY;
			orig.side = 1;
		}
		// if (orig.ray.sideDisX > orig.ray.sideDisY)
		// {
		// 	orig.side = 0;
		// }
		orig.worldMap[orig.ray.mapX][orig.ray.mapY] > 0 ? orig.hit = 1 : 0;
	}
	if (orig.side == 0)
		orig.ray.prpWallDis = (orig.ray.mapX - orig.player.posX + (1 - orig.ray.stepbyX) / 2) / orig.ray.rayDirX;
	else
		orig.ray.prpWallDis = (orig.ray.mapY - orig.player.posY + (1 - orig.ray.stepbyY) / 2) / orig.ray.rayDirY;
	orig.ray.lineHeight = (int)(winH / orig.ray.prpWallDis);
	orig.ray.drawStart = -orig.ray.lineHeight / 2 + winH / 2;
	orig.ray.drawStart < 0 ? orig.ray.drawStart = 0 : 0;
	orig.ray.drawEnd = orig.ray.lineHeight / 2 + winH / 2;
	orig.ray.drawEnd >= winH ? orig.ray.drawEnd = winH - 1 : 0;
	return (orig);
}

t_orig	set_texture_params(t_orig orig)
{
	orig.sdl.srcrect.w = 800;
	orig.sdl.srcrect.h = 600;
	orig.sdl.dstrect.w = 800;
	orig.sdl.dstrect.h = 600;

	//hud
	orig.sdl.sHUD.y = 70;
	orig.sdl.sHUD.w = 1000;
	orig.sdl.sHUD.h = 2000;
	orig.sdl.dHUD.y = 500;
	orig.sdl.dHUD.w = 800;
	orig.sdl.dHUD.h = 100;

	//other weapons
	orig.sdl.sWEAP.w = 1000;
	orig.sdl.sWEAP.h = 1000;
	orig.sdl.dWEAP.x = 200;
	orig.sdl.dWEAP.y = 150;
	orig.sdl.dWEAP.w = 400;
	orig.sdl.dWEAP.h = 500;

	//daggers
	orig.sdl.sdag.x = 0;
	orig.sdl.sdag.y = 0;
	orig.sdl.sdag.w = 1000;
	orig.sdl.sdag.h = 1000;
	orig.sdl.ddag.x = 400;
	orig.sdl.ddag.y = 150;
	orig.sdl.ddag.w = 300;
	orig.sdl.ddag.h = 500;

	//fdagger

	orig.sdl.sfdag.x = 0;
	orig.sdl.sfdag.y = 0;
	orig.sdl.sfdag.w = 1000;
	orig.sdl.sfdag.h = 1000;
	orig.sdl.dfdag.x = 100;
	orig.sdl.dfdag.y = 150;
	orig.sdl.dfdag.w = 300;
	orig.sdl.dfdag.h = 500;
	return (orig);
}

t_orig	stepby_and_disRay(t_orig orig)
{
	if (orig.ray.rayDirX < 0)
	{
		orig.ray.stepbyX = -1;
		orig.ray.sideDisX = (orig.player.posX - orig.ray.mapX) * orig.ray.delDisX;
	}
	else
	{
		orig.ray.stepbyX = 1;
		orig.ray.sideDisX = (orig.ray.mapX + 1.0 - orig.player.posX) * orig.ray.delDisX;
	}
	if (orig.ray.rayDirY < 0)
	{
		orig.ray.stepbyY = -1;
		orig.ray.sideDisY = (orig.player.posY - orig.ray.mapY) * orig.ray.delDisY;
	}
	else
	{
		orig.ray.stepbyY = 1;
		orig.ray.sideDisY = (orig.ray.mapY + 1.0 - orig.player.posY) * orig.ray.delDisY;
	}
	return (orig);
}

void	wolf(t_orig orig)
{
	orig.done = 0;
	orig.player.dirX = -1;
	orig.player.dirY = 0;
	orig.player.planeX = 0;
	orig.player.planeY = 0.66;
	orig.frame.time = 0;
	orig.frame.oldtime = 0;
	orig.weapon = 0;
	orig.tic = 0;
	int check = 0;
	orig.flag = 0;
	int count = 0;
	int texcolor = 0;
	orig = set_texture_params(orig);
	
	int color;
	int x = 0;
	orig.arr = (int**)malloc(sizeof(int*) * (winW));
	orig.screen = (int*)malloc(sizeof(int*) * (winH*winW));
	int i1 = 0;
	while (i1 < winW)
	{
		orig.arr[i1] = (int*)malloc(sizeof(int) * (winH));
		i1++;
	}
	orig = get_textures(orig);
	create_sdl(&orig);
	while (!orig.done)
	{
		// printf("X: %f\n", orig.player.planeX);
		// printf("Y: %f\n", orig.player.planeY);
		x = 0;
		count = 0;
		while (x < winW)
		{
			double cameraX = 2 * x / (double)(winW) - 1;
			orig.ray.rayDirX = orig.player.dirX + orig.player.planeX * cameraX;
			orig.ray.rayDirY = orig.player.dirY + orig.player.planeY * cameraX;
			orig.ray.mapX = (int)orig.player.posX;
			orig.ray.mapY = (int)orig.player.posY;
			orig.ray.delDisX = fabs(1 / orig.ray.rayDirX);
			orig.ray.delDisY = fabs(1 / orig.ray.rayDirY);
				orig.hit = 0;
			orig = stepby_and_disRay(orig);
			orig = DDA_perform(orig);
     		//calculate value of wallX
     		double wallX; //where exactly the wall was orig.hit
     		if (orig.side == 0)
     			wallX = orig.player.posY + orig.ray.prpWallDis * orig.ray.rayDirY;
     		else
     			wallX = orig.player.posX + orig.ray.prpWallDis * orig.ray.rayDirX;
     		wallX -= floor((wallX));
		
     		//x coordinate on the texture
     		int texX = (int)(wallX * (double)(texW));
     		orig.side == 0 && orig.ray.rayDirX > 0 ? texX = texW - texX - 1 : 0;
     		orig.side == 1 && orig.ray.rayDirY < 0 ? texX = texW - texX - 1 : 0;
     		int xcount = count;
     		orig = fill_textures(orig, xcount, x, texcolor, texX);
			x++;
			count++;
		}
		if (check == 0)
		{
			orig.tic += 2;
			if (orig.tic == 50)
				check = 1;
		}
		if (check == 1)
		{
			orig.tic-= 2;
			if (orig.tic == 0)
				check = 0;
		}
		orig = update_texture(orig);
		orig = sdl_render(orig);
		orig = key(orig);
	}
}

int main(int ac, char **av)
{
	t_orig orig;

	if (ac == 2)
	{
		int j;
		orig = reader(orig, open(av[1], O_RDONLY));
		// printf("%d\n", orig.height);
		// printf("%d\n", orig.width);
		int k = 0;	
		while (k < orig.height)
		{
			j = 0;
			while (j < orig.width)
			{
				printf("%d ", orig.worldMap[j][k]);
				j++;
			}
			printf("\n");
			k++;
		}
		wolf(orig);
	}
	else
		return (0);
}
