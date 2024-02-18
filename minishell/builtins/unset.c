/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medalgic <medalgic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 03:59:42 by medalgic          #+#    #+#             */
/*   Updated: 2023/12/05 03:59:43 by medalgic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_from_minienv(char *varname, t_env **minienv);
static void	minienv_del_next_node(t_env **node);

int	unset(char **args, t_env **minienv)
{
	char	*varname;
	int		exit_status;

	args++;
	exit_status = EXIT_SUCCESS;
	if (!*args)
		return (0);
	while (*args)
	{
		varname = *args;
		if (!is_valid_varname(varname))
		{
			print_varname_error_msg("unset", varname);
			exit_status = EXIT_FAILURE;
		}
		else
			remove_from_minienv(varname, minienv);
		args++;
	}
	return (exit_status);
}

static void	remove_from_minienv(char *varname, t_env **minienv)
{
	t_env	*aux;

	aux = *minienv;
	while (aux && aux->next)
	{
		if (ft_strncmp((aux->next)->key_pair, varname, ft_strlen(varname)) == 0)
		{
			if ((aux->next)->key_pair[ft_strlen(varname)] == '=')
				return (minienv_del_next_node(&aux));
		}
		aux = aux->next;
	}
}

static void	minienv_del_next_node(t_env **node)
{
	t_env	*temp;

	temp = (*node)->next;
	(*node)->next = ((*node)->next)->next;
	free(temp->key_pair);
	temp->key_pair = NULL;
	free(temp);
	temp = NULL;
}
