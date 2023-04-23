/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:41:58 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:42:01 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_space(char c)
{
	if (c == ' ')
		return (0);
	return (1);
}

int	is_corr_texture(char *s, int i)
{
	if (s && s[i] && s[i] == 'N' && s[i + 1]
		&& s[i + 1] == 'O' && s[i + 2] && !is_space(s[i + 2]))
		return (0);
	else if (s && s[i] && s[i] == 'S' && s[i + 1]
		&& s[i + 1] == 'O' && s[i + 2] && !is_space(s[i + 2]))
		return (0);
	else if (s && s[i] && s[i] == 'W' && s[i + 1]
		&& s[i + 1] == 'E' && s[i + 2] && !is_space(s[i + 2]))
		return (0);
	else if (s && s[i] && s[i] == 'E' && s[i + 1]
		&& s[i + 1] == 'A' && s[i + 2] && !is_space(s[i + 2]))
		return (0);
	return (2);
}

static int	check_line(char **info, char a, char b, t_flag fl)
{
	int	i;
	int	j;

	i = fl.i;
	j = fl.j;
	if (info[i][j] == a && info[i][j + 1]
		&& info[i][j + 1] == b)
		return (0);
	return (1);
}

static void	check_lines_info(char **info, t_flag *fl)
{
	while (info && info[(*fl).i] && info[(*fl).i][(*fl).j])
	{
		if (!check_line(info, 'N', 'O', (*fl)))
		{
			(*fl).flag0++;
			return ;
		}
		else if (!check_line(info, 'S', 'O', (*fl)))
		{
			(*fl).flag1++;
			return ;
		}
		else if (!check_line(info, 'E', 'A', (*fl)))
		{
			(*fl).flag2++;
			return ;
		}
		else if (!check_line(info, 'W', 'E', (*fl)))
		{
			(*fl).flag3++;
			return ;
		}
		++(*fl).j;
	}
}

void	check_count(char **info)
{
	t_flag	fl;

	fl.i = 0;
	fl.j = 0;
	fl.flag0 = 0;
	fl.flag1 = 0;
	fl.flag2 = 0;
	fl.flag3 = 0;
	while (info && info[fl.i] && fl.i < 6)
	{
		check_lines_info(info, &fl);
		++fl.i;
	}
	if (fl.flag0 != 1 || fl.flag1 != 1 || fl.flag2 != 1 || fl.flag3 != 1)
		exit_false_text_param();
}
