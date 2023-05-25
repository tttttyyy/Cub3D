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
}

int	create_trgb(int r, int g, int b)
{
	int	t;

	t = 0;
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

void	xpm_to_image(t_tool *hero)
{
	hero->mlx = mlx_init();
	hero->mlx_win = mlx_new_window(hero->mlx, WIDTH, HEIGHT, "Cub3D");
	hero->so = mlx_xpm_file_to_image(hero->mlx, hero->coordin.so,
			&hero->imgs[1].width, &hero->imgs[1].height);
	hero->no = mlx_xpm_file_to_image(hero->mlx, hero->coordin.no,
			&hero->imgs[2].width, &hero->imgs[2].height);
	hero->we = mlx_xpm_file_to_image(hero->mlx, hero->coordin.we,
			&hero->imgs[3].width, &hero->imgs[3].height);
	hero->ea = mlx_xpm_file_to_image(hero->mlx, hero->coordin.ea,
			&hero->imgs[4].width, &hero->imgs[4].height);
	hero->f = create_trgb(hero->ceiling.r, hero->ceiling.g, hero->ceiling.b);
	hero->f = create_trgb(hero->floor.r, hero->floor.g, hero->floor.b);
	if (hero->mlx == NULL || hero->mlx_win == NULL)
		exit_game(hero);
	if (hero->no == NULL || hero->so == NULL)
		exit_game(hero);
	if (hero->we == NULL || hero->ea == NULL)
		exit_game(hero);
}
