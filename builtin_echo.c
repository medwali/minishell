/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 01:12:24 by mel-idri          #+#    #+#             */
/*   Updated: 2020/06/26 19:15:02 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_echo(char **args)
{
	int	is_first;

	is_first = 1;
	while (*args)
	{
		if (is_first)
			is_first = 0;
		else
			ft_putchar_fd(' ', 1);
		ft_putstr_fd(*args++, 1);
	}
	ft_putchar_fd('\n', 1);
}