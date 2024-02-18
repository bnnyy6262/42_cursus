/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_multiple_commands.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medalgic <medalgic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 03:58:42 by medalgic          #+#    #+#             */
/*   Updated: 2023/12/26 02:41:08 by medalgic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	save_original_fds(int original_fds[2])
{
	original_fds[0] = dup(STDIN_FILENO);
	original_fds[1] = dup(STDOUT_FILENO);
}

static void	handle_redirects(char *command, char **commands, t_env **minienv)
{
	char	redirect;

	redirect = get_next_redirect(command);
	while (redirect)
	{
		if (redirect == '<')
		{
			if (redirect_input(command) == FAILED)
				quit_child(commands, minienv);
		}
		if (redirect == '>')
		{
			if (redirect_output(command) == FAILED)
				quit_child(commands, minienv);
		}
		if (redirect < 0 && redirect > -50)
			redirect_heredoc(command, redirect);
		redirect = get_next_redirect(command);
	}
}

static void	execute_forked_command(char *command, char **commands,
		t_env **minienv)
{
	char	**args;

	close_extra_fds();
	args = split_args(command);
	free_array(commands);
	if (is_builtin(args[0]))
		execute_forked_builtin(args, minienv);
	else
		execute_external(args, *minienv);
}

static void	restore_original_fds(int original_fds[2])
{
	redirect_fd(original_fds[IN], STDIN_FILENO);
	redirect_fd(original_fds[OUT], STDOUT_FILENO);
}

int	execute_multiple_commands(char **commands, t_env **minienv)
{
	int	original_fds[2];
	int	*children_pid;
	int	i;

	save_original_fds(original_fds);
	children_pid = init_children_pid(commands);
	i = 0;
	while (commands[i])
	{
		handle_pipe(original_fds[OUT], commands[i], commands);
		children_pid[i] = fork();
		define_execute_signals(children_pid[i]);
		if (children_pid[i] == -1)
			print_perror_msg("fork", commands[i]);
		else if (children_pid[i] == 0)
		{
			free(children_pid);
			children_pid = NULL;
			handle_redirects(commands[i], commands, minienv);
			execute_forked_command(commands[i], commands, minienv);
		}
		i++;
	}
	restore_original_fds(original_fds);
	return (wait_for_children(children_pid));
}
