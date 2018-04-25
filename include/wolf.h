/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 12:24:42 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/04/24 13:35:07 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <stdbool.h>
# include <SDL_image.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/src/libft.h"
# define TEXH 64
# define TEXW 64
# define WINH 600
# define WINW 800
# define RENDER orig->sdl.renderer
# define RENDERER orig.sdl.renderer
# define WEAPSURFACE orig->sdl.weaponsurf
# define DBAXESURF orig->sdl.doubleaxesurf
# define HAMSURF orig->sdl.hammersurf
# define DAGSURF orig->sdl.daggersurf
# define FDAGSURF orig->sdl.firstdaggersurf
# define WEAPON orig.weapon
# define DHUD orig.sdl.dhud
# define SHUD orig.sdl.shud
# define SWEAP orig.sdl.sweap
# define DWEAP orig.sdl.dweap
# define DDAG orig.sdl.ddag
# define DFDAG orig.sdl.dfdag
# define SDAG orig.sdl.sdag
# define SFDAG orig.sdl.sfdag
# define BUF orig.buf[i]
# define TEXCOL orig.texcolor
# define DRAWSTR orig.ray.drawstart
# define DRAWEND orig.ray.drawend
# define RAYDIRY orig.ray.ray_dir_y
# define RAYDIRX orig.ray.ray_dir_x
# define SIDE orig.side
# define TEX orig.texture
# define ARR orig.arr
# define STEP_X orig.ray.stepby_x
# define STEP_Y orig.ray.stepby_y
# define WALL_DIS orig.ray.prp_wall_dis
# define RAY_MAP_X orig.ray.map_x
# define RAY_MAP_Y orig.ray.map_y
# define POS_X orig.player.pos_x
# define POS_Y orig.player.pos_y
# define SIDE1 SIDE == 1
# define SIDE0 SIDE == 0
# define SIDEN SIDE != 0
# define FROM9TOX BUF > 57 && BUF < 88
# define TO0 BUF >= 33 && BUF < 48

typedef struct		s_sdl
{
	SDL_Rect		srcrect;
	SDL_Rect		dstrect;
	SDL_Rect		shud;
	SDL_Rect		dhud;
	SDL_Rect		sweap;
	SDL_Rect		dweap;
	SDL_Rect		sdag;
	SDL_Rect		ddag;
	SDL_Rect		sfdag;
	SDL_Rect		dfdag;
	SDL_Event		event;
	SDL_Window		*win;
	SDL_Surface		*surface;
	SDL_Surface		*hud2;
	SDL_Surface		*hud3;
	SDL_Surface		*hud4;
	SDL_Surface		*hud5;
	SDL_Surface		*hud6;
	SDL_Surface		*weaponsurf;
	SDL_Surface		*axesurf;
	SDL_Surface		*doubleaxesurf;
	SDL_Surface		*hammersurf;
	SDL_Surface		*daggersurf;
	SDL_Surface		*firstdaggersurf;
	SDL_Surface		*swrdsurf;
	SDL_Texture		*tex;
	SDL_Texture		*texhud2;
	SDL_Texture		*texhud3;
	SDL_Texture		*texhud4;
	SDL_Texture		*texhud5;
	SDL_Texture		*texhud6;
	SDL_Texture		*fillscreen;
	SDL_Texture		*weapon;
	SDL_Texture		*axe;
	SDL_Texture		*doubleaxe;
	SDL_Texture		*hammer;
	SDL_Texture		*dagger;
	SDL_Texture		*firstdagger;
	SDL_Texture		*swrd;
	SDL_Renderer	*renderer;
}					t_sdl;

typedef struct		s_frame
{
	double			time;
	double			oldtime;
	double			frametime;
}					t_frame;

typedef	struct		s_player
{
	double			movespeed;
	double			rotspeed;
	double			dir_x;
	double			dir_y;
	double			pos_x;
	double			pos_y;
	double			plane_x;
	double			plane_y;
}					t_player;

typedef struct		s_ray
{
	int				drawstart;
	int				drawend;
	int				map_x;
	int				map_y;
	double			ray_dir_x;
	double			ray_dir_y;
	double			del_dis_x;
	double			del_dis_y;
	double			prp_wall_dis;
	double			side_dis_x;
	double			side_dis_y;
	int				stepby_x;
	int				stepby_y;
	int				line_height;
}					t_ray;

typedef struct		s_orig
{
	t_frame			frame;
	t_sdl			sdl;
	t_player		player;
	t_ray			ray;
	int				*texture[19];
	int				*skybox;
	int				flag;
	int				done;
	int				**worldmap;
	int				height;
	int				width;
	char			*buf;
	int				i;
	int				**arr;
	int				*screen;
	int				side;
	int				hit;
	int				weapon;
	int				tic;
	int				texcolor;
	int				x;
	int				move_flag;
}					t_orig;

void				wolf(t_orig orig, int x, int count);
t_orig				set_texture_params(t_orig orig);
t_orig				set_tex_params_2(t_orig orig);
t_orig				set_values(t_orig orig);
void				set_tex_color2(t_orig *orig);
int					set_rgb(unsigned int r, unsigned int g, unsigned int b);
void				ft_get_image(int *pixels, const char *path, int tex);
void				create_sdl_and_hud(t_orig *orig);
t_orig				key(t_orig orig, double old_x, double old_y);
char				*ft_strjo(char *s1, char const *s2);
int					how_many(char *line, int counter, int i, int j);
t_orig				reader(t_orig orig, int fd, int i);
t_orig				map(t_orig orig, int i, int n, int j);
t_orig				get_textures(t_orig orig, int i);
t_orig				stepby_and_disray(t_orig orig);
void				create_weapons(t_orig *orig);
void				create_sdl_and_hud(t_orig *orig);
t_orig				update_texture(t_orig orig);
t_orig				check_weapon(t_orig orig);
t_orig				set_texture_params(t_orig orig);
t_orig				free_exit(t_orig orig);
void				ft_error(int i);
void				check_if(t_orig orig);
t_orig				set_tex_params_2(t_orig orig);
void				set_tex_color(t_orig *orig);
t_orig				move_weapons(t_orig orig);
t_orig				update_sky(t_orig orig);
t_orig				shift(t_orig orig, double oldx, double oldy);
t_orig				dda_perform(t_orig orig);
t_orig				calc_raydir_pos(t_orig orig, int x);

#endif
