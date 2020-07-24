/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 02:34:49 by mel-idri          #+#    #+#             */
/*   Updated: 2020/07/10 00:02:01 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		builtin_env(char **args)
{
	char		*equal_sign;
	size_t		i;
	t_vector	*tmp_env_vec;

	tmp_env_vec = create_env_vector((*env_vec())->array);
	i = 0;
	while ((equal_sign = ft_strchr(args[i], '=')))
	{
		*equal_sign = '\0';
		set_env_item(tmp_env_vec, args[i], equal_sign + 1);
		i++;
	}
	if (args[i])
		execute_executable(args + i, (char**)tmp_env_vec->array);
	else
		print_all_env_items(tmp_env_vec);
	vector_free(tmp_env_vec);
}