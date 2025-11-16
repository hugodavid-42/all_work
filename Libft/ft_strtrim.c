/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:31:17 by hdavid            #+#    #+#             */
/*   Updated: 2025/11/13 15:01:34 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char *ft_strtrim(char const *s1, char const *set)
// {
// 	char *copy;
// 	int	set_len;
// 	int start;

// 	start = 0;
// 	set_len = ft_strlen(set);
// 	while (s1[start] == ' ')
// 		start ++;
// 	if (!s1 || !set || (int)ft_strlen(s1 + start) <= set_len)
// 		return (NULL);
// 	if (ft_strncmp(s1 + start, set, set_len) == 0)
// 		copy = ft_strdup(s1 + start + set_len);
// 	else
// 		copy = ft_strdup(s1 + start);

// 	if (ft_strncmp(copy + ft_strlen(copy) - set_len, set, set_len) == 0)
// 		ft_memset(copy + ft_strlen(copy) - set_len - 1, 0, 1);
// 	return (copy);
// }

static int	ft_scan(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (s1[i] != set[j])
			break ;
		i++;
	}
	return (i + 1);
}

static int	ft_reverse_scan(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (s1[i] != set[j])
			break ;
		i--;
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	start = ft_scan(s1, set);
	end = ft_reverse_scan(s1, set);
	ptr = ft_substr(s1, start - 1, end - start + 1);
	if (!ptr)
		return (NULL);
	return (ptr);
}
