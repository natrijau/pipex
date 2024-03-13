/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:14:55 by natrijau          #+#    #+#             */
/*   Updated: 2024/03/13 12:51:21 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*first_word(char *str)
{
	int		i;
	int		start;
	char	*copy;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	start = i;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			break ;
		i++;
	}
	copy = ft_substr(str, start, (i - start));
	return (copy);
}

void	init_cmd(t_struc *list, char **av)
{
	list->cmd1 = first_word(av[2]);
	list->cmd2 = first_word(av[3]);
}

void	parent_process(t_struc *list, int pipefd[2])
{
	int	status;
	int	returned;

	if (list->fd_infile == -1)
		return ;
	close_all(list, pipefd);
	if (list->id_fork1 > 0)
		waitpid(list->id_fork1, NULL, 0);
	if (list->id_fork2 > 0)
	{
		waitpid(list->id_fork2, &status, 0);
		returned = WEXITSTATUS(status);
		if (returned != 0)
		{
			free_all(list);
			exit(returned);
		}
	}
}

void	get_options_cmd(t_struc *list, char *str1, char *str2)
{
	list->cmd1_options = ft_split(str1, ' ');
	list->cmd2_options = ft_split(str2, ' ');
}
