/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:42:54 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/04/17 17:23:39 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char		*ft_strjo(char *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(*str) * (len1 + len2 + 1))))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	free(s1);
	return (str);
}

int			how_many(char *line, int counter)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
		{
			while (line[i] == ' ')
			{
				if (line[i + 1] != ' ' && line[i + 1] != '\0')
					j = 0;
				i++;
			}
		}
		if (j == 0)
		{
			counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

t_orig		z(t_orig orig)
{
	int		i;
	int		n = 0;
	int 	j = 0;

	i = 0;
	orig.i = 0;
	while (orig.buf[i] != '\0')
	{
		j = 0;
		while (orig.buf[i] != '\n' && orig.buf[i] != '\0')
		{
			if (orig.buf[i] != '\n' || orig.buf[i] != ' ' || orig.buf[i] != '\0')
			{
				if (orig.buf[i] == 'X')
				{	
					if (j == 0 || j == orig.height || n == 0 || n == orig.width - 1)
					{
						ft_putendl("put X not in borders");
						exit (0);
					}
					orig.player.posX = n + 0.1;
					orig.player.posY = j - 1 + 0.1;
					orig.worldMap[n][j] = 0;
					i++;
				}
				else if (orig.buf[i] != '\n' || orig.buf[i] != ' ' || orig.buf[i] != '\0')
				{
					orig.worldMap[n][j] = ft_atoi1(orig.buf, &i);
					if ((orig.buf[i] >= 33 && orig.buf[i] < 88) || (orig.buf[i] > 88))
						i++;
					j++;
				}
			}
			else
				i++;
		}
		i++;
		n++;
		printf("\n");
	}
	return (orig);
}



t_orig		defence_map(t_orig orig)
{
	int i;

	i = 0;
	while(i < orig.height)
	{
		if (orig.worldMap[0][i] == 0)
			orig.worldMap[0][i] = 1;
		if (orig.worldMap[orig.width - 1][i] > 0 && orig.worldMap[orig.width - 1][i] < 2)
			orig.worldMap[orig.width - 1][i] = 1;
		i++;
	}
	i = 0;
	while(i < orig.width)
	{
		if (orig.worldMap[i][0] == 0)
			orig.worldMap[i][0] = 1;
		if (orig.worldMap[i][orig.height - 1] > 0 && orig.worldMap[i][orig.height - 1] < 2)
			orig.worldMap[i][orig.height - 1] = 1;
		i++;
	}
	return (orig);
}

void	check_if(t_orig orig)
{
	int i;
	int xcount;

	i = 0;
	xcount = 0;
	if (orig.height > 30 && orig.width > 30)
	{
		ft_putendl("No more than 20*20");
		exit (0);
	}
	while (orig.buf[i] != '\0')
	{
		orig.buf[i] == 'X' ? xcount = 1 : 0;
		i++;
	}
	if (xcount != 1)
	{
		ft_putendl("put X on map");
		exit (0);
	}
	else if ((orig.height != orig.width) || (orig.height <= 2 && orig.width <= 2))
	{
		ft_putendl("put map X * X");
		exit (0);
	}
	// while (orig.buf[i] != '\0')
	// {
	// 	if ()
	// }
}

t_orig reader(t_orig orig, int fd)
{
	char *line;
	char *asd;
	int i = 0;

	orig.buf = ft_strnew(100);
	orig.height = 0;
	orig.width = 0;
	while(get_next_line(fd, &line) > 0 && orig.height++ > -1)
	{
		asd = line;
		if (orig.width == 0)
			orig.width = how_many(line, 0);
		else if (orig.width != how_many(line, 0))
		{
			ft_putendl("Map should be X * X");
			exit (0);
		}
		orig.buf = ft_strjo(ft_strjo(orig.buf, line), "\n");
		free(asd);
	}
	orig.width == 0 ? exit(0) : 0;
	get_next_line(fd, &line) <= -1 ? exit(0) : 0;
	orig.worldMap = (int**)malloc(sizeof(int*) * orig.width);
	while(i < orig.height)
	{
		orig.worldMap[i] = (int*)malloc(sizeof(int) * orig.height);
		i++;
	}
	check_if(orig);
	printf("%d\n", orig.height);
	printf("%d\n", orig.width);
	orig = z(orig);
	orig = defence_map(orig);
	return (orig);
}
