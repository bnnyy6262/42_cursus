/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medalgic <medalgic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 03:56:24 by medalgic          #+#    #+#             */
/*   Updated: 2023/12/05 03:56:31 by medalgic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	replace_pipes(char *str, char delimeter);
static void	restore_pipes(char **exec_args);

char	**split_commands(char *input)
{
	char	**commands;

	replace_pipes(input, '"');
	replace_pipes(input, '\'');
	commands = ft_split(input, '|');
	restore_pipes(commands);
	return (commands);
}

static void	replace_pipes(char *str, char delimeter)
{
	while (*str && *str != delimeter)
		str++;
	if (*str)
		str++;
	while (*str && *str != delimeter)
	{
		if (*str == '|')
			*str = -1;
		str++;
	}
	if (*str)
		str++;
	if (*str)
		replace_pipes(str, delimeter);
}

static void	restore_pipes(char **exec_args)
{
	char	*str;

	while (*exec_args)
	{
		str = *exec_args;
		while (*str)
		{
			if (*str == -1)
				*str = '|';
			str++;
		}
		exec_args++;
	}
	return ;
}
