/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:48:11 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:48:14 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_map_width(char **info)
{
	int	max;
	int	tmp;
	int	i;

	max = 0;
	tmp = 0;
	i = 5;
	while (info && info[i])
	{
		i++;
		tmp = ft_strlen(info[i]);
		if (tmp > max)
		max = tmp;
	}
	return (max);
}

int	get_map_height(char **info)
{
	int	max;

	max = 6;
	while (info && info[max])
	{
		max++;
	}
	return (max - 6);
}
