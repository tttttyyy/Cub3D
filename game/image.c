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