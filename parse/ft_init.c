/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:46:58 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:47:02 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ignor_space(char *info, int	*i)
{
	while (info[*i] && !is_space(info[*i]))
		(*i)++;
}

char	*get_texture(char *info)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	ignor_space(info, &i);
	while (info[i] && is_space(info[i]))
		i++;
	ignor_space(info, &i);
	res = ft_substr(info, i, ft_strlen(info) - i);
	return (res);
}

static char	*ft_fill_line(char **info, int i, int w)
{
	char	*map;
	int		len;
	int		j;

	j = 0;
	len = ft_strlen(info[i]);
	map = malloc(sizeof(char) * (w + 1));
	while (info && j < w)
	{
		if (j > len || !is_space(info[i][j]) || info[i][j] == '\0')
			map[j] = 'x';
		else
			map[j] = info[i][j];
		++j;
	}
	map[j] = '\0';
	return (map);
}

static char	**init_map(char **info, int w, int h)
{
	int		i;
	int		k;
	char	**map;

	i = 6;
	k = 0;
	map = malloc(sizeof(char *) * (h + 1));
	while (info && info[i])
	{
		map[k] = ft_fill_line(info, i, w);
		++i;
		++k;
	}
	map[k] = NULL;
	return (map);
}

// void	init_plane(t_tool *hero, double i, double j)
// {
// 	hero->pdp.planex = i;
// 	hero->pdp.planey = j;
// }

// void	init_dir(t_tool *hero, double i, double j)
// {
// 	hero->pdp.dirx = i;
// 	hero->pdp.diry = j;
// }

// void	init_player_pos(t_tool *hero, int i, int j)
// {
// 	if (hero->map[i][j] == 'S')
// 	{
// 		init_dir(hero, 1, 0);
// 		init_plane(hero, 0, -0.66);
// 	}
// 	else if (hero->map[i][j] == 'N')
// 	{
// 		init_dir(hero, -1, 0);
// 		init_plane(hero, 0, 0.66);
// 	}
// 	else if (hero->map[i][j] == 'E')
// 	{
// 		init_dir(hero, 0, 1);
// 		init_plane(hero, 0.66, 0);
// 	}
// 	else if (hero->map[i][j] == 'W')
// 	{
// 		init_dir(hero, 0, -1);
// 		init_plane(hero, -0.66, 0);
// 	}
// }

char	get_pos(char **info, t_tool *lol)
{
	int		i;
	int		j;

	i = 6;
	(void) info;
	while (lol->map && lol->map[i])
	{
		j = 0;
		while (lol->map[i][j])
		{
			if (ft_strchr(HERO, lol->map[i][j]))
			{
				// init_player_pos(lol, i, j);
				// lol->pdp.posx = j + 0.5;
				// lol->pdp.posy = i - 6 + 0.5;
				// lol->map[i][j] = '0';
				return (lol->map[i][j]);
			}
			++j;
		}
		++i;
	}
	return (0);
}

t_tool	init_hero(char **info)
{
	t_tool	hero;
	
	hero.height = get_map_height(info);
	hero.width = get_map_width(info);
	hero.coordin = init_coordin(info);
	hero.ceiling = init_colors(info, 'C');
	hero.floor = init_colors(info, 'F');

	hero.map = init_map(info, hero.width, hero.height);
	hero.player = get_pos(info, &hero);
	return (hero);
}
