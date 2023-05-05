/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:58:39 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:58:40 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_tool *hero, double rotate)
{
	double	old_pos;

	old_pos = hero->pdp.dirx;
	hero->pdp.dirx = old_pos * cos(rotate) - \
	hero->pdp.diry * sin(rotate);
	hero->pdp.diry = old_pos * sin(rotate) + \
	hero->pdp.diry * cos(rotate);
	old_pos = hero->pdp.planex;
	hero->pdp.planex = old_pos * cos(rotate) - \
	hero->pdp.planey * sin(rotate);
	hero->pdp.planey = old_pos * sin(rotate) + \
	hero->pdp.planey * cos(rotate);
}

void	move_a(t_tool *hero)
{
	int	x;
	int	y;

	x = (int)(hero->pdp.posx - hero->pdp.planex * \
	(MOVE_SPEED + 0.1));
	y = (int)hero->pdp.posy;
	if (hero->map[x][y] == '0')
		hero->pdp.posx -= hero->pdp.planex * MOVE_SPEED;
	x = (int)hero->pdp.posx;
	y = (int)(hero->pdp.posy - hero->pdp.planey * \
	(MOVE_SPEED + 0.1));
	if (hero->map[x][y] == '0')
		hero->pdp.posy -= hero->pdp.planey * MOVE_SPEED;
}

void	move_d(t_tool *hero)
{
	int	x;
	int	y;

	x = (int)(hero->pdp.posx + hero->pdp.planex * \
	(MOVE_SPEED + 0.1));
	y = (int)hero->pdp.posy;
	if (hero->map[x][y] == '0')
		hero->pdp.posx += hero->pdp.planex * MOVE_SPEED;
	x = (int)hero->pdp.posx;
	y = (int)(hero->pdp.posy + hero->pdp.planey * \
	(MOVE_SPEED + 0.1));
	if (hero->map[x][y] == '0')
		hero->pdp.posy += hero->pdp.planey * MOVE_SPEED;
}

void	move_s(t_tool *hero)
{
	int	x;
	int	y;

	x = (int)(hero->pdp.posx - \
	hero->pdp.dirx * (MOVE_SPEED + 0.1));
	y = (int)hero->pdp.posy;
	if (hero->map[x][y] == '0')
		hero->pdp.posx -= hero->pdp.dirx * MOVE_SPEED;
	x = (int)hero->pdp.posx;
	y = (int)(hero->pdp.posy - \
	hero->pdp.diry * (MOVE_SPEED + 0.1));
	if (hero->map[x][y] == '0')
		hero->pdp.posy -= hero->pdp.diry * MOVE_SPEED;
}

void	move_w(t_tool *hero)
{
	int	x;
	int	y;

	x = (int)(hero->pdp.posx + \
	hero->pdp.dirx * (MOVE_SPEED + 0.1));
	y = (int)hero->pdp.posy;
	if (hero->map[x][y] == '0')
		hero->pdp.posx += hero->pdp.dirx * MOVE_SPEED;
	x = (int)hero->pdp.posx;
	y = (int)(hero->pdp.posy + \
	hero->pdp.diry * (MOVE_SPEED + 0.1));
	if (hero->map[x][y] == '0')
		hero->pdp.posy += hero->pdp.diry * MOVE_SPEED;
}

// void	move_a(t_tool *hero)
// {
// 	hero->pdp.pa -= 0.1;
// 	if (hero->pdp.pa < 0)
// 		hero->pdp.pa += 2 * PI;
// 	hero->pdp.dirx = cos(hero->pdp.pa) * 5;
// 	hero->pdp.diry = sin(hero->pdp.pa) * 5;
// 	if (hero->map[(int)hero->pdp.posy][(int)hero->pdp.posx - 1] != '1')
// 	{
// 		hero->map[(int)hero->pdp.posy][(int)hero->pdp.posx] = '0';
// 		hero->pdp.posx--;
// 		hero->map[(int)hero->pdp.posy][(int)hero->pdp.posx] = 'N';
// 		mlx_clear_window(hero->mlx, hero->mlx_win);
// 		draw_map(hero);
// 	}
// }

// void	move_s(t_tool *hero)
// {
// 	hero->pdp.posx -= hero->pdp.dirx;
// 	hero->pdp.posy -= hero->pdp.diry;
// 	if (hero->map[(int)hero->pdp.posy + 1][(int)hero->pdp.posx] != '1')
// 	{
// 		hero->map[(int)hero->pdp.posy][(int)hero->pdp.posx] = '0';
// 		hero->pdp.posy++;
// 		hero->map[(int)hero->pdp.posy][(int)hero->pdp.posx] = 'N';
// 		mlx_clear_window(hero->mlx, hero->mlx_win);
// 		draw_map(hero);
// 	}
// }

// void	move_d(t_tool *hero)
// {
// 	hero->pdp.pa += 0.1;
// 	if (hero->pdp.pa > 2 * PI)
// 		hero->pdp.pa -= 2 * PI;
// 	hero->pdp.dirx = cos(hero->pdp.pa) * 5;
// 	hero->pdp.diry = sin(hero->pdp.pa) * 5;
// 	if (hero->map[(int)hero->pdp.posy][(int)hero->pdp.posx + 1] != '1')
// 	{
// 		hero->map[(int)hero->pdp.posy][(int)hero->pdp.posx] = '0';
// 		hero->pdp.posx++;
// 		hero->map[(int)hero->pdp.posy][(int)hero->pdp.posx] = 'N';
// 		mlx_clear_window(hero->mlx, hero->mlx_win);
// 		draw_map(hero);
// 	}
// }

	// char sym;

	// hero->mx = hero->pdp.posx + (hero->pdp.dirx * 0.2);
	// hero->my = hero->pdp.posy + (hero->pdp.diry * 0.2);
	// sym = get_sym(hero->mx, hero->my, hero);
	// // sym = write our getmapsymulation
	// if (sym == '0' || sym == 'x')
	// {
	// 	if (sym == 'x')
	// 	{
	// 		put_sym(hero->mx, hero->my, hero, '0');
	// 		// i guess other things were for bonus
	// 		// if you want we can do it
	// 		// write our put map sym
	// 	}
	// 	// then come steps of the player
	// 	hero->pdp.posx += hero->pdp.dirx * 0.1;//why 0.1
	// 	hero->pdp.posy += hero->pdp.diry * 0.1;


	// if (hero->map[(int)hero->pdp.posy - 1][(int)hero->pdp.posx] != '1')
	// {
	// 	hero->map[(int)hero->pdp.posy][(int)hero->pdp.posx] = '0';
	// 	hero->pdp.posy--;
	// 	hero->map[(int)hero->pdp.posy][(int)hero->pdp.posx] = 'N';
	// 	mlx_clear_window(hero->mlx, hero->mlx_win);
	// 	draw_map(hero);
	// }
// }