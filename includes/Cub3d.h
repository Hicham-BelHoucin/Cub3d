/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 09:25:31 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/17 14:53:22 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <float.h>
# include <time.h>
# include <stdbool.h>
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define ESC 53
# define W 13
# define VITESS 8
# define A 0
# define S 1
# define D 2
# define SPACE 49
# define TOBACK 124
# define TOFORWARD 123
# define F 3
# define R 15
# define ANG 3.14
# define TILE_SIZE 64
# define WIDTH 1200
# define HEIGHT 800
# define PI 3.1415926535 
# define FOV 1.047198
# define NORTHTEXTURE "NO"
# define SOUTHTEXTURE "SO"
# define WESTTEXTURE "WE"
# define EASTTEXTURE "EA"
# define RED "\033[0;31m"

typedef struct s_player {
	int		dxx;
	int		dyy;
	double	px;
	double	ag;
	double	py;
	double	rotangle;
	double	rotspeed;
	int		movespeed;
	double	tdirection;
	double	rspeed;
	double	movestep;
	double	walkdirection;
	int		to_a;
	int		to_s;
	int		to_d;
	int		to_w;
	int		to_forward;
	int		to_back;
	int		to_space;
	double	fov;
}				t_player;
typedef struct ray
{
	double	fov;
	double	*rayangle;
	double	num_rays;
	double	horwallhitx;
	double	horwallhity;
	double	verwallhitx;
	double	verwallhity;
	double	distance;
	double	xstep;
	double	ystep;
	double	xintercept;
	double	yintercept;
	int		facingdown;
	int		facingup;
	int		facingright;
	int		facingleft;
	double	nexthox;
	double	nexthoy;
	double	nextverx;
	double	nextvery;
	double	xhortocheck;
	double	yhortocheck;
	double	xvertocheck;
	double	yvertocheck;
	double	foundhorwallhit;
	double	foundverwallhit;
	double	verdist;
	double	hordist;
	double	wallhitx;
	double	wallhity;
	double	washitvert;
	int		verwallcontent;
	int		horwallcontent;
	int		wallcon;
}	t_ray;
typedef struct s_wall
{
	int		wallstripheight;
	double	distancepro;
	double	playerwalldist;
	int		drawstartx;
	int		drawstarty;
	double	*line_distance;
	double	corrwall;
	int		topwall;
	int		bottomwall;
	int		*hitver;
	double	*wx;
	double	*wy;
	double	*faceup;
	double	*facedown;
	double	*faceright;
	double	*faceleft;
	int		*con;
	int		a;
}	t_wall;

typedef struct s_texture
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
	float	x;
	float	y;
}	t_texture;
typedef struct s_data
{
	t_list	*elements;
	t_list	*map;
	t_list	*colors;
}	t_data;

typedef struct s_elements
{
	char		*identifier;
	char		*path;
	t_texture	texture;
}	t_elements;

typedef struct s_colors
{
	char	*identifier;
	int		color;
}	t_colors;

typedef struct s_window
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*addr;
	int			bits;
	int			size;
	int			endian;
	int			map_x;
	int			map_y;
	int			r;
	int			ammo;
	char		**map;
	char		**old_map;
	t_elements	*elem;
	t_colors	*color;
	t_player	player;
	int			txtnbr;
	t_texture	door;
	t_ray		ray;
	t_wall		wall;
}	t_window;

//////////////////////////////// [ Parsing ] /////////////////////

char		*get_next_line(int fd);
void		ft_replace_spaces(char **temp);
int			check_map_colors(t_list *colors, t_colors *tofill, char **temp);
int			check_valid_path(char **map, int row, int colm);
t_data		ft_getmap(int fd);
int			check_duplicate_player(char **temp);
size_t		ft_arr_length(char **map);
void		clear_list(t_list *list);
int			check_map_content(char	**temp, char *charset);
int			check_map_elements(t_list *elements, t_elements **tofill);
char		**list_to_char(t_list *list);
void		ft_free_arr(char **buffer);
int			check_top_path(char **map, int i, int j);
int			check_left_path(char **map, int row, int j);
int			get_color(int r, int g, int b);

//////////////////////////////// [ Displaying Errors ] /////////////////////

int			print_error_pos(int row, int column, char c);
void		print_error(char *str, t_data data);
int			display(char *error);

//////////////////////////////// [ Creating Window ] /////////////////////

int			create_window(t_data data, t_elements *elm, t_colors *col);

//////////////////////////////// [ Handling Textures ] /////////////////////

int			check_texture_name(t_elements **tofill, int i);
t_texture	load_img(char *path, void *mlx);

//////////////////////////////// [Casting Rays] /////////////////////

void		rayfacing(t_window *conf, double _ang);
void		cast_rays_helper(t_window *conf);
void		clear(t_window *conf);
void		cast_rays(t_window *conf);
double		normalize_ang(double angle);
void		hoz_intersection_helper(t_window *conf);
void		ver_intersection_helper(t_window *conf);
char		has_wall(t_window *conf, double x, double y);
double		disbtp(double x1, double y1, double x2, double y2);

//////////////////////////////// [ternary functions] /////////////////////

double		ternary(bool condition, double true_case, double false_case);
int			int_ternary(bool condition, int true_case, int false_case);

//////////////////////////////// [Draw Ceilling And Floor] /////////////////////

void		draw_ceilling_or_floor(t_window *window, char *identifier);

//////////////////////////////// [ Drawing Walls ] /////////////////////

void		rendering_walls(t_window *window);
void		draw_wall(t_window *conf);
char		has_wall(t_window *conf, double x, double y);
void		render3d(t_window *conf);
void		texture_facing(t_window *conf);

//////////////////////////////// [ Handle Keys] /////////////////////

int			player_move(int key, t_window *conf);
int			keyrealeased(int key, t_window *conf);
int			close_win(t_window *conf);
int			mouse_hook(int x, int y, t_window *conf);
void		rotate(t_window *conf);
void		move_to(t_window *conf);

//////////////////////////////// [Init funtions] /////////////////////

void		set_up_all(t_window *conf);
void		set_rotangle(double *rot, char c);
void		init_all(t_window *conf);
void		set_players_position(int *x, int *y, char **map);
void		get_filled_map(char **map);

#endif // CUB3D_H