/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:28:32 by hdavid            #+#    #+#             */
/*   Updated: 2025/11/12 10:28:29 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*d;
	unsigned char	*s;

	index = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (index < n)
	{
		if (d < s)
			d[index] = s[index];
		else
			d[n - 1 - index] = s[n - 1 - index];
		index++;
	}
	return (dest);
}
