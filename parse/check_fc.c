/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:12:52 by tyenokya          #+#    #+#             */
/*   Updated: 2023/05/19 14:12:54 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_rgb_info(char **info, t_flag *fl)
{
	while (info && info[(*fl).i] && info[(*fl).i][(*fl).j])
	{
		if (info[(*fl).i][(*fl).j] == 'F')
		{
			(*fl).flag0++;
			return ;
		}
		else if (info[(*fl).i][(*fl).j] == 'C')
		{
			(*fl).flag1++;
			return ;
		}
		++(*fl).j;
	}
}

void	check_fc(char **info)
{
	t_flag	fl;

	fl.i = 0;
	fl.j = 0;
	fl.flag0 = 0;
	fl.flag1 = 0;
	while (info && info[fl.i] && fl.i < 6)
	{
		fl.j = 0;
		check_rgb_info(info, &fl);
		++fl.i;
	}
	if (fl.flag0 != 1 || fl.flag1 != 1)
		exit_false_text_param();
}
