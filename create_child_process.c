/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_child_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 23:51:26 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/14 19:52:30 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_child_process(char *exe_path, char **argv, char **envp)
{
	pid_t	pid;

	if ((pid = fork()) == 0)
	{
		if (execve(exe_path, argv, envp) == -1)
			print_error("minishell: execve", NULL, E_EXECVE_FAILED);
		exit(1);
	}
	else if (pid == -1)
		print_error("minishell: fork", NULL, E_FORK_FAILED);
	else
		wait(NULL);
}
