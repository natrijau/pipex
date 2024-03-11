/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:34:18 by natrijau          #+#    #+#             */
/*   Updated: 2023/11/20 16:06:19 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	list_format(va_list ptr, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(ptr, int));
	if (c == 's')
		i += ft_putstr(va_arg(ptr, char *));
	if (c == 'd')
		i += ft_nbr(va_arg(ptr, int));
	if (c == 'i')
		i += ft_nbr(va_arg(ptr, int));
	if (c == 'u')
		i += ft_nbr_unsigned(va_arg(ptr, unsigned int));
	if (c == 'x')
		i += ft_hexa_min(va_arg(ptr, unsigned int));
	if (c == 'X')
		i += ft_hexa_maj(va_arg(ptr, unsigned int));
	if (c == 'p')
		i += ft_pointer_hexa(va_arg(ptr, unsigned long long));
	if (c == '%')
		i += ft_percent();
	return (i);
}

int	ft_printf(const char *list, ...)
{
	int		i;
	va_list	ptr;
	int		len;

	if (!list)
		return (-1);
	len = 0;
	va_start(ptr, list);
	i = 0;
	while (list[i])
	{
		if (list[i] != '%')
			len += ft_putchar(list[i]);
		else if (list[i] == '%')
		{
			len += list_format(ptr, list[i + 1]);
			i++;
		}
		i++;
	}
	va_end(ptr);
	return (len);
}
