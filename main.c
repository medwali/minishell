/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                     +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 09:14:53 by mel-idri          #+#    #+#             */
/*   Updated: 2020/03/28 21:57:25 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_args(char **args)
{
	int is_first = 1;
	printf("[");
	while (*args)
	{
		if (!is_first)
			printf(", ");
		else
			is_first = 0;
		printf("\"%s\"", *args++);
	}
	printf("]\n");
	return (0);
}

int		main(int argc, char **argv, char **envp)
{
	char		*command;
	char		**args;
	t_vector	*env_vector;

	(void)argc;
	(void)argv;
	env_vector = create_env_vector(envp);
	*env_vec() = env_vector;
	while (1)
	{
		ft_putstr_fd("$> ", 1);
		command = read_command();
		if (command)
			args = parse_command(command);
		if (command == NULL || args == NULL)
			continue ;
		if (execute_builtin(args) == BUILTIN_NOT_FOUND)
			execute_executable(args, envp);
		ft_free_2d_chr_array(args);
	}
	return (0);
}
