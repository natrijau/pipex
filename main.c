/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:38:55 by natrijau          #+#    #+#             */
/*   Updated: 2024/03/15 16:06:15 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av, char **envp)
{
	t_struc	list;
	int		pipefd[2];

	check_ac(ac);
	get_infile(&list, av[1]);
	get_outfile(&list, av[4]);
	init_cmd(&list, av);
	check_env(envp, &list);
	get_all_path(list.path, &list);
	get_options_cmd(&list, av[2], av[3]);
	cmd1(&list);
	cmd2(&list);
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
