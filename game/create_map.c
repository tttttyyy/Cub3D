/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:58:18 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:58:19 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_game(t_tool *hero)
{
	mlx_destroy_window(hero->mlx, hero->mlx_win);
	//free_game(hero); menq petqa grenq struct jnjox
	exit(0);
}
