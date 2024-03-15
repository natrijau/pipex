/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:16:48 by natrijau          #+#    #+#             */
/*   Updated: 2024/03/15 16:42:29 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_all(t_struc *list)
{
	list->path = (NULL);
	list->cmd1 = (NULL);
	list->cmd1_with_path = (NULL);
	list->cmd2 = (NULL);
	list->cmd2_with_path = (NULL);
	list->all_path_cmd = (NULL);
	list->cmd1_options = (NULL);
	list->cmd2_options = (NULL);
}

void	init_cmd(t_struc *list, char **av)
{
	init_all(list);
	if (ft_all_space(av[2]))
		list->cmd1 = ft_strdup(av[2]);
	else
		list->cmd1 = first_word(av[2]);
	if (ft_all_space(av[3]))
		list->cmd2 = ft_strdup(av[3]);
	else
		list->cmd2 = first_word(av[3]);
}
