/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:11:51 by lgalstya          #+#    #+#             */
/*   Updated: 2023/05/05 16:11:53 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	continue_init_win(t_tool *hero)
{
	if (hero->pdp.raydirx == 0)
		hero->pdp.deltadistx = 1e30;
	else
		hero->pdp.deltadistx = ft_abs(1 / hero->pdp.raydirx);
	if (hero->pdp.raydiry == 0)
		hero->pdp.deltadisty = 1e30;
	else
		hero->pdp.deltadisty = ft_abs(1 / hero->pdp.raydiry);
	if (hero->pdp.raydirx < 0)
	{
		hero->pdp.stepx = -1;
		hero->pdp.sidedistx = (hero->pdp.posx - \
		hero->pdp.mapx) * hero->pdp.deltadistx;
	}
	else
	{
		hero->pdp.stepx = 1;
		hero->pdp.sidedistx = (hero->pdp.mapx + 1.0 - \
		hero->pdp.posx) * hero->pdp.deltadistx;
	}
	norm_init_win(hero);
}

void	init_plane(t_tool *hero, double i, double j)
{
	hero->pdp.planex = i;
	hero->pdp.planey = j;
}

void	init_dir(t_tool *hero, double i, double j)
{
	hero->pdp.dirx = i;
	hero->pdp.diry = j;
}

void	init_player_pos(t_tool *hero, int i, int j)
{
	if (hero->map[i][j] == 'S')
	{
		init_dir(hero, 1, 0);
		init_plane(hero, 0, -0.66);
	}
	else if (hero->map[i][j] == 'N')
	{
		init_dir(hero, -1, 0);
		init_plane(hero, 0, 0.66);
	}
	else if (hero->map[i][j] == 'E')
	{
		init_dir(hero, 0, 1);
		init_plane(hero, 0.66, 0);
	}
	else if (hero->map[i][j] == 'W')
	{
		init_dir(hero, 0, -1);
		init_plane(hero, -0.66, 0);
	}
}

void	find_pos_player(t_tool *hero)
{
	int	i;
	int	j;

	i = 0;
	while (hero->map[i])
	{
		j = 0;
		while (hero->map[i][j])
		{
			if (hero->map[i][j] == 'N' || \
				hero->map[i][j] == 'S' || \
				hero->map[i][j] == 'E' || \
				hero->map[i][j] == 'W')
			{
				init_player_pos(hero, i, j);
				hero->pdp.posx = i + 0.5;
				hero->pdp.posy = j + 0.5;
				hero->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}
