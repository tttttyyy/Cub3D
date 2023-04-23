/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:56:42 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:56:44 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strdup(char *s1)
{
	char	*dest;

	dest = malloc(gnl_strlen(s1) + 1);
	if (!dest || !s1)
		return (NULL);
	gnl_strcpy(dest, s1);
	return (dest);
}

char	*gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return ((char *)(s + i));
}

char	*gnl_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*ns;
	size_t	i;
	size_t	k;

	i = 0;
	ns = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (!ns)
		return (NULL);
	while (s1[i] != '\0')
	{
		ns[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k] != '\0')
	{
		ns[i] = s2[k];
		k++;
		i++;
	}
	ns[i] = '\0';
	if (s1)
		free(s1);
	return (ns);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	strs;

	if (!*s || !s)
		return (NULL);
	if (start > gnl_strlen(s))
		strs = 0;
	else if (gnl_strlen(s) - start > len)
		strs = len;
	else
		strs = gnl_strlen(s) - start;
	substring = (char *)malloc((strs + 1) * sizeof(char));
	if (!substring)
		return (0);
	if (substring)
		gnl_strlcpy(substring, s + start, strs + 1);
	return (substring);
}
