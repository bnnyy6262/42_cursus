/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssakarya <ssakarya@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 03:56:21 by medalgic          #+#    #+#             */
/*   Updated: 2024/01/08 16:55:19 by ssakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_prompt_str(t_env *minienv)
{
	char		*cwd;
	char		*directory;
	static char	prompt[PATH_MAX];

	cwd = minienv_value("PWD", minienv);
	if (!cwd)
		cwd = "/UNKNOWN";
	directory = ft_strrchr(cwd, '/') + 1;
	if (ft_strncmp(cwd, "/", 2) == 0)
		directory = "ROOT";
	ft_bzero(prompt, sizeof(prompt));
	ft_strlcat(prompt, BLE, PATH_MAX);
	ft_strlcat(prompt, ">--|^_^|-->", PATH_MAX);
	ft_strlcat(prompt, RED, PATH_MAX);
	ft_strlcat(prompt, directory, PATH_MAX);
	ft_strlcat(prompt, BLE, PATH_MAX);
	ft_strlcat(prompt, ">--|^_^|-->", PATH_MAX);
	ft_strlcat(prompt, CRESET, PATH_MAX);
	return (prompt);
}

char	*prompt_input(t_env *minienv)
{
	char	*input;

	input = readline(get_prompt_str(minienv));
	if (!input)
		builtin_exit(NULL, &minienv);
	if (input && *input)
		add_history(input);
	return (input);
}
