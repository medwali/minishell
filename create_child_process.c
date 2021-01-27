/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_child_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 23:51:26 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/27 19:51:14 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_child_process(char *exe_path, char **argv, char **envp)
{
	pid_t	pid;

	signal(SIGINT, SIG_IGN);
	if ((pid = fork()) == 0)
	{
		signal(SIGINT, SIG_DFL);
		if (execve(exe_path, argv, envp) == -1)
			print_error("minishell: execve", NULL, E_EXECVE_FAILED);
		exit(1);
	}
	else if (pid == -1)
		print_error("minishell: fork", NULL, E_FORK_FAILED);
	else
		wait(NULL);
	signal(SIGINT, sigint_handler);
}
