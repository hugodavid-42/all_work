/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:14:03 by hdavid            #+#    #+#             */
/*   Updated: 2025/11/16 15:09:57 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_hex_low(unsigned int n, int *count)
{
	char	*scale;

	scale = "0123456789abcdef";
	if (n >= 16)
		convert_hex_low(n / 16, count);
	ft_putchar(scale[n % 16], count);
}

void	convert_hex_cap(unsigned int n, int *count)
{
	char	*scale;

	scale = "0123456789ABCDEF";
	if (n >= 16)
		convert_hex_cap(n / 16, count);
	ft_putchar(scale[n % 16], count);
}
