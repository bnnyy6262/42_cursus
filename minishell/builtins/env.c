/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medalgic <medalgic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 03:59:27 by medalgic          #+#    #+#             */
/*   Updated: 2023/12/05 03:59:28 by medalgic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env(t_env *minienv)
{
	t_env	*aux;

	aux = minienv;
	while (aux)
	{
		if (ft_strchr(aux->key_pair, '='))
		{
			ft_putstr_fd(aux->key_pair, STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
		aux = aux->next;
	}
	return (0);
}
