/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:09:57 by natrijau          #+#    #+#             */
/*   Updated: 2024/03/15 16:45:44 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	child_process(t_struc *list, int *pipefd, char **envp)
{
	if (list->cmd1_with_path == NULL)
		list->cmd1_with_path = ft_strdup(list->cmd1);
	if (list->id_fork1 == -1)
		free_close_exit(list, pipefd);
	else if (list->id_fork1 == 0)
	{
		if (list->fd_infile == -1)
			free_close_exit(list, pipefd);
		if (dup2(list->fd_infile, 0) < 0)
			ft_putstr_fd("Error dup2", 2);
		if (dup2(pipefd[1], 1) < 0)
			ft_putstr_fd("Error dup2", 2);
		close_all(list, pipefd);
		execve(list->cmd1_with_path, list->cmd1_options, envp);
		ft_putstr_fd(list->cmd1_with_path, 2);
		ft_putstr_fd(" : command not found\n", 2);
		free_all(list);
		exit(127);
	}
}

void	child_process2(t_struc *list, int *pipefd, char **envp)
{
	if (list->cmd2_with_path == NULL)
		list->cmd2_with_path = ft_strdup(list->cmd2);
	if (list->fd_outfile == -1)
		return ;
	if (list->id_fork2 == -1)
		free_close_exit(list, pipefd);
	if (list->id_fork2 == 0)
	{
		if (dup2(pipefd[0], 0) < 0)
			ft_putstr_fd("Error dup2", 2);
		if (dup2(list->fd_outfile, 1) < 0)
			ft_putstr_fd("Error dup2", 2);
		close_all(list, pipefd);
		execve(list->cmd2_with_path, list->cmd2_options, envp);
		ft_putstr_fd(list->cmd2_with_path, 2);
		ft_putstr_fd(" : command not found\n", 2);
		free_all(list);
		exit(127);
	}
}

void	parent_process(t_struc *list, int pipefd[2])
{
	int	status;
	int	returned;

	close_all(list, pipefd);
	if (list->id_fork1 > 0)
		waitpid(list->id_fork1, NULL, 0);
	if (list->id_fork2 > 0)
	{
		waitpid(list->id_fork2, &status, 0);
		returned = WEXITSTATUS(status);
		if (returned != 0)
		{
			close_all(list, pipefd);
			free_all(list);
			exit(returned);
		}
	}
}
