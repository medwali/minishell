/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:59:10 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/25 21:43:31 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(char *prefix, char *var, int error_num)
{
	const char *error_msgs[13] = {"too many arguments",
	"No such file or directory", "Not a directory", "Permission denied",
	"can't get current working directory", "can't change working directory",
	"command not found", "execve failed", "fork failed",
	"Unmatched double-quote", "cannot read from stdin", "Invalid argument",
	"Variable name must contain alphanumeric characters"};

	if (prefix)
	{
		ft_putstr_fd(prefix, 2);
		ft_putstr_fd(": ", 2);
	}
	if (var)
	{
		ft_putstr_fd(var, 2);
		ft_putstr_fd(": ", 2);
		free(var);
	}
	if (0 <= error_num && error_num < 13)
		ft_putstr_fd(error_msgs[error_num], 2);
	ft_putchar_fd('\n', 2);
}
