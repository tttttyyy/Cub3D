/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:58:36 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:58:37 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_xpm(char *xpm)
{
	int		len;
	char	*ber;

	len = ft_strlen(xpm);
	if (len <= 4)
		exit_false_map_form();
	len -= 4;
	ber = ".xpm";
	if (ft_strncmp(xpm + len, ber, len) != 0)
		exit_false_map_form();
}

int	main(int argc, char **argv)
{
	t_tool	hero;

	if (argc != 2)
	{
		write(2, "Must map path as argument\n", 27);
		return (1);
	}
	hero = parser(argv[1]);
	game(&hero);
	return (0);
}
