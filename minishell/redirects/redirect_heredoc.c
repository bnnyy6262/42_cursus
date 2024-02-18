/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medalgic <medalgic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 03:56:43 by medalgic          #+#    #+#             */
/*   Updated: 2023/12/05 03:56:45 by medalgic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*tmp_filename(int heredoc_number)
{
	char	filename[30];
	char	*number_str;

	ft_bzero(filename, 30);
	number_str = ft_itoa(heredoc_number);
	ft_strlcat(filename, "/tmp/heredoc", 30);
	ft_strlcat(filename, number_str, 30);
	free(number_str);
	number_str = NULL;
	return (ft_strdup(filename));
}

void	redirect_heredoc(char *command, int heredoc_number)
{
	char	*filename;
	int		tmp_file_fd;
	char	*heredoc_position;

	filename = tmp_filename(heredoc_number);
	tmp_file_fd = open(filename, O_RDONLY);
	if (tmp_file_fd == -1)
	{
		print_perror_msg("open", filename);
		free(filename);
		filename = NULL;
		return ;
	}
	free(filename);
	filename = NULL;
	redirect_fd(tmp_file_fd, STDIN_FILENO);
	heredoc_position = get_redirect_position(command, heredoc_number);
	move_one_forward(heredoc_position);
}
