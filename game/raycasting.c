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

void	raycasting(t_tool *hero, t_ray *ray)
{
	int	i;
	
	i = 0;
	ray->ra = fix_angle(hero->pa + 30);
	ray->posx = hero->posx * 64;
	ray->posy = hero->posy * 64;
	while (i < 1024)
	{
		hero->dis = 1000000;
		for (r=0;r<60;r++)
 		{
			//---Vertical--- 
			dof=0;
			ray->tan_ra = tan(degToRad(ray->ra));
			if (cos(degToRad(ray->ra))> 0.001)
			{
				ray->rx = (((int)ray->px >> 6) << 6) + 64;
				ray->ry = (ray->px - ray->rx) * ray->tan_ra + ray->py;
				ray->xo = 64;
				ray->yo = -64 * ray->tan_ra;
			}//looking left
			else if (cos(degToRad(ray->ra))<-0.001)
			{
				ray->rx = (((int)ray->px >> 6) << 6) -0.0001;
				ray->ry = (ray->px - ray->rx) * ray->tan_ra + ray->py;
				ray->xo = -64;
				ray->yo = 64 * Tan;
			}//looking right
			else // not clear from here
			{
				ray->rx=ray->px;
				ray->ry=ray->py;
				dof=8;
			}      //looking up or down. no hit  

			while(dof<8) 
			{ 
				mx=(int)(rx)>>6;
				my=(int)(ry)>>6;
				mp=my*mapX+mx;                     
				if (mp>0 && mp<mapX*mapY && map[mp]==1)
				{
					dof=8;
					disV=cos(degToRad(ra))*(rx-px)-sin(degToRad(ra))*(ry-py);
				}//hit         
				else
				{
					rx+=xo;
					ry+=yo;
					dof+=1;
				} //check next horizontal
			} 
			vx=rx; vy=ry;
		//write for vertical and horizontal
		//hero->dist = hero->dist * cos()
		}	
}