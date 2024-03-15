/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:52:36 by natrijau          #+#    #+#             */
/*   Updated: 2024/03/15 16:06:10 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <stdbool.h>
# include "./libft/libft.h"
# include "./printf/ft_printf.h"

typedef struct s_struct
{
	pid_t			id_fork1;
	pid_t			id_fork2;
	char			*path;
	char			**all_path_cmd;
	char			*cmd1;
	char			*cmd1_with_path;
	char			*cmd2;
	char			*cmd2_with_path;
	char			**cmd1_options;
	char			**cmd2_options;
	int				fd_infile;
	int				fd_outfile;
	int				new_stdout;
	struct s_stak	*next;
}	t_struc;

/*parsing.c*/
void	check_ac(int ac);
void	get_infile(t_struc *list, char *str);
void	get_outfile(t_struc *list, char *str);
void	check_env(char **str, t_struc *list);

/*init_struc.c*/
void	init_all(t_struc *list);
void	init_cmd(t_struc *list, char **av);

/*init_cmd.c*/
void	get_all_path(char *str, t_struc *list);
bool	check_access(t_struc *list, int id);
void	cmd1(t_struc *list);
void	cmd2(t_struc *list);

/*process.c*/
void	child_process(t_struc *list, int *pipefd, char **envp);
void	child_process2(t_struc *list, int *pipefd, char **envp);
void	parent_process(t_struc *list, int pipefd[2]);

/*utils.c*/
char	*first_word(char *str);
void	get_options_cmd(t_struc *list, char *str1, char *str2);
bool	ft_all_space(char *str);

/*free.c*/
void	free_close_exit(t_struc *list, int *pipefd);
void	close_all(t_struc *list, int *pipefd);
void	free_all(t_struc *list);
char	**free_split(char **s);

#endif