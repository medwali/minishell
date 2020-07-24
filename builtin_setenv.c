/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 02:34:50 by mel-idri          #+#    #+#             */
/*   Updated: 2020/07/08 23:12:59 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		builtin_setenv(char **args)
{
	size_t	argc;

	argc = 0;
	while (args[argc])
		argc++;
	if (argc == 0)
		print_all_env_items(*env_vec());
	else if (argc == 1)
		set_env_item(*env_vec(), args[0], "");
	else if (argc == 2)
		set_env_item(*env_vec(), args[0], args[1]);
	else
		print_error("minishell: setenv", NULL, E_TOO_MANY_ARGS);

}