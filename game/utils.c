/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:58:46 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:58:47 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	deg_to_rad(double degr)
{
	return (degr * PI / 180.0);
}

void	my_mlx_pixel_put(t_tool *hero, int x, int y, int clr)
{
	char	*dst;

	dst = hero->add[1] + ((y * hero->line_length[0]) + x
			* (hero->bits_per_pixel[0] / 8));
	*(unsigned int *)dst = clr;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	put_texture_pixel(t_tool *hero, int x, int y, int k)
{
	char	*dst;
	int		i;
	int		j;

	if (hero->linelen == 0)
		return ;
	i = hero->ray;
	k = k + hero->stepy;
	j = (k << 6) / hero->linelen;
	dst = hero->add[hero->zeros] + ((j * hero->line_length[hero->zeros])
			+ i * (hero->bits_per_pixel[hero->zeros] / 8));
	my_mlx_pixel_put(hero, x, y, *(unsigned int *)dst);
}

void	draw_line_2(t_tool *hero, int i, int lineh, int lineoff)
{
	int	k;
	int	y;

	k = -1;
	y = 0;
	while (y < 1000)
	{
		if (y < lineoff)
			my_mlx_pixel_put(hero, i, y,
				create_trgb(0, hero->ceiling.r, hero->ceiling.g, hero->ceiling.b));
		else if (y > lineh + lineoff)
			my_mlx_pixel_put(hero, i, y,
				create_trgb(0, hero->floor.r, hero->floor.g, hero->floor.b));
		else
			put_texture_pixel(hero, i, y, k++);
		y++;
	}
}

void	draw_line(t_tool *hero, int i)
{
	int	lineh;
	int	lineoff;

	lineh = (1000 << 5) / hero->dis;
	hero->stepy = 0;
	hero->linelen = lineh;
	if (lineh > 1000)
	{
		hero->stepy = ((lineh - 1000) >> 1);
		lineh = 1000;
	}
	lineoff = (1000 - lineh) >> 1;
	draw_line_2(hero, i, lineh, lineoff);
}
