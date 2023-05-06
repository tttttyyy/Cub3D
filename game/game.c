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

void	init_win(t_tool *hero)
{
	int	i;

	i = 0;
	find_pos_player(hero);
	hero->imgs[0].ptr = mlx_new_image(hero->mlx, WIDTH, HEIGHT);
	hero->imgs[0].img = mlx_get_data_addr(hero->imgs[0].ptr, \
	&hero->imgs[0].bpp, &hero->imgs[0].size_line, &hero->imgs[0].endian);
	get_addr(hero);
	while (i < WIDTH)
	{
		hero->index = i;
		hero->pdp.camerax = 2 * i / (double)WIDTH - 1;
		hero->pdp.raydirx = hero->pdp.dirx + \
		hero->pdp.planex * hero->pdp.camerax;
		hero->pdp.raydiry = hero->pdp.diry + \
		hero->pdp.planey * hero->pdp.camerax;
		hero->pdp.mapx = (int)hero->pdp.posx;
		hero->pdp.mapy = (int)hero->pdp.posy;
		continue_init_win(hero);
		i++;
	}
	mlx_put_image_to_window(hero->mlx, hero->mlx_win, \
	hero->imgs[0].ptr, 0, 0);
}

void	game(t_tool *hero)
{
	init_structs(hero);
	xpm_to_image(hero);
	init_win(hero);
	mlx_hook(hero->mlx_win, 17, 1L << 0, exit_game, hero);
	mlx_hook(hero->mlx_win, 2, 1L << 0, move_player, hero);
	mlx_loop(hero->mlx);
}
