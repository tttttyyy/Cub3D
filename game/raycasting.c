/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:58:41 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:58:42 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vertical(t_tool *hero, t_ray *ray)
{
	//for (r = 0; r < 60; r++)
	//{
	//---Vertical--- 
	int dof = 0;
	ray->tan_ra = tan(degToRad(ray->ra));
	if (cos(degToRad(ray->ra))> 0.001)
	{
		ray->rx = (((int)ray->posx >> 6) << 6) + 64;
		ray->ry = (ray->posx - ray->rx) * ray->tan_ra + ray->py;
		ray->xo = 64;
		ray->yo = -64 * ray->tan_ra;
	}//looking left
	else if (cos(degToRad(ray->ra))<-0.001)
	{
		ray->rx = (((int)ray->posx >> 6) << 6) -0.0001;
		ray->ry = (ray->posx - ray->rx) * ray->tan_ra + ray->py;
		ray->xo = -64;
		ray->yo = 64 * ray->tan_ra;
	}//looking right
	else // not clear from here
	{
		ray->rx=ray->posx;
		ray->ry=ray->posy;
		dof=8;
	}      //looking up or down. no hit 
	while(dof<8) 
	{ 
		mx=(int)(rx)>>6;
		my=(int)(ry)>>6;
		mp=my*mapX+mx;                     
		if (mp>0 && mp<mapX*mapY && map[mp]==1)
		{
			dof = 8;
			hero->dis = ray_dist(ray);
		}//hit         
		else
		{
			rx += ray->xo;
			ry += ray->yo;
			dof+=1; 
		} //check next horizontal
	} 
	ray->vx = ray->rx;
	ray->vy = ray->ry;
}

void	horizontal(t_tool *hero, t_ray *ray)
{
	int	dof;

	dof = 0;
	ray->atan_ra = 1.0 / tan(deg_to_rad(ray->ra));
	if (sin(degToRad(ray->ra)) > 0.001)
	{
		ray->ry = (((int)ray->posy >> 6) << 6) - 0.0001;
		ray->rx = (ray->posy - ray->ry) * ray->atan_ra + ray->posx;
		ray->yo = -64;
		ray->xo = 64 * ray->atan_ra;
	}//looking up
	else if (sin(degToRad(ray->ra))<-0.001)
	{
		ray->ry = (((int)py >> 6) << 6) + 64;
		ray->rx = (ray->posy - ray->ry) * ray->atan_ra + ray->posx;
		ray->yo = 64;
		ray->xo = -64 * ray->atan_ra;
	}//looking down
	else
	{
		ray->rx = ray->posx;
		ray->ry = ray->posy;
		dof=8;
	}//looking straight left or right
	while (dof < 8)
	{
		mx=(int)(ray->rx) >> 6;
		my=(int)(ray->ry) >> 6;
		mp=my*mapX+mx;
		if(mp > 0 && mp<mapX*mapY && map[mp]==1)
		{
			dof=8;
			disH=cos(degToRad(ra))*(rx-px)-sin(degToRad(ra))*(ry-py);
		}//hit
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			dof += 1;
		}//check next horizontal
	} 
  
}

void	raycasting(t_tool *hero, t_ray *ray)
{
	int	i;
	
	i = 0;
	ray->ra = fix_angle(hero->pdp.pa + 30);
	ray->posx = hero->pdp.posx * 64;
	ray->posy = hero->pdp.posy * 64;
	while (i < 1024)
	{
		hero->dis = 1000000;
		vertical(hero, ray);
		//write for vertical and horizontal
		hero->dis = hero->dis * cos(deg_to_rad
			(fix_angle(hero->pdp.pa - ray->ra)));
		ray->ra = fix_angle(ray->ra - hero->angle);
		++i;
	}
}