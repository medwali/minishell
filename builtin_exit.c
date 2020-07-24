/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 07:48:10 by mel-idri          #+#    #+#             */
/*   Updated: 2020/07/08 16:47:23 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_exit(char **args)
{
	if (args[0] == NULL)
		exit(0);
	else if (args[0] && args[1] == NULL)
		exit((unsigned char)ft_atoi(args[0]));
	print_error("minishell: exit", NULL, E_TOO_MANY_ARGS);
}