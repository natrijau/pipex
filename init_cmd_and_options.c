/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_and_options.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:02:05 by natrijau          #+#    #+#             */
/*   Updated: 2024/03/13 12:50:24 by natrijau         ###   ########.fr       */
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

bool	ft_all_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' || str[i] != '\t')
			return false;
		i++;	
	}
	return true;
}

void	cmd2(t_struc *list, char **av)
{
	if (av[2][0] == '\0' || ft_all_space(list->cmd2))
	{
		list->cmd2_with_path = (NULL);
		close(list->fd_infile);
		close(list->fd_outfile);
		free_all(list);
		exit(1);
	}
	if (av[2][0] == '/')
		list->cmd2_with_path = ft_strdup(first_word(av[2]));
	if (!list->cmd2 || check_access_cmd2(list) == 0)
		return ;
	else
	{
		list->cmd2_with_path = (NULL);
		ft_printf("%s: command not found\n", list->cmd2);
	}
}

void	cmd1(t_struc *list, char **av)
{
	if (av[3][0] == '/')
		list->cmd1_with_path = ft_strdup(av[3]);
	if (!list->cmd1 || check_access_cmd1(list) == 0)
		return ;
}
