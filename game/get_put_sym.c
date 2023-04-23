/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_put_sym.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:58:31 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:58:32 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	get_sym(int mx, int my, t_tool *hero)
{
	int	i;
	char **map;
	char *s;//mtacum em kareliya aranc srael

	i = 0;
	if (mx < 0 || my < 0 || mx >= hero->width || my >= hero->height)
		return (' ');
	map = hero->map;
	while (my > 0)
	{
		--my;
		i++;
	}
	s = map[i];
	return (s[mx]);
}

void	put_sym(int mx, int my, t_tool *hero, char c)
{
	int	i;
	char **map;
	char *s;//mtacum em kareliya aranc srael

	i = 0;
	if (mx < 0 || my < 0 )
		return ;
	map = hero->map;
	while (my > 0)
	{
		--my;
		i++;
	}
	s = map[i];
	s[mx] = c;
}