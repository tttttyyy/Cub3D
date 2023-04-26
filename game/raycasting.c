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
void	vertical2(t_tool *hero, t_ray *ray)
{
	int		my;
	int		mx;
	char	c;

	while(ray->dof<hero->width) 
	{ 
		mx=(int)(ray->rx)>>6;
		my=(int)(ray->ry)>>6;
		c = get_sym(mx, my, hero);
		// mp=my*mapX+mx;                     
		// if (mp>0 && mp<mapX*mapY && map[mp]==1)
		if (c == '1' || c == 'D')
		{
			ray->dof = 8;
			hero->dis = ray_dist(ray);
		}//hit         
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof+=1; 
		} //check next horizontal
	} 
	ray->vx = ray->rx;
	ray->vy = ray->ry;
}

void	vertical(t_tool *hero, t_ray *ray)
{
	//for (r = 0; r < 60; r++)
	//{
	//---Vertical--- 
	ray->dof = 0;
	(void)hero;
	ray->tan_ra = tan(degToRad(ray->ra));
	if (cos(degToRad(ray->ra))> 0.001)
	{
		ray->rx = (((int)ray->posx >> 6) << 6) + 64;
		ray->ry = (ray->posx - ray->rx) * ray->tan_ra + ray->posy;
		ray->xo = 64;
		ray->yo = -64 * ray->tan_ra;
	}//looking left
	else if (cos(degToRad(ray->ra))<-0.001)
	{
		ray->rx = (((int)ray->posx >> 6) << 6) -0.0001;
		ray->ry = (ray->posx - ray->rx) * ray->tan_ra + ray->posy;
		ray->xo = -64;
		ray->yo = 64 * ray->tan_ra;
	}//looking right
	else // not clear from here
	{
		ray->rx=ray->posx;
		ray->ry=ray->posy;
		ray->dof = hero->width;
	}      //looking up or down. no hit 
}

void	horizontal2(t_tool *hero, t_ray *ray)
{
	int		mx;
	int		my;
	char	c;

	while (ray->dof < hero->height)
	{
		mx=(int)(ray->rx) >> 6;
		my=(int)(ray->ry) >> 6;
		c = get_sym(mx, my, hero);
		// mp=my*mapX+mx;
		// if(mp > 0 && mp<mapX*mapY && map[mp]==1)
		if (c == '1' || c == 'D')
		{
			ray->dof=hero->height;
			hero->dis = ray_dist(ray);
		}//hit
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof += 1;
		}//check next horizontal
	} 
}

void	horizontal(t_tool *hero, t_ray *ray)
{
	ray->dof = 0;
	(void)hero;
	ray->atan_ra = 1.0 / tan(deg_to_rad(ray->ra));
	if (sin(degToRad(ray->ra)) > 0.001)
	{
		ray->ry = (((int)ray->posy >> 6) << 6) - 0.0001;
		ray->rx = (ray->posy - ray->ry) * ray->atan_ra + ray->posx;
		ray->yo = -64;
		ray->xo = 64 * ray->atan_ra;
	}//looking up
	else if (sin(degToRad(ray->ra)) < -0.001)
	{
		ray->ry = (((int)ray->posy >> 6) << 6) + 64;
		ray->rx = (ray->posy - ray->ry) * ray->atan_ra + ray->posx;
		ray->yo = 64;
		ray->xo = -64 * ray->atan_ra;
	}//looking down
	else
	{
		ray->rx = ray->posx;
		ray->ry = ray->posy;
		ray->dof=hero->height;
	}//looking straight left or right
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
		horizontal(hero, ray);
		hero->dis = hero->dis * cos(deg_to_rad
			(fix_angle(hero->pdp.pa - ray->ra)));
		draw_line(hero, i);
		ray->ra = fix_angle(ray->ra - hero->angle);
		++i;
	}
}