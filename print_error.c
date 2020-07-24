/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:59:10 by mel-idri          #+#    #+#             */
/*   Updated: 2020/07/09 22:19:35 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(char *prefix, char *var, int error_num)
{
	const char *error_msgs[10] = {"too many arguments",
	"No such file or directory", "Not a directory", "Permission denied",
	"can't get current working directory", "can't change working directory",
	"command not found", "execve failed", "fork failed",
	"Unmatched double-quote"};

	if (prefix)
	{
		ft_putstr_fd(prefix, 2);
		ft_putstr_fd(": ", 2);
	}
	if (var)
	{
		ft_putstr_fd(var, 2);
		ft_putstr_fd(": ", 2);
	}
	if (0 <= error_num && error_num < 10)
		ft_putstr_fd(error_msgs[error_num], 2);
	ft_putchar_fd('\n', 2);
}