/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:27:16 by hdavid            #+#    #+#             */
/*   Updated: 2025/11/08 14:43:49 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi(const char *nptr)
{
	int			index;
	long long	res;
	int			sign;

	sign = 1;
	index = 0;
	res = 0;
	while (nptr[index] == ' ' || (nptr[index] >= '\t' && nptr[index] <= '\r'))
		index++;
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index] == '-')
			sign *= -1;
		index++;
	}
	while (nptr[index] != '\0' && (nptr[index] >= '0' && nptr[index] <= '9'))
	{
		res = res * 10 + nptr[index] - '0';
		index++;
	}
	return (res * sign);
}
