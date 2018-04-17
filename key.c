/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:41:35 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/04/17 15:28:54 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_orig	key(t_orig orig)
{
	SDL_PollEvent(&orig.sdl.event);
	orig.sdl.event.type == SDL_QUIT ? orig.done = 1 : 0;
	orig.sdl.event.key.keysym.scancode == SDL_SCANCODE_ESCAPE ? orig.done = 1 : 0;
	const Uint8 *keykey = SDL_GetKeyboardState(NULL);		
			if (keykey[SDL_SCANCODE_UP])
			{
				orig.worldMap[(int)(orig.player.posX + orig.player.dirX * orig.player.moveSpeed)][(int)(orig.player.posY)] == false ? orig.player.posX += orig.player.dirX * orig.player.moveSpeed : 0;
				orig.worldMap[(int)(orig.player.posX)][(int)(orig.player.posY + orig.player.dirY * orig.player.moveSpeed)] == false ? orig.player.posY += orig.player.dirY * orig.player.moveSpeed : 0;
				if (orig.flag == 1)
				{
					if (orig.weapon == 2 || orig.weapon == 3)
					{
						orig.sdl.dWEAP.y+=1;
						orig.sdl.dWEAP.w+=1;
					}
					else
					{
						orig.sdl.dWEAP.y+=2;
						orig.sdl.dWEAP.w+=2;
					}
					if (orig.weapon == 4)
					{
						orig.sdl.ddag.y += 2;
						orig.sdl.dfdag.y -= 2;
						
					}
					if (orig.sdl.dWEAP.y >= 150)
						orig.flag = 0;
				}
				if (orig.flag == 0)
				{
					if (orig.weapon == 2 || orig.weapon == 3)
					{
						orig.sdl.dWEAP.y-=1;
						orig.sdl.dWEAP.w-=1;
					}
					else
					{
						orig.sdl.dWEAP.y-=2;
						orig.sdl.dWEAP.w-=2;
					}
					if (orig.weapon == 4)
					{
						orig.sdl.ddag.y -= 2;
						orig.sdl.dfdag.y += 2;
						
					}
					if (orig.sdl.dWEAP.y <= 120)
						orig.flag = 1;
				}
			}
			if (keykey[SDL_SCANCODE_DOWN])
			{
				orig.worldMap[(int)(orig.player.posX - orig.player.dirX * orig.player.moveSpeed)][(int)(orig.player.posY)] == false ? orig.player.posX -= orig.player.dirX * orig.player.moveSpeed : 0;
				orig.worldMap[(int)(orig.player.posX)][(int)(orig.player.posY - orig.player.dirY * orig.player.moveSpeed)] == false ? orig.player.posY -= orig.player.dirY * orig.player.moveSpeed : 0;
				if (orig.flag == 1)
				{
					if (orig.weapon == 2 || orig.weapon == 3)
					{
						orig.sdl.dWEAP.y+=1;
						orig.sdl.dWEAP.w+=1;
					}
					else
					{
						orig.sdl.dWEAP.y+=2;
						orig.sdl.dWEAP.w+=2;
					}
					if (orig.weapon == 4)
					{
						orig.sdl.ddag.y += 2;
						orig.sdl.dfdag.y -= 2;
						
					}
					if (orig.sdl.dWEAP.y >= 150)
						orig.flag = 0;
				}
				if (orig.flag == 0)
				{
					if (orig.weapon == 2 || orig.weapon == 3)
					{
						orig.sdl.dWEAP.y-=1;
						orig.sdl.dWEAP.w-=1;
					}
					else
					{
						orig.sdl.dWEAP.y-=2;
						orig.sdl.dWEAP.w-=2;
					}
					if (orig.weapon == 4)
					{
						orig.sdl.ddag.y -= 2;
						orig.sdl.dfdag.y += 2;
						
					}
					if (orig.sdl.dWEAP.y <= 120)
						orig.flag = 1;
				}
			}
			if (keykey[SDL_SCANCODE_RIGHT])
			{
				double oldDirX = orig.player.dirX;
				orig.player.dirX = orig.player.dirX * cos(-orig.player.rotSpeed) - orig.player.dirY * sin(-orig.player.rotSpeed);
				orig.player.dirY = oldDirX * sin(-orig.player.rotSpeed) + orig.player.dirY * cos(-orig.player.rotSpeed);
				double oldPlaneX = orig.player.planeX;
				orig.player.planeX = orig.player.planeX * cos(-orig.player.rotSpeed) - orig.player.planeY * sin(-orig.player.rotSpeed);
				orig.player.planeY = oldPlaneX * sin(-orig.player.rotSpeed) + orig.player.planeY * cos(-orig.player.rotSpeed);
				if (orig.flag == 1)
				{
					if (orig.weapon == 2 || orig.weapon == 3)
					{
						orig.sdl.dWEAP.y+=1;
						orig.sdl.dWEAP.w+=1;
					}
					else
					{
						orig.sdl.dWEAP.y+=2;
						orig.sdl.dWEAP.w+=2;
					}
					if (orig.weapon == 4)
					{
						orig.sdl.ddag.y += 2;
						orig.sdl.dfdag.y -= 2;
						
					}
					if (orig.sdl.dWEAP.y >= 150)
						orig.flag = 0;
				}
				if (orig.flag == 0)
				{
					if (orig.weapon == 2 || orig.weapon == 3)
					{
						orig.sdl.dWEAP.y-=1;
						orig.sdl.dWEAP.w-=1;
					}
					else
					{
						orig.sdl.dWEAP.y-=2;
						orig.sdl.dWEAP.w-=2;
					}
					if (orig.weapon == 4)
					{
						orig.sdl.ddag.y -= 2;
						orig.sdl.dfdag.y += 2;
						
					}
					if (orig.sdl.dWEAP.y <= 120)
						orig.flag = 1;
				}
			}
			if (keykey[SDL_SCANCODE_LEFT])
			{
				double oldDirX = orig.player.dirX;
				orig.player.dirX = orig.player.dirX * cos(orig.player.rotSpeed) - orig.player.dirY * sin(orig.player.rotSpeed);
				orig.player.dirY = oldDirX * sin(orig.player.rotSpeed) + orig.player.dirY * cos(orig.player.rotSpeed);
				double oldPlaneX = orig.player.planeX;
				orig.player.planeX = orig.player.planeX * cos(orig.player.rotSpeed) - orig.player.planeY * sin(orig.player.rotSpeed);
				orig.player.planeY = oldPlaneX * sin(orig.player.rotSpeed) + orig.player.planeY * cos(orig.player.rotSpeed);
				if (orig.flag == 1)
				{
					if (orig.weapon == 2 || orig.weapon == 3)
					{
						orig.sdl.dWEAP.y+=1;
						orig.sdl.dWEAP.w+=1;
					}
					else
					{
						orig.sdl.dWEAP.y+=2;
						orig.sdl.dWEAP.w+=2;
					}
					if (orig.weapon == 4)
					{
						orig.sdl.ddag.y += 2;
						orig.sdl.dfdag.y -= 2;
					}
					if (orig.sdl.dWEAP.y >= 150)
						orig.flag = 0;
				}
				if (orig.flag == 0)
				{
					if (orig.weapon == 2 || orig.weapon == 3)
					{
						orig.sdl.dWEAP.y-=1;
						orig.sdl.dWEAP.w-=1;
					}
					else
					{
						orig.sdl.dWEAP.y-=2;
						orig.sdl.dWEAP.w-=2;
					}
					if (orig.weapon == 4)
					{
						orig.sdl.ddag.y -= 2;
						orig.sdl.dfdag.y += 2;
					}
					if (orig.sdl.dWEAP.y <= 120)
						orig.flag = 1;
				}
			}
			if (keykey[SDL_SCANCODE_2])
				orig.weapon = 1;
			if (keykey[SDL_SCANCODE_1])
				orig.weapon = 0;
			if (keykey[SDL_SCANCODE_3])
				orig.weapon = 2;
			if (keykey[SDL_SCANCODE_4])
				orig.weapon = 3;
			if (keykey[SDL_SCANCODE_5])
				orig.weapon = 4;
		return (orig);
}