/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:58:18 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:58:19 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_game(t_tool *hero)
{
	mlx_destroy_window(hero->mlx, hero->win);
	//free_game(hero); menq petqa grenq truct jnjox
	exit(0);
}

void	create_map(t_tool *hero)
{
	t_ray	ray;
	if (hero->img)
	mlx_destroy_image(hero->mlx, hero->img);
	hero->img = mlx_new_image(game->mlx, 1024, 512);
	if (!hero->img)
	{
		write(2, "Error\nImage couldn't be created!\n", 32);
		exit_game(game);
	}
	game->addr[0] = get_data_addr(hero.img, &hero->imgs.bits_per_pixel[0],
			&hero->line_length[0], &hero->endian[0]);
	mlx_put_image_to_window(hero->mlx, hero->mlx_win, hero->img, 0, 0);
}