/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 00:17:40 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/24 09:03:59 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			is_env_var_matched(char *env_var, char *env_item)
{
	size_t	i;

	i = 0;
	while (env_var[i])
	{
		if (env_var[i] != env_item[i])
			return (0);
		i++;
	}
	if (env_item[i] != '=')
		return (0);
	return (1);
}

t_vector	*create_env_vector(char **envp)
{
	t_vector	*env_vec;
	char		*env_item;

	env_vec = vector_init(sizeof(char*), ft_free_ptr);
	while (*envp)
	{
		env_item = ft_strdup(*envp);
		vector_push(env_vec, &env_item);
		envp++;
	}
	vector_push(env_vec, (char*[1]){NULL});
	return (env_vec);
}

t_vector	**env_vec(void)
{
	static t_vector	*env_vec;

	return (&env_vec);
}

char		**find_env_item(char **envp, char *env_var)
{
	size_t		i;

	if (envp == NULL)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		if (is_env_var_matched(env_var, envp[i]))
			return (envp + i);
		i++;
	}
	return (NULL);
}

void		print_all_env_items(t_vector *env_vec)
{
	char	**env_items;

	env_items = (char**)env_vec->array;
	while (*env_items)
		ft_putendl_fd(*env_items++, 1);
}
