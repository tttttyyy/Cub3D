/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:58:24 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:58:25 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	color_block(t_tool *hero, int i, int j, int color)
{
	int	k;
	int	l;

	k = -1;
	while (++k < 20)
	{
		l = -1;
		while (++l < 20)
		{
			mlx_pixel_put(hero->mlx, hero->mlx_win, l + (20 * j),
				 k + (20 * i), color);
		}
	}
}

void	choose(char c, t_tool *hero, int i, int j)
{
	if (c == '1')
		color_block(hero, i, j, 0x0000FF00);
	else if (c == '0')
		color_block(hero, i, j, 0x00000000);
	else if (ft_strchr(HERO, c))
		color_block(hero, i, j, 0x00FF0000);
}

void	draw_map(t_tool *hero)
{
	int	i;
	int	j;

	i = -1;
	while (++i < hero->height)
	{
		j = -1;
		while (++j < hero->width)
			choose(hero->map[i][j], hero, i, j);
	}
}