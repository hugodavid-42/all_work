/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:12:15 by hdavid            #+#    #+#             */
/*   Updated: 2025/11/16 14:17:18 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

/*	Fonction de print	*/
void	ft_putchar(char c, int *count);
void	ft_putnbr_unsigned(unsigned int n, int *count);
void	ft_putnbr(int n, int *count);
void	print_str(const char	*arg, int *count);
void	convert_hex_low(unsigned int n, int *count);
void	convert_hex_cap(unsigned int n, int *count);
void	ptr_adress(unsigned int n, int *count);

/*	Printf	*/
int		ft_printf(const char *str, ...);
#endif