/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:41:29 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:41:31 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_rgb_number(char *str, int i)
{
	int		count;
	char	**array;
	int		tmp;

	array = NULL;
	tmp = 0;
	count = count_com(str, i);
	if (count > 3)
		return (1);
	array = ft_split(str + i, ',');
	if (array[0] && array[1] && array[2])
	{
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
	}
	else
	{
		ft_free_matrix(array);
		return (3);
	}
	ft_free_matrix(array);
	return (0);
}

int	check_rgb_line(char *str, int i)
{
	if (check_rgb_number(str, i))
		return (1);
	return (0);
}

int	check_rgb(char *info)
{
	int	j;

	j = 0;
	while (info && info[j] && !is_space(info[j]))
		j++;
	if (info[j] && info[j] != 'F' && info[j] != 'C')
		return (3);
	j++;
	while (info[j] && !is_space(info[j]))
		j++;
	if (info[j] && check_rgb_line(info, j))
		return (4);
	while (info[j] && !is_space(info[j]))
		j++;
	return (0);
}

int	check_texture_line(char *info)
{
	int	j;

	j = 0;
	while (info && info[j])
	{
		while (info[j] && !is_space(info[j]))
			j++;
		if (is_corr_texture(info, j))
			return (2);
		j += 2;
		while (info[j] && !is_space(info[j]))
			j++;
		while (info[j] && is_space(info[j]))
			j++;
		if (!info[j] || info[j] == '\n')
			return (0);
		else
			return (2);
	}
	return (0);
}

void	check_info(char **info)
{
	int	i;
	int	f_rgb;
	int	f_path;
	int	c_rgb;
	int	c_path;

	i = 0;
	c_path = 0;
	c_rgb = 0;
	check_count(info);
	while (info && info[i] && i < 5)
	{
		f_path = check_texture_line(info[i]);
		f_rgb = check_rgb(info[i]);
		if (f_path != 0 && f_rgb != 0)
			exit_false_text_param();
		else if (f_path == 0)
			c_path++;
		else if (f_rgb == 0)
			c_rgb++;
		i++;
	}
	if (c_path != 4 && c_rgb != 2)
		exit_false_text_param();
}
