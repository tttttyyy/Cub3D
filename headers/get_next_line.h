/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:40:24 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:40:40 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*gnl_strchr(char *s, int c);
char	*gnl_strcpy(char *dst, char *src);
char	*gnl_strdup(char *s1);
char	*gnl_strjoin(char *s1, char *s2);
size_t	gnl_strlen(char *s);
char	*gnl_substr(char *s, unsigned int start, size_t len);
char	*gnl_strlcpy(char *dst, char *src, size_t dstsize);

#endif
