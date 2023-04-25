/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:58:34 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:58:35 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_addr(t_tool *hero)
{
	if (!hero->img.so || !hero->img.we || !hero->img.no || !hero->img.ea)
	{
		write(2, "Error! Image file could not found!\n", 35);
		//freearray(map)
		free(hero->mlx);
		exit(1);
	}
	hero->img.addr[1] = mlx_get_data_addr(hero->img.no, &hero->img.bits_per_pixel[1],
			&hero->img.line_length[1], &hero->img.endian[1]);
	hero->img.addr[2] = mlx_get_data_addr(hero->img.so, &hero->img.bits_per_pixel[1],
			&hero->img.line_length[2], &hero->img.endian[2]);
	hero->img.addr[3] = mlx_get_data_addr(hero->img.we, &hero->img.bits_per_pixel[1],
			&hero->img.line_length[3], &hero->img.endian[3]);
	hero->img.addr[4] = mlx_get_data_addr(hero->img.ea, &hero->img.bits_per_pixel[1],
			&hero->img.line_length[4], &hero->img.endian[4]);
}

void	xpm_to_image(t_tool *hero)
{
	int		i;
	char	*tmp;

	i = 50;
	tmp = hero->img.so;
	hero->img.so = mlx_xpm_file_to_image(hero->mlx, hero->img.so, &i, &i);
	free(tmp);
	tmp = hero->img.no;
	hero->img.no = mlx_xpm_file_to_image(hero->mlx, hero->img.no, &i, &i);
	free(tmp);
	tmp = hero->img.we;
	hero->img.we = mlx_xpm_file_to_image(hero->mlx, hero->img.we, &i, &i);
	free(tmp);
	tmp = hero->img.ea;
	hero->img.ea = mlx_xpm_file_to_image(hero->mlx, hero->img.ea, &i, &i);
	free(tmp);
	get_addr(hero);
}

// void	hero_to_window(t_tool hero, void *mlx, void *mlx_win)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (x < 50 && ++x)
// 	{
// 		hero.pdp.camerax = 2 * x / double()
// 	}
// }