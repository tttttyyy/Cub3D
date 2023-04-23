/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:47:31 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:47:33 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	cnt_word(char const *str, char delim)
{
	size_t	prev_del;
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	prev_del = 1;
	while (str[i])
	{
		if (str[i] == delim)
			prev_del = 1;
		else if (prev_del)
			count++;
		if (str[i] != delim)
			prev_del = 0;
		i++;
	}
	return (count);
}

static char	*ml(char const *s, size_t st, size_t len)
{
	char	*tab;
	size_t	i;

	i = 0;
	tab = malloc(len + 1);
	if (!tab)
		return (NULL);
	while (s[st] && i < len)
	{
		tab[i] = s[st];
		st++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static void	*fr(char **s, size_t i)
{
	while (i > 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**tab;
	size_t	start;
	size_t	end;

	start = 0;
	end = 0;
	i = -1;
	tab = malloc(sizeof(char *) * (cnt_word (s, c) + 1));
	if (!(tab) || !s)
		return (0);
	while (++i < cnt_word (s, c))
	{
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		tab[i] = ml(s, start, end - start);
		if (!tab[i])
			fr (tab, i);
		start = end;
	}
	tab[i] = 0;
	return (tab);
}
