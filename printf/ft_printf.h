/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:46:12 by natrijau          #+#    #+#             */
/*   Updated: 2023/11/20 16:01:06 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *list, ...);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_percent(void);
int		ft_nbr(int n);
int		ft_pointer_hexa(unsigned long long n);
int		ft_hexa_min(unsigned int n);
int		ft_hexa_maj(unsigned int n);
int		ft_put_hexa(char *s);
int		ft_nbr_unsigned(unsigned int n);
#endif
