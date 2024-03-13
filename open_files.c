/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:58:48 by natrijau          #+#    #+#             */
/*   Updated: 2024/03/13 11:07:16 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	get_infile(t_struc *list, char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("%s: No such file or directory\n", str);
	}
	list->fd_infile = fd;
}

void	get_outfile(t_struc *list, char *str)
{
	int	fd;

	fd = open(str, O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (fd < 0)
	{
		ft_printf("%s: Permission denied\n", str);
		close(list->fd_infile);
		exit(EXIT_FAILURE);
	}
	list->fd_outfile = fd;
}
