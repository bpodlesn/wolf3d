/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 11:26:59 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/04/24 13:39:25 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_orig		free_exit(t_orig orig)
{
	int		i;

	i = 0;
	orig.done = 1;
	free(orig.arr);
	free(orig.screen);
	free(orig.worldmap);
	free(orig.skybox);
	return (orig);
}

int			main(int ac, char **av)
{
	t_orig	orig;

	orig.done = 0;
	if (ac == 2)
	{
		orig = reader(orig, open(av[1], O_RDONLY), -1);
		orig = set_values(orig);
		orig = set_texture_params(orig);
		orig = get_textures(orig, -1);
		create_sdl_and_hud(&orig);
		wolf(orig, -1, 0);
	}
	else
		ft_error(0);
	return (0);
}
