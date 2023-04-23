/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:57:29 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:57:30 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != 0)
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && n > 0)
	{
		if (s1[i] != s2[i])
		{
			return ((size_t)((unsigned char)s1[i] - (unsigned char)s2[i]));
		}
		if (s1[i] == '\0')
			return ((-1) * s2[i]);
		i++;
		n--;
	}
	return (0);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*tox;

	i = 0;
	if (!src)
		return (0);
	tox = (char *)malloc(ft_strlen(src) + 1);
	if (!tox)
		return (0);
	while (src[i])
	{
		tox[i] = src[i];
		i++;
	}
	tox[i] = 0;
	return (tox);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc (ft_strlen (s1) + ft_strlen (s2) + 10);
	if (!str)
		return (0);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	if (s1)
		free(s1);
	return (str);
}
