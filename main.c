/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 09:14:53 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/27 18:46:04 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			g_is_interrupted;

static void	shell_loop(void)
{
	char		*command;
	char		**args;
	int			ret;

	while (1)
	{
		g_is_interrupted = 0;
		ft_putstr_fd("$> ", 1);
		if ((command = read_command(&ret)) == NULL && ret == 0 &&
				!g_is_interrupted)
		{
			ft_putendl("exit");
			exit(0);
		}
		if (command == NULL)
			continue ;
		args = parse_command(command);
		ft_strdel(&command);
		if (args == NULL)
			continue ;
		if (execute_builtin(args) == BUILTIN_NOT_FOUND)
			execute_executable(args, (*env_vec())->array);
		ft_free_2d_chr_array(args);
	}
}

int			main(int argc, char **argv, char **envp)
{
	t_vector	*env_vector;

	(void)argv[argc];
	env_vector = create_env_vector(envp);
	*env_vec() = env_vector;
	signal(SIGINT, sigint_handler);
	shell_loop();
	return (0);
}
