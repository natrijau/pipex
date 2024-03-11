/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:26:18 by natrijau          #+#    #+#             */
/*   Updated: 2023/11/10 17:19:53 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;

	if (!lst || !(f) || !(del))
		return (NULL);
	while (lst != NULL)
	{
		node = (f)(lst->content);
		if (!node)
			ft_lstclear(&node, (del));
		lst = lst->next;
	}
	lst = (NULL);
	return (node);
}
