/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:59:40 by natrijau          #+#    #+#             */
/*   Updated: 2024/03/11 11:57:19 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	check_ac(int ac)
{
	if (ac != 5)
	{
		ft_putstr_fd("Not enough arguments !\n", 2);
		exit(EXIT_FAILURE);
	}
}
