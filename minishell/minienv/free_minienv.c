/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_minienv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medalgic <medalgic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 03:57:09 by medalgic          #+#    #+#             */
/*   Updated: 2023/12/05 03:57:11 by medalgic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_minienv(t_env **minienv)
{
	t_env	*aux;
	t_env	*next;

	aux = *minienv;
	while (aux)
	{
		free(aux->key_pair);
		next = aux->next;
		free(aux);
		aux = next;
	}
	*minienv = NULL;
}

void	export_set(char *name, char *value, t_env *aux, char *new_keypair)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(name) + ft_strlen(value) + 2;
	new_keypair = malloc(size * sizeof(char));
	if (!new_keypair)
		return ;
	while (*name)
		new_keypair[i++] = *name++;
	new_keypair[i++] = '=';
	while (*value)
		new_keypair[i++] = *value++;
	new_keypair[i] = '\0';
	aux->key_pair = new_keypair;
}
