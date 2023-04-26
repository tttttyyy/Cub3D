/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:58:28 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:58:29 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_player(int key, t_tool *hero)
{
	// hero->pdp.pa = 90;
	// if (key == 0 || key == 123)
	// {
	// 	move_a(hero);
	// }
	// else if (key == 1 || key == 125)
	// {
	// 	move_s(hero);
	// }
	// else if (key == 2 || key == 124)
	// {
	// 	move_d(hero);
	// }
	if (key == 13 || key == 126)
	{
		move_w(hero);
	}
	else if (key == 53)
	{
		exit(0); //exit_game(hero);
	}
	return (0);
}

void	game(t_tool *hero)
{
	// char	*addr;
	// char	dst;
	// int		bits_per_pixel;
	// int		line_length;
	// int		endian;

	// hero.pdp.dirx = -1;
	// hero.pdp.diry = 0;
		// printf("hello/n");
	hero->pdp.planex = 0;
	hero->pdp.planey = 0.66;
	hero->pdp.time = 0;
	hero->pdp.oldtime = 0;
	hero->angle = 60.0 / 1024;
	//map_to_window(hero-> hero->mlx, mlx_win);
	//hero->img = mlx_new_image(hero->mlx, 1024, 512);
	hero->pdp.dirx = cos(hero->pdp.pa);
	hero->pdp.diry = -1 * sin(hero->pdp.pa);
	hero->mlx = mlx_init();
	xpm_to_image(hero);
	hero->mlx_win = mlx_new_window(hero->mlx, 1024, 512, "Cub3D");
	// mlx_pixel_put(hero->mlx, hero->mlx_win, hero->pdp.posx, hero->pdp.posy, 0x00FF0000);
	mlx_hook(hero->mlx_win, 2, 1L << 0, move_player, hero);
	mlx_loop_hook(hero->mlx, start, hero);
	mlx_loop(hero->mlx);
}