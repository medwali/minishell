/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 20:42:17 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/28 09:59:57 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_builtin(char **argv)
{
	char	*builtin_cmd;

	builtin_cmd = argv[0];
	if (ft_strequ(builtin_cmd, "exit"))
		builtin_exit(argv + 1);
	else if (ft_strequ(builtin_cmd, "echo"))
		builtin_echo(argv + 1);
	else if (ft_strequ(builtin_cmd, "cd"))
		builtin_cd(argv + 1);
	else if (ft_strequ(builtin_cmd, "env"))
		builtin_env(argv + 1);
	else if (ft_strequ(builtin_cmd, "setenv"))
		builtin_setenv(argv + 1);
	else if (ft_strequ(builtin_cmd, "unsetenv"))
		builtin_unsetenv(argv + 1);
	else if (ft_strequ(builtin_cmd, "pwd"))
		builtin_pwd();
	else
		return (BUILTIN_NOT_FOUND);
	return (BUILTIN_EXECUTED);
}
