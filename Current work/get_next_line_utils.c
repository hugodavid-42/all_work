/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:45:23 by hdavid            #+#    #+#             */
/*   Updated: 2025/11/20 19:32:23 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

char *ft_strchr_spc(char * str, char sep)
{
	if (!str)
		return NULL;
	while(str)
	{
		if (*str == sep)
			return (str);
		str ++;
	}
	return NULL;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while(str[i] != '\0')
		i++;
	return (i);
}

char *ft_strjoin(char *stash, char *buffer)
{
	char	*dst;
	int		dst_len;
	char	*start;

	dst_len = ft_strlen(stash) + ft_strlen(buffer);
	dst = malloc(sizeof(char) * (dst_len + 1));

	start = dst;
	if(stash)
		while(*stash)
			*dst++ = *stash++;
	if(buffer)
		while(*buffer)
			*dst++ = *buffer++;
	*dst = '\0';
	return (start);
}

char	*ft_strdup(char *str)
{
	char	*dst;
	size_t	len_dst;
	size_t	i;

	len_dst = ft_strlen(str);
	dst = malloc((len_dst + 1));

	if (!dst)
		return (NULL);
	i = 0;
	while (i < len_dst)
	{
		dst[i] = str[i];
		i ++;
	}
	dst[i] = '\0';
	return (dst);
}