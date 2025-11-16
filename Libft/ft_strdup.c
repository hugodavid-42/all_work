/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:28:48 by hdavid            #+#    #+#             */
/*   Updated: 2025/11/08 14:44:03 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		len_s;
	int		index;

	index = 0;
	len_s = ft_strlen((char *)s);
	dest = (char *)malloc((sizeof(char)) * (len_s + 1));
	if (!dest)
		return (NULL);
	while (index < len_s)
	{
		dest[index] = s[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
