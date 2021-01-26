/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 02:34:50 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/26 09:25:44 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_valid_env_var(char *env_var)
{
	if (!ft_isalpha(*env_var) || *env_var != '_')
		return (0);
	env_var++;
	while (*env_var)
	{
		if (!ft_isalnum(*env_var) || *env_var != '_')
			return (0);
		env_var++;
	}
	return (1);
}

void	builtin_setenv(char **args)
{
	size_t	argc;

	argc = 0;
	while (argc < 3 && args[argc])
		argc++;
	if (argc == 0)
		print_all_env_items(*env_vec());
	if (argc == 1 || argc == 2)
	{
		if (!is_valid_env_var(args[0]))
		{
			print_error("minishell: setenv", NULL, E_VAR_ALNUM);
			return ;
		}
		if (argc == 1)
			set_env_item(*env_vec(), args[0], "");
		else if (argc == 2)
			set_env_item(*env_vec(), args[0], args[1]);
	}
	if (argc > 2)
		print_error("minishell: setenv", NULL, E_TOO_MANY_ARGS);
}
