/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 23:59:48 by mel-idri          #+#    #+#             */
/*   Updated: 2020/07/11 14:15:02 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_env_item(char *env_var)
{
	t_vector	*env_vector;
	char		**env_items;
	size_t		i;

	i = 0;
	env_vector = *env_vec();
	env_items = env_vector->array;
	while (env_items[i])
	{
		if (is_env_var_matched(env_var, env_items[i]))
		{
			vector_remove(env_vector, i);
			return ;
		}
		i++;
	}
}

void	set_env_item(t_vector *env_vec, char* env_var, char *env_value)
{
	char	*new_env_item;
	char	**old_env_item;

	new_env_item = ft_strglue(env_var, '=', env_value);
	if ((old_env_item = find_env_item(env_vec, env_var)) != NULL)
	{
		free(*old_env_item);
		*old_env_item = new_env_item;
	}
	else
		vector_insert(env_vec, &new_env_item,
			env_vec->length > 0 ? env_vec->length - 1 : 0);
}

char	*get_env_value(char *env_var)
{
	char	**env_item;
	char	*env_value;

	if ((env_item = find_env_item(*env_vec(), env_var)) != NULL)
	{
		env_value = skip_until_chars(*env_item, "=") + 1;
		return (ft_strdup(env_value));
	}
	else
		return (NULL);
}