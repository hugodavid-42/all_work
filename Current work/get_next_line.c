/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:47:49 by hdavid            #+#    #+#             */
/*   Updated: 2025/11/20 19:47:08 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char **stash)
{
	char	*newline;
	char	*line;
	size_t	len;
	size_t	rest_len;
	size_t	i;

	if (!*stash || **stash == '\0')
		return (NULL);

	newline = ft_strchr_spc(*stash, '\n');
	len = newline ? (newline - *stash + 1) : ft_strlen(*stash);
	line = malloc(sizeof(char) * len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while(i < len)
	{
		line[i] = (*stash)[i];
		i ++;
	}
	line[len] = '\0';

	rest_len = ft_strlen(*stash + len);
	char *rest = rest_len ? ft_strdup(*stash + len) : NULL;
	free(*stash);
	*stash = rest;
	return (line);
}

char	*find_next(char *stash)
{
	char *dst;
	int i = 0;

	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	dst = malloc(sizeof(char) * (i + 1));
	while (*stash != '\n' && *stash != '\0')
	{
		*dst++ = (*stash)++;
	}
	*dst = '\0';
	return (dst);
	
}

char	*get_next_line(int fd)
{
	static char *stash;
	ssize_t bytes_read;
	char buffer[BUFFER_SIZE + 1];

	while (!ft_strchr_spc(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	return (find_next(&stash));
}
