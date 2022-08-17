/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 08:28:01 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/07/28 15:04:52 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# define MINIMAP 0.1

# include "Cub3d.h"

typedef struct s_doors
{
	int		x;
	int		y;
	void	*next;
}	t_doors;

void	player_print(t_window *conf);
int		player_move_bonus(int key, t_window *conf);
int		keyrealeased_bonus(int key, t_window *conf);
int		check_map_content_bonus(char **temp, char *charset);
void	ver_intersection_helper_bonus(t_window *conf);
void	hoz_intersection_helper_bonus(t_window *conf);
double	ver_intersection_bonus(t_window *conf, double _ang);
double	hoz_intersection_bonus(t_window *conf, double _ang);
void	try_to_close_door(t_window *conf);
void	print_rectangl(t_window *conf, int y, int x, int color);
void	mapp_print(t_window *conf);
void	open_door(t_window *conf, int pdx, int pdy);
void	move_to_bonus(t_window *conf);
char	**ft_cpy_arr(char **str);
void	rendering_walls_bonus(t_window *window);
void	cast_rays_bonus(t_window *conf);
void	put_pixle(t_window *conf, int y, int offsetx, int offsety);
void	rendering_walls_bonus(t_window *window);

#endif // CUB3D_BONUS_H