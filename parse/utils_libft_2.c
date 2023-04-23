/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:57:37 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:57:44 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strchr(char *s, int c)
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

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

static int	ft_strlcpy(char *dst, char *src, int l)
{
	int	i;

	i = 0;
	if ((! dst && src) || l == 0)
		return (ft_strlen (src));
	if (!dst && !src)
		return (0);
	while (i < l - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_substr(char *s, int start, int len)
{
	char	*s2;
	int		count;
	int		end;

	end = 0;
	count = ft_strlen(s);
	if (!s)
		return (0);
	if (start < count)
		end = count - start;
	if (end > len)
		end = len;
	s2 = (char *)malloc(sizeof(char) * (end + 1));
	if (!s2)
		return (0);
	ft_strlcpy(s2, s + start, end + 1);
	return (s2);
}

int	ft_atoi(char *str)
{
	int	c;
	int	min;
	int	n;

	c = 0;
	min = 1;
	n = 0;
	if (!str)
		return (0);
	while ((str[c] >= '\t' && str[c] <= '\r') || str[c] == ' ')
		c++;
	if (str[c] == '-')
		min = -1;
	if (str[c] == '+' || str[c] == '-')
		c++;
	while (str[c] >= '0' && str[c] <= '9')
	{
		n = (str[c] - '0') + (n * 10);
		c++;
	}
	return (n * min);
}
