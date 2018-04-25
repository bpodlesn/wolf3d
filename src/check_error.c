/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 11:12:43 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/04/24 13:41:54 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_error(int i)
{
	i == 1 ? ft_putendl("Map should be X * X") : 0;
	i == 2 ? ft_putendl("Put X not in borders") : 0;
	i == 3 ? ft_putendl("Just one X is available") : 0;
	i == 4 ? ft_putendl("Put at least one X on the map") : 0;
	i == 5 ? ft_putendl("Min map 3*3") : 0;
	i == 6 ? ft_putendl("No more than 30*30") : 0;
	i == 0 ? ft_putendl("Put valid map") : 0;
	i == 7 ? ft_putendl("Only space is available") : 0;
	i == 8 ? ft_putendl("Not ascii symbol") : 0;
	i == 9 ? ft_putendl("bye") : 0;
	exit(0);
}

void		check_if(t_orig orig)
{
	int		i;
	int		xcount;

	i = 0;
	xcount = 0;
	orig.height > 30 && orig.width > 30 ? ft_error(6) : 0;
	while (BUF != '\0' && i++ > -1)
		BUF == 'X' ? xcount++ : 0;
	xcount > 1 ? ft_error(3) : 0;
	xcount < 1 ? ft_error(4) : 0;
	(orig.height != orig.width) ||
		(orig.height <= 2 && orig.width <= 2) ? ft_error(5) : 0;
}
