/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:21:21 by hdavid            #+#    #+#             */
/*   Updated: 2025/11/16 15:08:39 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putnbr(int n, int *count)
{
	long long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-', count);
		nbr = -nbr;
	}
	if (nbr > 9)
		ft_putnbr (nbr / 10, count);
	ft_putchar (nbr % 10 + '0', count);
}

void	ft_putnbr_unsigned(unsigned int nbr, int *count)
{
	if (nbr > 9)
		ft_putnbr_unsigned (nbr / 10, count);
	ft_putchar (nbr % 10 + '0', count);
}

void	print_str(const char	*arg, int *count)
{
	int	i;

	i = 0;
	if (arg == NULL)
		return ;
	while (arg[i] != '\0')
	{
		ft_putchar(arg[i], count);
		i ++;
	}
}
