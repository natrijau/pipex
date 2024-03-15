/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:04:53 by natrijau          #+#    #+#             */
/*   Updated: 2024/03/15 16:43:02 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* Check numb arguments */
void	check_ac(int ac)
{
	if (ac != 5)
	{
		ft_putstr_fd("Not enough arguments !\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	get_infile(t_struc *list, char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(" : No such file or directory\n", 2);
	}
	list->fd_infile = fd;
}

void	get_outfile(t_struc *list, char *str)
{
	int	fd;

	fd = open(str, O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (fd < 0)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(" : Permission denied\n", 2);
		close(list->fd_infile);
		exit(EXIT_FAILURE);
	}
	list->fd_outfile = fd;
}

void	check_env(char **str, t_struc *list)
{
	char	*path;
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_strncmp(str[i], "PATH", 4) == 0)
		{
			path = ft_strdup(str[i]);
			(*list).path = ft_substr(path, 5, ft_strlen(path));
			free(path);
			return ;
		}
		i++;
	}
	if (!(*list).path)
	{
		close(list->fd_outfile);
		close(list->fd_infile);
		ft_printf("environment variable not found\n");
		exit(EXIT_FAILURE);
	}
}
