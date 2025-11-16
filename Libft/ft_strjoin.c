/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:27:25 by hdavid            #+#    #+#             */
/*   Updated: 2025/11/08 17:02:39 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		size_dest;

	size_dest = ft_strlen ((char *)s1) + ft_strlen ((char *)s2);
	dest = (char *)malloc((sizeof(char)) * (size_dest + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, ft_strlen ((char *)s1) + 1);
	ft_strlcat(dest, s2, size_dest + 1);
	return (dest);
}
