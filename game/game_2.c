/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:11:45 by lgalstya          #+#    #+#             */
/*   Updated: 2023/05/05 16:11:47 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_walls(t_tool *hero, char *dest, char *dest_2, int texx)
{
	double	step;
	double	texpos;
	int		texy;
	int		i;
	int		n;

	(void)texy;
	n = check_nwse(hero);
	i = hero->pdp.drawstart;
	texx = (int)ft_texx(hero, n);
	step = 1.0 * hero->imgs[n].width / hero->pdp.lineheight;
	texpos = (hero->pdp.drawstart - HEIGHT / 2 + \
	hero->pdp.lineheight / 2) * step;
	while (i < hero->pdp.drawend)
	{
		texy = (int)texpos & hero->imgs[n].width;
		texpos += step;
		dest = hero->imgs[0].img + (i * hero->imgs[0].size_line + \
		hero->index * (hero->imgs[0].bpp / 8));
		dest_2 = hero->imgs[n].img + ((int)texpos * \
		hero->imgs[n].size_line + texx * (hero->imgs[n].bpp / 8));
		*(int *)dest = *(int *)dest_2;
		i++;
	}
	return (0);
}

void	draw_floor_and_celling(t_tool *hero, char *dest)
{
	int	i;

	i = -1;
	while (++i < HEIGHT / 2)
	{
			dest = hero->imgs[0].img + (i * hero->imgs[0].size_line + \
			hero->index * hero->imgs[0].bpp / 8);
			*(int *)dest = hero->c;
	}
	while (++i < HEIGHT)
	{
			dest = hero->imgs[0].img + (i * hero->imgs[0].size_line + \
			hero->index * hero->imgs[0].bpp / 8);
			*(int *)dest = hero->f;
	}
}

void	norm_init_win_3(t_tool *hero)
{
	if (hero->pdp.side == 0)
		hero->pdp.perpwalldist = (hero->pdp.sidedistx - \
		hero->pdp.deltadistx);
	else
		hero->pdp.perpwalldist = (hero->pdp.sidedisty - \
		hero->pdp.deltadisty);
	hero->pdp.lineheight = (int)(HEIGHT / \
	hero->pdp.perpwalldist);
	hero->pdp.drawstart = -hero->pdp.lineheight / \
	2 + HEIGHT / 2;
	if (hero->pdp.drawstart < 0)
		hero->pdp.drawstart = 0;
	hero->pdp.drawend = hero->pdp.lineheight / 2 + HEIGHT / 2;
	if (hero->pdp.drawend >= HEIGHT)
		hero->pdp.drawend = HEIGHT - 1;
	draw_floor_and_celling(hero, 0);
	draw_walls(hero, 0, 0, 0);
}

void	norm_init_win_2(t_tool *hero)
{
	hero->pdp.hit = 0;
	while (hero->pdp.hit == 0)
	{
		if (hero->pdp.sidedistx < hero->pdp.sidedisty)
		{
			hero->pdp.sidedistx += hero->pdp.deltadistx;
			hero->pdp.mapx += hero->pdp.stepx;
			hero->pdp.side = 0;
		}
		else
		{
			hero->pdp.sidedisty += hero->pdp.deltadisty;
			hero->pdp.mapy += hero->pdp.stepy;
			hero->pdp.side = 1;
		}
		if (hero->map[hero->pdp.mapx] \
		[hero->pdp.mapy] != '0')
			hero->pdp.hit = 1;
	}
	norm_init_win_3(hero);
}

void	norm_init_win(t_tool *hero)
{
	if (hero->pdp.raydiry < 0)
	{
		hero->pdp.stepy = -1;
		hero->pdp.sidedisty = (hero->pdp.posy - \
		hero->pdp.mapy) * hero->pdp.deltadisty;
	}
	else
	{
		hero->pdp.stepy = 1;
		hero->pdp.sidedisty = (hero->pdp.mapy + 1.0 - \
		hero->pdp.posy) * hero->pdp.deltadisty;
	}
	norm_init_win_2(hero);
}
