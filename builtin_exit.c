/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 07:48:10 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/24 11:33:38 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_exit(char **args)
{
	int argc;

	argc = 0;
	while (argc < 2 && args[argc])
		argc++;
	if (argc == 0)
		exit(0);
	else if (argc == 1)
		exit((unsigned char)ft_atoi(args[0]));
	print_error("minishell: exit", NULL, E_TOO_MANY_ARGS);
}
