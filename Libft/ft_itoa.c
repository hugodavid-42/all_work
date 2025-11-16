/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:29:12 by hdavid            #+#    #+#             */
/*   Updated: 2025/11/12 11:17:31 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	nbr_len(long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len ++;
	while (n != 0)
	{
		n /= 10;
		len ++;
	}
	return (len);
}

static void	*ft_putnbr(long long n, char *dst, int *i)
{
	if (n < 0)
	{
		dst[(*i)++] = '-';
		n = -n;
	}
	if (n > 9)
	{
		dst = ft_putnbr(n / 10, dst, i);
	}
	dst[(*i)++] = ((n % 10) + '0');
	return (dst);
}

char	*ft_itoa(int n)
{
	long long	nbr;
	int			length;
	char		*dst;
	int			i;

	i = 0;
	nbr = n;
	length = nbr_len(nbr);
	dst = (char *)malloc(sizeof(char) * (length + 1));
	if (!dst)
		return (NULL);
	ft_putnbr(n, dst, &i);
	dst[i] = '\0';
	return (dst);
}
