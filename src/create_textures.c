/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:06:24 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/04/23 16:12:41 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_orig				update_sky(t_orig orig)
{
	static int		check;

	if (check == 1)
	{
		orig.tic -= 1;
		if (orig.tic == 0)
			check = 0;
	}
	else
	{
		orig.tic += 1;
		if (orig.tic == 50)
			check = 1;
	}
	return (orig);
}

int					set_rgb(unsigned int r, unsigned int g, unsigned int b)
{
	return ((r << 16) | (g << 8) | b);
}

static int			get_col_by_i(void *ptr, int i)
{
	unsigned char	*tmp;

	tmp = (unsigned char*)ptr;
	return (set_rgb(tmp[i + 2], tmp[i + 1], tmp[i]));
}

void				ft_get_image(int *pixels, const char *path, int tex)
{
	SDL_Surface		*sur;
	int				i;
	int				size;
	int				k;

	i = -1;
	if (tex == 0)
		size = TEXH * TEXW;
	else
		size = 640 * 480;
	k = 0;
	sur = IMG_Load(path);
	while (++i < size)
	{
		pixels[i] = get_col_by_i(sur->pixels, k);
		k += 4;
	}
	SDL_FreeSurface(sur);
}

t_orig				get_textures(t_orig orig, int i)
{
	orig.skybox = (int*)malloc(sizeof(int) * (800 * 600));
	while (++i < 18)
		orig.texture[i] = (int*)malloc(sizeof(int) * (int)TEXH * (int)TEXW);
	ft_get_image(orig.texture[0], "images/textures/1-1.png", 0);
	ft_get_image(orig.texture[1], "images/textures/1-2.png", 0);
	ft_get_image(orig.texture[2], "images/textures/1-3.png", 0);
	ft_get_image(orig.texture[3], "images/textures/1-4.png", 0);
	ft_get_image(orig.texture[4], "images/textures/1.png", 0);
	ft_get_image(orig.texture[5], "images/textures/2.png", 0);
	ft_get_image(orig.texture[6], "images/textures/3.png", 0);
	ft_get_image(orig.texture[7], "images/textures/4.png", 0);
	ft_get_image(orig.texture[8], "images/textures/5.png", 0);
	ft_get_image(orig.texture[9], "images/textures/6.png", 0);
	ft_get_image(orig.texture[10], "images/textures/7.png", 0);
	ft_get_image(orig.texture[11], "images/textures/8.png", 0);
	ft_get_image(orig.texture[12], "images/textures/9.png", 0);
	ft_get_image(orig.texture[13], "images/textures/10.png", 0);
	ft_get_image(orig.texture[14], "images/textures/11.png", 0);
	ft_get_image(orig.texture[15], "images/textures/12.png", 0);
	ft_get_image(orig.texture[16], "images/textures/13.png", 0);
	ft_get_image(orig.texture[17], "images/textures/14.png", 0);
	ft_get_image(orig.skybox, "images/textures/sky.png", 1);
	return (orig);
}
