/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ternary.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:07:07 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/07/29 12:30:31 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

double	ternary(bool condition, double true_case, double false_case)
{
	if (condition)
		return (true_case);
	return (false_case);
}

int	int_ternary(bool condition, int true_case, int false_case)
{
	if (condition)
		return (true_case);
	return (false_case);
}

void	cast_rays_helper(t_window *conf)
{
	conf->wall.line_distance = malloc(sizeof(double) * conf->ray.num_rays);
	conf->wall.wx = malloc(sizeof(double) * conf->ray.num_rays);
	conf->wall.wy = malloc(sizeof(double) * conf->ray.num_rays);
	conf->ray.rayangle = malloc(sizeof(double) * conf->ray.num_rays);
	conf->wall.hitver = malloc(sizeof(double) * conf->ray.num_rays);
	conf->wall.faceup = malloc(sizeof(double) * conf->ray.num_rays);
	conf->wall.facedown = malloc(sizeof(double) * conf->ray.num_rays);
	conf->wall.faceright = malloc(sizeof(double) * conf->ray.num_rays);
	conf->wall.faceleft = malloc(sizeof(double) * conf->ray.num_rays);
	conf->wall.con = malloc(sizeof(double) * conf->ray.num_rays);
	if (!conf->wall.wx || !conf->wall.wy || !conf->ray.rayangle
		|| !conf->wall.line_distance || !conf->wall.hitver
		|| !conf->wall.faceup || !conf->wall.facedown
		|| !conf->wall.faceright || !conf->wall.faceleft
		|| !conf->wall.con)
		exit(display("Malloc Error"));
}

void	clear(t_window *conf)
{
	free(conf->wall.line_distance);
	free(conf->wall.wx);
	free(conf->wall.wy);
	free(conf->ray.rayangle);
	free(conf->wall.hitver);
	free(conf->wall.faceup);
	free(conf->wall.facedown);
	free(conf->wall.faceright);
	free(conf->wall.faceleft);
	free(conf->wall.con);
	free(conf->elem);
	free(conf->color);
	ft_free_arr(conf->map);
	if (conf->old_map != NULL)
		ft_free_arr(conf->old_map);
}
