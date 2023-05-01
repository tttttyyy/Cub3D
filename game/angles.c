/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:58:12 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:58:13 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double fix_angle(double a)
{
	if (a >= 360)
		a = a - 360;
	else if (a <= -1) 
		a = a + 360;
	return (a);
}

double degToRad(int a)
{
	return (a * PI / 180.0);
}

double	ray_dist(t_ray *ray)
{
	double	x;

	x = cos(degToRad(ray->ra)) * (ray->rx - ray->posx)
		- sin(degToRad(ray->ra)) * (ray->ry - ray->posy);
	return (x);
}