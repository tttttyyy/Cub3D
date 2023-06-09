/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:57:17 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:57:18 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	whites(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		if (is_space(s[i++]))
			break ;
	if (!s[i])
		return (1);
	return (0);
}

int	ft_check_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error ");
		exit(3);
	}
	return (fd);
}

void	map(char *curr, char **str, char *tmp)
{
	if (whites(curr))
		exit_false_map();
	*str = ft_strjoin(tmp, curr);
}

char	**read_file(char *path)
{
	char	*curr;
	char	*tmp;
	char	*str;
	char	**matr;
	int		fd[2];

	fd[1] = 0;
	str = ft_strdup("");
	fd[0] = ft_check_file(path);
	curr = get_next_line(fd[0]);
	while (curr)
	{
		tmp = str;
		if (!whites(curr) && ++fd[1] <= 6)
			str = ft_strjoin(tmp, curr);
		else if (fd[1] > 6)
			map(curr, &str, tmp);
		free(curr);
		curr = get_next_line(fd[0]);
	}
	matr = ft_split(str, '\n');
	free(str);
	free(curr);
	return (matr);
}
