/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:11:40 by lgalstya          #+#    #+#             */
/*   Updated: 2023/05/05 16:11:41 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_player(int key, t_tool *hero)
{
	if (key == 0)
		move_a(hero);
	else if (key == 1)
		move_s(hero);
	else if (key == 2)
		move_d(hero);
	else if (key == 13)
		move_w(hero);
	else if (key == 53)
		exit(0);
	if (key == 124)
		rotate_right(hero, -ROTATE_SPEED);
	if (key == 123)
		rotate_right(hero, ROTATE_SPEED);
	init_win(hero);
	return (0);
}

float	ft_abs(float num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	check_nwse(t_tool *hero)
{
	int	n;

	n = 1;
	if (hero->pdp.side == 1 && hero->pdp.raydiry < 0)
		n = 3;
	else if (hero->pdp.side == 1 && hero->pdp.raydiry > 0)
		n = 4;
	else if (hero->pdp.side == 0 && hero->pdp.raydirx > 0)
		n = 2;
	else if (hero->pdp.side == 0 && hero->pdp.raydirx < 0)
		n = 1;
	return (n);
}

int	ft_texx(t_tool *hero, int n)
{
	int		texx;
	double	wallx;

	wallx = 0.0;
	if (hero->pdp.side == 0)
		wallx = hero->pdp.posy + hero->pdp.perpwalldist \
		* hero->pdp.raydiry;
	else
		wallx = hero->pdp.posx + hero->pdp.perpwalldist \
		* hero->pdp.raydirx;
	wallx -= floor(wallx);
	texx = (int)(wallx * (double)hero->imgs[n].width);
	if (hero->pdp.side == 0 && hero->pdp.raydirx > 0)
		texx = hero->imgs[n].width - texx - 1;
	if (hero->pdp.side == 1 && hero->pdp.raydiry < 0)
		texx = hero->imgs[n].width - texx - 1;
	return (texx);
}
