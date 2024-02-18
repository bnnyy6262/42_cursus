/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medalgic <medalgic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 03:59:34 by medalgic          #+#    #+#             */
/*   Updated: 2023/12/05 03:59:36 by medalgic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	declare_env(t_env *minienv)
{
	t_env	*aux;
	char	*tmp;

	aux = minienv;
	while (aux)
	{
		tmp = name_only(aux->key_pair);
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(tmp, STDOUT_FILENO);
		if (ft_strchr(aux->key_pair, '='))
		{
			ft_putstr_fd("=", STDOUT_FILENO);
			ft_putstr_fd("\"", STDOUT_FILENO);
			ft_putstr_fd(value_only(aux->key_pair), STDOUT_FILENO);
			ft_putstr_fd("\"", STDOUT_FILENO);
		}
		ft_putstr_fd("\n", STDOUT_FILENO);
		aux = aux->next;
		free(tmp);
	}
	return (0);
}

int	minienv_node_return(char *name, t_env *minienv)
{
	t_env	*aux;
	int		size;

	aux = minienv;
	size = ft_strlen(name);
	while (aux)
	{
		if (ft_strncmp(name, aux->key_pair, size) == 0)
			return (0);
		aux = aux->next;
	}
	return (1);
}

void	keypair_if_any(char *key_pair, t_env **minienv)
{
	if (list_append(key_pair, minienv))
		free_minienv(minienv);
}

int	builtin_export(char **args, t_env **minienv)
{
	char	*key_pair;
	char	*varname;
	int		exit_status;

	args++;
	exit_status = EXIT_SUCCESS;
	if (!*args)
		return (declare_env(*minienv));
	while (*args)
	{
		key_pair = *args;
		varname = name_only(key_pair);
		if (!is_valid_varname(varname) || str_equal(key_pair, "="))
		{
			print_varname_error_msg("export", key_pair);
			exit_status = EXIT_FAILURE;
		}
		else if (minienv_node(varname, *minienv))
			minienv_update(varname, value_only(key_pair), *minienv);
		else if (minienv_node_return(varname, *minienv))
			keypair_if_any(key_pair, minienv);
		free_and_null(varname);
		args++;
	}
	return (exit_status);
}
