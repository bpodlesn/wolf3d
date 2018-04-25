/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:42:54 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/04/24 13:42:52 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			how_many(char *line, int counter, int i, int j)
{
	while (line[i] != '\0')
	{
		if (line[i] > -1 && line[i] <= 127)
		{
			if (line[i] == ' ')
				while (line[i] == ' ')
				{
					(line[i + 1] != ' ' && line[i + 1] != '\0') ? j = 0 : 0;
					i++;
				}
			line[i] == '\t' ? ft_error(7) : 0;
			if (j == 0)
			{
				counter++;
				j++;
			}
		}
		else
			ft_error(8);
		i++;
	}
	return (counter);
}

t_orig		buf_x(t_orig orig, int *i, int j, int n)
{
	if (j == 0 || j == orig.height || n == 0 || n == orig.width - 1)
		ft_error(2);
	orig.player.pos_x = n + 0.1;
	orig.player.pos_y = j - 1 + 0.1;
	orig.worldmap[n][j] = 0;
	while (orig.buf[(*i)] != '\n' && orig.buf[(*i)] != ' '
		&& orig.buf[(*i)] != '\0')
		(*i)++;
	return (orig);
}

t_orig		map(t_orig orig, int i, int n, int j)
{
	while (BUF != '\0' && i++ > -1)
	{
		j = 0;
		while (BUF != '\n' && BUF != '\0')
		{
			if (BUF != '\n' || BUF != ' ' || BUF != '\0')
			{
				if (BUF == 'X')
					orig = buf_x(orig, &i, j, n);
				else if (BUF != '\n' || BUF != ' ' || BUF != '\0')
				{
					while ((TO0) || (FROM9TOX) || (BUF > 88))
						i++;
					orig.worldmap[n][j] = ft_atoi1(orig.buf, &i);
					orig.worldmap[n][j] <= 0 || orig.worldmap[n][j]
						> 14 ? orig.worldmap[n][j] = 0 : 0;
					j++;
				}
			}
			else
				i++;
		}
		n++;
	}
	return (orig);
}

t_orig		defence_map(t_orig orig)
{
	int		i;

	i = 0;
	while (i < orig.height)
	{
		if (orig.worldmap[0][i] == 0)
			orig.worldmap[0][i] = 1;
		if (orig.worldmap[orig.width - 1][i] <= 0 &&
			orig.worldmap[orig.width - 1][i] <= 14)
			orig.worldmap[orig.width - 1][i] = 1;
		i++;
	}
	i = 0;
	while (i < orig.width)
	{
		if (orig.worldmap[i][0] == 0)
			orig.worldmap[i][0] = 1;
		if (orig.worldmap[i][orig.height - 1] <= 0 &&
			orig.worldmap[i][orig.height - 1] <= 14)
			orig.worldmap[i][orig.height - 1] = 1;
		i++;
	}
	return (orig);
}

t_orig		reader(t_orig orig, int fd, int i)
{
	char	*line;
	char	*asd;

	orig.buf = ft_strnew(100);
	orig.height = 0;
	orig.width = 0;
	while (get_next_line(fd, &line) > 0 && orig.height++ > -1)
	{
		asd = line;
		if (orig.width == 0)
			orig.width = how_many(line, 0, 0, 0);
		else if (orig.width != how_many(line, 0, 0, 0))
			ft_error(1);
		orig.buf = ft_strjo(ft_strjo(orig.buf, line), "\n");
		free(asd);
	}
	get_next_line(fd, &line) <= -1 ? ft_error(0) : 0;
	orig.width == 0 ? ft_error(1) : 0;
	orig.worldmap = (int**)malloc(sizeof(int*) * orig.width);
	while (++i < orig.height)
		orig.worldmap[i] = (int*)malloc(sizeof(int) * orig.height);
	check_if(orig);
	orig = map(orig, 0, 0, 0);
	orig = defence_map(orig);
	return (orig);
}
