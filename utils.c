/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:14:55 by natrijau          #+#    #+#             */
/*   Updated: 2024/03/15 16:44:02 by natrijau         ###   ########.fr       */
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

void	get_options_cmd(t_struc *list, char *str1, char *str2)
{
	list->cmd1_options = ft_split(str1, ' ');
	list->cmd2_options = ft_split(str2, ' ');
}

bool	ft_all_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (false);
		i++;
	}
	return (true);
}
