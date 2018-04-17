/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 12:24:42 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/04/17 15:36:06 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <SDL_image.h>
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft/libft.h"

#define mapWidth 24
#define mapHeight 24

#define texH 64
#define texW 64

#define winH 600
#define winW 800

typedef struct	s_frame
{
	double time;
	double oldtime;
	double frameTime;
}				t_frame;

typedef	struct s_player
{
	double 		moveSpeed;
	double 		rotSpeed;
	double 		dirX;
	double 		dirY;
	double		posX;
	double		posY;
	double		planeX;
	double		planeY;
}				t_player;

typedef struct	s_sdl
{
	SDL_Window* win;
	SDL_Renderer* renderer;
	SDL_Event event;
	SDL_Rect srcrect;
	SDL_Rect dstrect;
	SDL_Rect sHUD;
	SDL_Rect dHUD;
	SDL_Rect sWEAP;
	SDL_Rect dWEAP;
	SDL_Rect sdag;
	SDL_Rect ddag;
	SDL_Rect sfdag;
	SDL_Rect dfdag;
	SDL_Surface* surface;
	SDL_Surface* weaponsurf;
	SDL_Surface* axesurf;
	SDL_Surface* doubleaxesurf;
	SDL_Surface* hammersurf;
	SDL_Surface* daggersurf;
	SDL_Surface* firstdaggersurf;
	SDL_Texture* tex;
	SDL_Texture* fillscreen;
	SDL_Texture* weapon;
	SDL_Texture* axe;
	SDL_Texture* doubleaxe;
	SDL_Texture* hammer;
	SDL_Texture* dagger;
	SDL_Texture* firstdagger;
}				t_sdl;

typedef struct s_ray
{
	int			drawStart;
	int			drawEnd;
	int			mapX;
	int			mapY;
	double		rayDirX;
	double		rayDirY;
	double		delDisX;
	double		delDisY;
	double		prpWallDis;
	double		sideDisX;
	double		sideDisY;
	int			stepbyX;
	int			stepbyY;
	int			lineHeight;
}				t_ray;

typedef struct 	s_orig
{
	t_frame		frame;
	t_sdl		sdl;
	t_player	player;
	t_ray		ray;
	int			*texture[19];
	int			*skybox;
	int			flag;
	int			done;
	int			**worldMap;
	int			height;
	int			width;
	char		*buf;
	int			i;
	int 		**arr;
	int			*screen;
	int			side;
	int			hit;
	int			weapon;
	int			tic;
}				t_orig;

int					set_rgb(unsigned int r, unsigned int g, unsigned int b);
static int			get_col_by_i(void *ptr, int i);
void			ft_get_image(int *pixels, const char *path);
void			create_sdl(t_orig *orig);
t_orig		key(t_orig orig);
char		*ft_strjo(char *s1, char const *s2);
int			how_many(char *line, int counter);
t_orig		 reader(t_orig orig, int fd);
void			ft_get_image2(int *pixels, const char *path);
t_orig		z(t_orig orig);
t_orig		get_textures(t_orig orig);
