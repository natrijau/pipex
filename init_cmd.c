/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:02:05 by natrijau          #+#    #+#             */
/*   Updated: 2024/03/15 16:44:37 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	get_all_path(char *str, t_struc *list)
{
	char	**tab;
	int		i;
	char	*s2;

	i = 0;
	tab = ft_split(str, ':');
	while (tab[i])
	{
		s2 = malloc(sizeof(char) * 2);
		s2[0] = '/';
		s2[1] = '\0';
		tab[i] = ft_strjoin(tab[i], s2);
		free(s2);
		i++;
	}
	free(str);
	(*list).all_path_cmd = tab;
}

bool	check_access(t_struc *list, int id)
{
	int		i;
	char	*cmd;
	char	*copy;

	i = 0;
	while (list->all_path_cmd[i])
	{
		copy = ft_strdup(list->all_path_cmd[i]);
		if (id == 0)
			cmd = ft_strjoin(copy, list->cmd1);
		else
			cmd = ft_strjoin(copy, list->cmd2);
		if (access(cmd, X_OK) == 0)
		{
			if (id == 0)
				list->cmd1_with_path = ft_strdup(cmd);
			else
				list->cmd2_with_path = ft_strdup(cmd);
			free(cmd);
			return (true);
		}
		free(cmd);
		i++;
	}
	return (false);
}

void	cmd1(t_struc *list)
{
	if (list->cmd1[0] == '\0')
		return ;
	else if (list->cmd1[0] == '/')
		list->cmd1_with_path = ft_strdup(list->cmd1);
	if (check_access(list, 0))
		return ;
}

void	cmd2(t_struc *list)
{
	if (list->cmd2[0] == '\0')
		return ;
	else if (list->cmd2[0] == '/')
		list->cmd2_with_path = ft_strdup(list->cmd2);
	if (check_access(list, 1))
		return ;
}
