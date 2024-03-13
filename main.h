/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:52:36 by natrijau          #+#    #+#             */
/*   Updated: 2024/03/13 18:11:13 by natrijau         ###   ########.fr       */
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

char	*first_word(char *str);
void	check_ac(int ac);
void	free_all(t_struc *list);
void	check_env(char **str, t_struc *list);
void	get_all_path(char *str, t_struc *list);
char	**free_split(char **s);
void	init_cmd(t_struc *list, char **av);
void	parent_process(t_struc *list, int pipefd[2]);
void	error(int error_code, char *error_msg);
void	get_infile(t_struc *list, char *str);
void	get_outfile(t_struc *list, char *str);
char	*get_cmd(char *str);
void	init_cmd(t_struc *list, char **av);
void	cmd1(t_struc *list, char **av);
void	cmd2(t_struc *list, char **av);
void	get_options_cmd(t_struc *list, char *str1, char *str2);
void	close_all(t_struc *list, int *pipefd);
#endif