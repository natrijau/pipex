/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:11:36 by natrijau          #+#    #+#             */
/*   Updated: 2023/11/20 12:06:10 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n)
{
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10);
		ft_putnbr_unsigned(n % 10);
	}
	if (n >= 0 && n <= 9)
		ft_putchar(n + 48);
}

int	ft_nbr_unsigned(unsigned int n)
{
	unsigned int	i;
	unsigned int	nb;

	i = 0;
	nb = n;
	if (n <= 0)
		i++;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	ft_putnbr_unsigned(n);
	return (i);
}
