/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:38:55 by natrijau          #+#    #+#             */
/*   Updated: 2024/03/11 18:06:34 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	child_process(t_struc *list, int *pipefd, char **envp)
{
	if (list->fd_infile == -1)
		return ;
	if (list->id_fork1 == -1)
	{
		free_all(list);
		close_all(list, pipefd);
		exit(EXIT_FAILURE);
	}
	if (list->id_fork1 == 0)
	{
		close(pipefd[0]);
		dup2(list->fd_infile, 0);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		close(list->fd_outfile);
		close(list->fd_infile);
		execve(list->cmd1_with_path, list->cmd1_options, envp);
		free_all(list);
		exit(EXIT_FAILURE);
	}
}

void	child_process2(t_struc *list, int *pipefd, char **envp)
{
	if (list->fd_infile == -1)
		return ;
	if (list->id_fork2 == -1)
	{
		free_all(list);
		close_all(list, pipefd);
		exit(EXIT_FAILURE);
	}
	if (list->id_fork2 == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		dup2(list->fd_outfile, 1);
		close(pipefd[0]);
		close(list->fd_outfile);
		close(list->fd_infile);
		execve(list->cmd2_with_path, list->cmd2_options, envp);
		free_all(list);
		exit(EXIT_FAILURE);
	}
}

void	init_cmd1(char **av, t_struc *list)
{
	int	i;

	i = 0;
	if (av[2][0] != '/')
		cmd1(list, av);
	else
	{
		while (av[2][i] && av[2][i] != ' ')
			i++;
		list->cmd1_with_path = ft_substr(av[2], 0, i);
		if (access(list->cmd1_with_path, X_OK | F_OK) != 0)
			ft_printf("%s: No such file or directory\n", list->cmd1_with_path);
	}
}

void	init_cmd2(char **av, t_struc *list)
{
	int	j;

	j = 0;
	if (av[3][0] != '/')
		cmd2(list, av);
	else
	{
		while (av[3][j] && av[3][j] != ' ')
			j++;
		list->cmd2_with_path = ft_substr(av[3], 0, j);
		if (access(list->cmd2_with_path, X_OK | F_OK) != 0)
			ft_printf("%s: No such file or directory\n", list->cmd2_with_path);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_struc	list;
	int		pipefd[2];

	check_ac(ac);
	get_infile(&list, av[1]);
	get_outfile(&list, av[4]);
	check_env(envp, &list, av);
	get_all_path(list.path, &list);
	init_cmd(&list, av);
	get_options_cmd(&list, av[2], av[3]);
	init_cmd1(av, &list);
	init_cmd2(av, &list);
	if (pipe(pipefd) == -1)
	{
		ft_putstr_fd("Error with pipe! \n", 2);
		exit(EXIT_FAILURE);
	}
	list.id_fork1 = fork();
	child_process(&list, pipefd, envp);
	list.id_fork2 = fork();
	child_process2(&list, pipefd, envp);
	parent_process(&list, pipefd);
	close_all(&list, pipefd);
	free_all(&list);
	return (0);
}
