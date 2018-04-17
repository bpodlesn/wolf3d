/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:06:24 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/04/17 16:10:53 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int					set_rgb(unsigned int r, unsigned int g, unsigned int b)
{
 return ((r << 16) | (g << 8) | b);
}

static int			get_col_by_i(void *ptr, int i)
{
	unsigned char *tmp;

	tmp = (unsigned char*)ptr;
	return (set_rgb(tmp[i + 2], tmp[i + 1], tmp[i]));
}

void			ft_get_image(int *pixels, const char *path)
{
	SDL_Surface		*sur;
	int				i;
	int				size;
	int				k;

	i = -1;
	size = texH * texW;
	k = 0;
	sur = IMG_Load(path);
	while (++i < size)
	{
		pixels[i] = get_col_by_i(sur->pixels, k);
		k += 4;
	}
	SDL_FreeSurface(sur);
}

void			ft_get_image2(int *pixels, const char *path)
{
	SDL_Surface		*sur;
	int				i;
	int				size;
	int				k;

	i = -1;
	size = 640*480;
	k = 0;
	sur = IMG_Load(path);
	while (++i < size)
	{
		pixels[i] = get_col_by_i(sur->pixels, k);
		k += 4;
	}
	SDL_FreeSurface(sur);
}

t_orig	get_textures(t_orig orig)
{
	int i;

	i = 0;
	orig.skybox = (int*)malloc(sizeof(int) * (800*600));
	while (i < 19)
	{
		orig.texture[i] = (int*)malloc(sizeof(int) * (int)texH * (int)texW);
		i++;
	}
	ft_get_image(orig.texture[0], "images/textures/1-1.png");
	ft_get_image(orig.texture[1], "images/textures/1-2.png");
	ft_get_image(orig.texture[2], "images/textures/1-3.png");
	ft_get_image(orig.texture[3], "images/textures/1-4.png");
	ft_get_image(orig.texture[4], "images/textures/1.png");
	ft_get_image(orig.texture[5], "images/textures/2.png");
	ft_get_image(orig.texture[6], "images/textures/3.png");
	ft_get_image(orig.texture[7], "images/textures/4.png");
	ft_get_image(orig.texture[8], "images/textures/5.png");
	ft_get_image(orig.texture[9], "images/textures/6.png");
	ft_get_image(orig.texture[10], "images/textures/7.png");
	ft_get_image(orig.texture[11], "images/textures/8.png");
	ft_get_image(orig.texture[12], "images/textures/9.png");
	ft_get_image(orig.texture[13], "images/textures/10.png");
	ft_get_image(orig.texture[14], "images/textures/11.png");
	ft_get_image(orig.texture[15], "images/textures/12.png");
	ft_get_image(orig.texture[16], "images/textures/13.png");
	ft_get_image(orig.texture[17], "images/textures/14.png");
	ft_get_image2(orig.skybox, "images/sky.png");
	return (orig);
}
