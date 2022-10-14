/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlandia <arlandia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:16:08 by arlandia          #+#    #+#             */
/*   Updated: 2022/10/14 17:23:18 by arlandia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n *= -1;
		ft_printchar('-');
		len++;
	}
	if (n > 9)
		len += ft_printnbr(n / 10);
	len += ft_printchar(n % 10 + '0');
	return (len);
}

int	ft_printu(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n >= 10)
		len += ft_printu(n / 10);
	len += ft_printchar(n % 10 + '0');
	return (len);
}
