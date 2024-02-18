/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssakarya <ssakarya@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 03:57:51 by medalgic          #+#    #+#             */
/*   Updated: 2024/01/08 17:10:36 by ssakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minienv.h"

int		is_builtin(char *command);
int		cd(char **args, t_env *minienv);
int		echo(char **args);
int		pwd(void);
int		builtin_export(char **args, t_env **minienv);
void	keypair_if_any(char *key_pair, t_env **minienv);
int		env(t_env *envp);
int		unset(char **args, t_env **minienv);
int		builtin_exit(char **args, t_env **minienv);

int		is_varname(char c);
int		is_valid_varname(char *name);

#endif
