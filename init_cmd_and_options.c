/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_and_options.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:02:05 by natrijau          #+#    #+#             */
/*   Updated: 2024/03/11 18:08:20 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_access_cmd1(t_struc *list)
{
	int		i;
	char	*cmd;
	char	*copy;

	i = 0;
	while (list->all_path_cmd[i])
	{
		copy = ft_strdup(list->all_path_cmd[i]);
		cmd = ft_strjoin(copy, list->cmd1);
		if (access(cmd, X_OK) == 0)
		{
			list->cmd1_with_path = ft_strdup(cmd);
			free(cmd);
			return (0);
		}
		free(cmd);
		i++;
	}
	return (1);
}

int	check_access_cmd2(t_struc *list)
{
	int		i;
	char	*cmd;
	char	*copy;

	i = 0;
	while (list->all_path_cmd[i])
	{
		copy = ft_strdup(list->all_path_cmd[i]);
		cmd = ft_strjoin(copy, list->cmd2);
		if (access(cmd, X_OK) == 0)
		{
			list->cmd2_with_path = ft_strdup(cmd);
			free(cmd);
			return (0);
		}
		free(cmd);
		i++;
	}
	return (1);
}

void	cmd2(t_struc *list, char **av)
{
	if (check_access_cmd2(list) == 0)
		return ;
	if (av[2][0] == '/')
		list->cmd2_with_path = ft_strdup(first_word(av[2]));
	else
	{
		list->cmd2_with_path = (NULL);
		ft_printf("%s: command not found\n", list->cmd2);
		free_all(list);
		close(list->fd_infile);
		exit(127);
	}
}

void	cmd1(t_struc *list, char **av)
{
	if (check_access_cmd1(list) == 0)
		return ;
	if (av[3][0] == '/')
		list->cmd2_with_path = ft_strdup(av[3]);
	else
	{
		list->cmd1_with_path = (NULL);
		ft_printf("%s: command not found\n", list->cmd1);
	}
}
