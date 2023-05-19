/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:43:51 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:43:55 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_path(char *path)
{
	int		len;
	char	*ber;

	len = ft_strlen(path);
	if (len <= 4)
		exit_false_map_form();
	len -= 4;
	ber = ".cub";
	if (ft_strncmp(path + len, ber, len) != 0)
		exit_false_map_form();
}

int	check_around(char **info, int i, int j, int h)
{
	if (i == 0 || i == h)
		return (1);
	else if (j == 0)
		return (2);
	if (!info[i][j - 1] || (info[i][j + 1] && !info[i][j + 1])
		|| !info[i - 1][j] || (info[i + 1] && !info[i + 1][j]))
		return (1);
	if (!ft_strrchr(CHARS, info[i][j - 1])
		|| !ft_strrchr(CHARS, info[i][j + 1]))
	{
		return (2);
	}
	if (!ft_strrchr(CHARS, info[i - 1][j])
		|| !ft_strrchr(CHARS, info[i + 1][j]))
		return (3);
	return (0);
}

void	check_map(char **info)
{
	int	i;
	int	j;
	int	count;

	i = 5;
	count = 0;
	while (info && info[i])
	{
		++i;
		j = 0;
		while (info[i] && info[i][j])
		{
			if (info[i][j] && (info[i][j] == '\t'
				|| (!ft_strrchr(CHARS, info[i][j]) && info[i][j] != ' ')))
				exit_false_map();
			if (info[i][j] && ft_strrchr(HERO, info[i][j]))
				++count;
			if ((info[i][j] == '0' || ft_strchr(HERO, info[i][j])) &&
				check_around(info, i, j, get_map_height(info) + 5) != 0)
				exit_false_map();
			++j;
		}
	}
	if (count != 1)
		exit_false_map();
}
