/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tilde.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 20:55:49 by mel-idri          #+#    #+#             */
/*   Updated: 2020/06/23 16:00:15 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_tilde(t_vector *tokens)
{
	t_token	*tokens_array;
	size_t	i;
	char	*var_value;

	i = 0;
	var_value = get_env_value("HOME");
	var_value = var_value ? var_value : ft_strdup("");
	tokens_array = (t_token*)tokens->array;
	while (i < tokens->length)
	{
		if (tokens_array[i].type == TILDE)
		{
			tokens_array[i].content = ft_strdup(var_value);
			tokens_array[i].type = STRING;
		}
		i++;
	}
	free(var_value);
}