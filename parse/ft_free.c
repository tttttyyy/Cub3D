/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:46:11 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:46:14 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_matrix(char **matr)
{
	int	i;

	i = 0;
	if (!matr)
		return ;
	while (matr[i])
	{
		if (matr[i])
		{
			free(matr[i]);
			matr[i] = 0;
		}
		i++;
	}
	free(matr);
	matr = 0;
}
