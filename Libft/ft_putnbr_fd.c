/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:26:31 by hdavid            #+#    #+#             */
/*   Updated: 2025/11/08 14:26:37 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd ('-', fd);
		nbr = -nbr;
	}
	if (nbr > 9)
		ft_putnbr_fd (nbr / 10, fd);
	ft_putchar_fd (nbr % 10 + '0', fd);
}
