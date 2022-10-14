/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlandia <arlandia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:21:06 by arlandia          #+#    #+#             */
/*   Updated: 2022/10/14 18:08:06 by arlandia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, char x)
{
	int	len;

	len = 0;
	if (x == 's')
		len += ft_printstr(va_arg (args, char *));
	else if (x == 'd' || x == 'i')
		len += ft_printnbr(va_arg (args, int));
	else if (x == 'u')
		len += ft_printu(va_arg (args, int));
	else if (x == 'x')
		len += ft_printhexa(va_arg(args, unsigned int), x);
	else if (x == 'X')
		len += ft_printhexa(va_arg(args, unsigned int), x);
	else if (x == 'p')
	{
		len += ft_printstr("0x")
			+ ft_printhexa(va_arg(args, size_t), x);
	}
	else if (x == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (x == '%')
		len += ft_printchar('%');
	return (len);
}

int	ft_printf(char const *x, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start (args, x);
	while (x[i])
	{
		if (x[i] != '%')
		{
			ft_printchar(x[i]);
			len++;
		}
		if (x[i] == '%')
		{
			i++;
			len += ft_format(args, x[i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}
