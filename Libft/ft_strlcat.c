/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:28:54 by hdavid            #+#    #+#             */
/*   Updated: 2025/11/10 17:50:43 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index_src;
	size_t	src_len;
	size_t	dst_len;	

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size == 0)
		return (src_len);
	if (dst_len >= size)
		return (size + src_len);
	index_src = 0;
	while (dst_len + index_src < size - 1 && src[index_src])
	{
		dst[dst_len + index_src] = src[index_src];
		index_src++;
	}
	dst[dst_len + index_src] = 0;
	if (size - dst_len > src_len)
		return (dst_len + index_src);
	else
		return (dst_len + src_len);
}
