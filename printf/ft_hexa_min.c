/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:55:36 by natrijau          #+#    #+#             */
/*   Updated: 2023/11/20 12:25:02 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_hexa_min(unsigned int n)
{
	if (n > 15)
		ft_put_hexa_min(n / 16);
	if (n >= 0 && n <= 9)
		ft_putchar(n + 48);
	else if (n >= 10 && n < 16)
		ft_putchar(n + 87);
	if (n > 15)
		ft_put_hexa_min(n % 16);
}

int	ft_hexa_min(unsigned int n)
{
	unsigned int	i;
	unsigned int	nb;

	nb = n;
	i = 0;
	if (n == 0)
		i++;
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	ft_put_hexa_min(n);
	return (i);
}
