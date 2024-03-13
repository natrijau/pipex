/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:20:06 by natrijau          #+#    #+#             */
/*   Updated: 2024/03/12 16:04:03 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	close_all(t_struc *list, int *pipefd)
{
	if (pipefd[0])
		close(pipefd[0]);
	if (pipefd[1])
		close(pipefd[1]);
	if (list->fd_infile)
		close(list->fd_infile);
	if (list->fd_outfile)
		close(list->fd_outfile);
}

void	free_all(t_struc *list)
{
	if (!list)
		return ;
	if (list->cmd1)
		free(list->cmd1);
	if (list->cmd2)
		free(list->cmd2);
	if (list->cmd1_with_path)
		free(list->cmd1_with_path);
	if (list->cmd2_with_path)
		free(list->cmd2_with_path);
	if (list->all_path_cmd)
		free_split(list->all_path_cmd);
	if (list->cmd1_options)
		free_split(list->cmd1_options);
	if (list->cmd2_options)
		free_split(list->cmd2_options);
}

char	**free_split(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}
