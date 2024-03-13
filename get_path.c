/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:49:24 by natrijau          #+#    #+#             */
/*   Updated: 2024/03/13 17:50:34 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	path = (NULL);
	(*list).path = (NULL);
	if (!path)
	{
		close(list->fd_outfile);
		close(list->fd_infile);
		ft_printf("environment variable not found\n");
		exit(EXIT_FAILURE);
	}
}

void	get_all_path(char *str, t_struc *list)
{
	char	**tab;
	int		i;
	char	*s2;

	i = 0;
	tab = ft_split(str, ':');
	while (tab[i])
	{
		s2 = malloc(sizeof(char) * 2);
		s2[0] = '/';
		s2[1] = '\0';
		tab[i] = ft_strjoin(tab[i], s2);
		free(s2);
		i++;
	}
	free(str);
	(*list).all_path_cmd = tab;
}
