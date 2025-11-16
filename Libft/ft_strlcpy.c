/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:28:59 by hdavid            #+#    #+#             */
/*   Updated: 2025/11/10 17:52:49 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen (src);
	if (src_len >= size)
	{
		if (size > 0)
		{
			ft_memcpy (dst, src, size);
			dst[size - 1] = '\0';
		}
	}
	else
		ft_memcpy (dst, src, src_len + 1);
	return (src_len);
}
