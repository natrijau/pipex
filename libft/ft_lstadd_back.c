/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:06:45 by natrijau          #+#    #+#             */
/*   Updated: 2023/11/10 17:24:25 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*stock;

	if (!lst || !new)
		return ;
	if (!(*lst))
		(*lst) = new;
	else
	{
		stock = ft_lstlast(*lst);
		stock->next = new;
	}
}
