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
	// if (!(hero->so || hero->we || hero->no || hero->ea))
	// {
	// 	write(2, "Error! Image file could not found!\n", 35);
	// 	//freearray(map)
	// 	free(hero->mlx);
	// 	exit(1);
	// }
	hero->imgs[1].img = mlx_get_data_addr \
	(hero->no, &hero->imgs[1].bpp, \
	&hero->imgs[1].size_line, &hero->imgs[1].endian);
	hero->imgs[2].img = mlx_get_data_addr \
	(hero->so, &hero->imgs[2].bpp, \
	&hero->imgs[2].size_line, &hero->imgs[2].endian);
	hero->imgs[3].img = mlx_get_data_addr \
	(hero->ea, &hero->imgs[3].bpp, \
	&hero->imgs[3].size_line, &hero->imgs[3].endian);
	hero->imgs[4].img = mlx_get_data_addr \
	(hero->we, &hero->imgs[4].bpp, \
	&hero->imgs[4].size_line, &hero->imgs[4].endian);

	// hero->add[1] = mlx_get_data_addr(hero->no, &hero->bits_per_pixel[1],
	// 		&hero->line_length[1], &hero->endian[1]);
	// hero->add[2] = mlx_get_data_addr(hero->so, &hero->bits_per_pixel[1],
	// 		&hero->line_length[2], &hero->endian[2]);
	// hero->add[3] = mlx_get_data_addr(hero->we, &hero->bits_per_pixel[1],
	// 		&hero->line_length[3], &hero->endian[3]);
	// hero->add[4] = mlx_get_data_addr(hero->ea, &hero->bits_per_pixel[1],
	// 		&hero->line_length[4], &hero->endian[4]);
}

int	create_trgb(int r, int g, int b)
{
	int	t;

	t = 0;
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

void	xpm_to_image(t_tool *hero)
{
	int		i;

	i = 64;
	hero->mlx = mlx_init();
	hero->mlx_win = mlx_new_window(hero->mlx, WIDTH, HEIGHT, "Cub3D");
	hero->so = mlx_xpm_file_to_image(hero->mlx, hero->coordin.so, &i, &i);
	hero->no = mlx_xpm_file_to_image(hero->mlx, hero->coordin.no, &i, &i);
	hero->we = mlx_xpm_file_to_image(hero->mlx, hero->coordin.we, &i, &i);
	hero->ea = mlx_xpm_file_to_image(hero->mlx, hero->coordin.ea, &i, &i);
	hero->f = create_trgb(hero->ceiling.r, hero->ceiling.g, hero->ceiling.b);
	hero->f = create_trgb(hero->floor.r, hero->floor.g, hero->floor.b);
	if (hero->mlx == NULL || hero->mlx_win == NULL)
		exit_game(hero);
	if (hero->no == NULL || hero->so == NULL)
		exit_game(hero);
	if (hero->we == NULL || hero->ea == NULL)
		exit_game(hero);
}