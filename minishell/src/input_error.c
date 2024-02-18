/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medalgic <medalgic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 03:56:03 by medalgic          #+#    #+#             */
/*   Updated: 2023/12/05 03:56:05 by medalgic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_input_error(char *input, int *exit_status, t_env *minienv)
{
	int	result;

	result = FALSE;
	if (is_empty(input))
		result = TRUE;
	else if (has_unclosed_quotes(input))
		result = TRUE;
	else if (is_invalid_syntax(input))
	{
		*exit_status = 2;
		result = TRUE;
	}
	else if (handle_heredoc(input, exit_status, minienv) == FAILED)
		result = TRUE;
	if (result == TRUE)
	{
		free(input);
		input = NULL;
	}
	return (result);
}
