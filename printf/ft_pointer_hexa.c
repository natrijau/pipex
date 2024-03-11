/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:30:17 by natrijau          #+#    #+#             */
/*   Updated: 2023/11/20 16:19:04 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_hexa(unsigned long long n)
{
	int	count;

	count = 1;
	while (n > 15)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

void	ft_hexa(unsigned long long n)
{
	if (n > 15)
		ft_hexa(n / 16);
	if (n >= 0 && n <= 9)
		ft_putchar(n + 48);
	else if (n >= 10 && n < 16)
		ft_putchar(n + 87);
	if (n > 15)
		ft_hexa(n % 16);
}

int	ft_pointer_hexa(unsigned long long n)
{
	int	count;

	count = 0;
	if (!n)
	{
		ft_putstr("(nil)");
		count = 5;
		return (count);
	}
	count += ft_putstr("0x");
	count += ft_count_hexa(n);
	ft_hexa(n);
	return (count);
}
