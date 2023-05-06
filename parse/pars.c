/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:57:10 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:57:11 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	def_angle(t_tool *hero)
{
	if (hero->player == 'E')
		hero->pdp.pa = 0;
	else if (hero-> player == 'N')
		hero->pdp.pa = 90;
	else if (hero-> player == 'W')
		hero->pdp.pa = 180;
	else if (hero-> player == 'S')
		hero->pdp.pa = 270;
}

t_tool	parser(char *path)
{
	char	**info;
	t_tool	hero;

	check_path(path);
	info = read_file(path);
	hero.map = info;
	check_info(info);
	check_map(info);
	hero = init_hero(info);
	def_angle(&hero);
	ft_free_matrix(info);
	return (hero);
}
