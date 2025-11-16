/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:27:28 by hdavid            #+#    #+#             */
/*   Updated: 2025/11/12 10:28:23 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *ptr, size_t value)
{
	size_t			index;
	unsigned char	*p;

	p = (unsigned char *)ptr;
	index = 0;
	while (index < value)
	{
		p[index] = '\0';
		index ++;
	}
}
