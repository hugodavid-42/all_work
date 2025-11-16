/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:29:18 by hdavid            #+#    #+#             */
/*   Updated: 2025/11/10 17:51:13 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	j;

	index = 0;
	j = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (big[index] && index < len)
	{
		while (big[index + j] == little[j] && big[index + j] && index + j < len)
		{
			j ++;
			if (little[j] == '\0')
				return ((char *)big + index);
		}
		index ++;
		j = 0;
	}
	return (NULL);
}
