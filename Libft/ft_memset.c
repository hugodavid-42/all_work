/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:28:38 by hdavid            #+#    #+#             */
/*   Updated: 2025/11/12 10:28:32 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *ptr, int value, int count)
{
	int				index;
	unsigned char	*p;

	p = (unsigned char *)ptr;
	index = 0;
	while (index < count)
	{
		p[index] = (unsigned char)value;
		index ++;
	}
	return (ptr);
}
