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

void	ignor_space(char *info, int	*i)
{
	while (info[*i] && !is_space(info[*i]))
		(*i)++;
}

int	ft_cmp(char **array)
{
	int		tmp;

	tmp = 0;
	tmp = ft_atoi(array[0]);
	if (tmp < 0 || tmp > 255)
	{
		ft_free_matrix(array);
		return (3);
	}
	tmp = ft_atoi(array[1]);
	if (tmp < 0 || tmp > 255)
	{
		ft_free_matrix(array);
		return (2);
	}
	tmp = ft_atoi(array[2]);
	if (tmp < 0 || tmp > 255)
	{
		ft_free_matrix(array);
		return (1);
	}
	return (0);
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
	ft_free_matrix(info);
	return (hero);
}
