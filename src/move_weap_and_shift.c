/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_weap_and_shift.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:03:57 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/04/23 16:10:38 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_orig			move_weapons(t_orig orig)
{
	static int	davai;

	if (WEAPON == 2 || WEAPON == 3)
		davai = 1 * orig.flag;
	else if (WEAPON == 1 || WEAPON == 5 || WEAPON == 0 || WEAPON == 4)
		davai = 2 * orig.flag;
	orig.sdl.dweap.y += davai;
	orig.sdl.dweap.w += davai;
	orig.sdl.ddag.y -= davai;
	orig.sdl.dfdag.y += davai;
	return (orig);
}

t_orig			shift(t_orig orig, double oldx, double oldy)
{
	orig.move_flag = 10;
	if (oldx != orig.player.pos_x || oldy != orig.player.pos_y)
		orig = move_weapons(orig);
	return (orig);
}
