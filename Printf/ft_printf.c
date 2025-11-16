/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:21:29 by hdavid            #+#    #+#             */
/*   Updated: 2025/11/16 14:44:02 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

void	find_args(const char *str, int arg, int i, int *count)
{
	if (str[i] == 'c')
		ft_putchar((const char)arg, count);
	else if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr(arg, count);
	else if (str[i] == 'u')
		ft_putnbr_unsigned((unsigned int)arg, count);
	else if (str[i] == 'x')
		convert_hex_low((unsigned int)arg, count);
	else if (str[i] == 'X')
		convert_hex_cap((unsigned int)arg, count);
	else if (str[i] == 'p')
	{
		print_str("0x", count);
		convert_hex_low((unsigned int)arg, count);
	}
	else
		return ;
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			ft_putchar(str[i], &count);
		else
		{
			i ++;
			if (str[i] == 's')
				print_str((const char *)va_arg(ap, int *), &count);
			else if (str[i] == '%')
				ft_putchar('%', &count);
			else
				find_args(str, va_arg(ap, int), i, &count);
		}
		i ++;
	}
	va_end(ap);
	return (count);
}
