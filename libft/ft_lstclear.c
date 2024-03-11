/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:07:08 by natrijau          #+#    #+#             */
/*   Updated: 2024/02/26 12:23:17 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*stock;

	if (!lst || !del)
		return ;
	while ((*lst) != NULL)
	{
		stock = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = stock;
	}
	*lst = (NULL);
}
