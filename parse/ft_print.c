/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:47:13 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:47:22 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	printf_matrix(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void	print_hero(t_tool hero)
{
	printf("hero.coordin.we = |%s|\n", hero.coordin.we);
	printf("hero.coordin.so = |%s|\n", hero.coordin.so);
	printf("hero.coordin.no = |%s|\n", hero.coordin.no);
	printf("hero.coordin.ea = |%s|\n", hero.coordin.ea);
	printf("hero.height = |%d|\n", hero.height);
	printf("hero.width = |%d|\n", hero.width);
	printf("hero.floor.r = |%d|\n", hero.floor.r);
	printf("hero.floor.g = |%d|\n", hero.floor.g);
	printf("hero.floor.b = |%d|\n", hero.floor.b);
	printf("hero.ceiling.r = |%d|\n", hero.ceiling.r);
	printf("hero.ceiling.g = |%d|\n", hero.ceiling.g);
	printf("hero.ceiling.b = |%d|\n", hero.ceiling.b);
	printf("hero.player = |%c|\n", hero.player);
	printf("hero.map is\n");
	printf_matrix(hero.map);
}
