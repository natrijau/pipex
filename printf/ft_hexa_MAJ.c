/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_MAJ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:54:30 by natrijau          #+#    #+#             */
/*   Updated: 2023/11/20 12:32:50 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_hexa_maj(unsigned int n)
{
	if (n > 15)
		ft_put_hexa_maj(n / 16);
	if (n >= 0 && n <= 9)
		ft_putchar(n + 48);
	else if (n >= 10 && n < 16)
		ft_putchar(n + 55);
	if (n > 15)
		ft_put_hexa_maj(n % 16);
}

int	ft_hexa_maj(unsigned int n)
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
	ft_put_hexa_maj(n);
	return (i);
}
