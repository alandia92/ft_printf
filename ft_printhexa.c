/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlandia <arlandia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:32:53 by arlandia          #+#    #+#             */
/*   Updated: 2022/10/14 19:13:56 by arlandia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa(size_t num, char x)
{
	int	len;

	len = 0;
	if (x == 0)
	{
		write (1, "0", 1);
		len = 1;
	}
	if (x == 'p' || x == 'x')
	{
		if (16 <= num)
			len += ft_printhexa(num / 16, x);
		len += ft_printchar("0123456789abcdef"[num % 16]);
	}
	else if (x == 'X')
	{
		if (16 <= num)
			len += ft_printhexa(num / 16, x);
		len += ft_printchar("0123456789ABCDEF"[num % 16]);
	}
	return (len);
}
