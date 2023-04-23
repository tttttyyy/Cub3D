/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:45:23 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:45:28 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_false_text_param(void)
{
	write(2, "Texture parametrs isn't correct\n", 33);
	exit(2);
}

void	exit_false_map(void)
{
	write(2, "Map isn't correct\n", 19);
	exit(2);
}

void	exit_false_map_form(void)
{
	write(2, "Map format isn't correct.\n", 27);
	exit(2);
}
