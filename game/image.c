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
	if (!(hero->so || hero->we || hero->no || hero->ea))
	{
		write(2, "Error! Image file could not found!\n", 35);
		//freearray(map)
		free(hero->mlx);
		exit(1);
	}
	hero->add[1] = mlx_get_data_addr(hero->no, &hero->bits_per_pixel[1],
			&hero->line_length[1], &hero->endian[1]);
	hero->add[2] = mlx_get_data_addr(hero->so, &hero->bits_per_pixel[1],
			&hero->line_length[2], &hero->endian[2]);
	hero->add[3] = mlx_get_data_addr(hero->we, &hero->bits_per_pixel[1],
			&hero->line_length[3], &hero->endian[3]);
	hero->add[4] = mlx_get_data_addr(hero->ea, &hero->bits_per_pixel[1],
			&hero->line_length[4], &hero->endian[4]);
}

void	xpm_to_image(t_tool *hero)
{
	int		i;
	// char	*tmp;

	i = 50;
	// tmp = hero->so;
	hero->so = mlx_xpm_file_to_image(hero->mlx, hero->coordin.so, &i, &i);
	// free(tmp);
	// tmp = hero->no;
	hero->no = mlx_xpm_file_to_image(hero->mlx, hero->coordin.no, &i, &i);
	// free(tmp);
	// tmp = hero->we;
	hero->we = mlx_xpm_file_to_image(hero->mlx, hero->coordin.we, &i, &i);
	// free(tmp);
	// tmp = hero->ea;
	hero->ea = mlx_xpm_file_to_image(hero->mlx, hero->coordin.ea, &i, &i);
	// free(tmp);
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