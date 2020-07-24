/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 02:23:22 by mel-idri          #+#    #+#             */
/*   Updated: 2020/06/23 16:02:54 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			expand_var_to_str(t_token *var_token)
{
	char	*value;

	value = get_env_value(var_token->content);
	free(var_token->content);
	var_token->content = value ? value : ft_strdup("");
	var_token->type = STRING;
}

static t_vector	*get_sub_tokens(char *val)
{
	char 		*start;
	char 		*end;
	char		*content;
	t_vector	*sub_tokens;

	sub_tokens = vector_init(sizeof(t_token), NULL);
	start = val;
	while (*start)
	{
		if (*start == ' ' || *start == '\t')
		{
			vector_push(sub_tokens, (t_token[1]){{SEPARATOR, NULL}});
			start = skip_chars(start, " \t");
		}
		else
		{
			end = skip_until_chars(start, " \t");
			content = ft_strndup(start, end - start);
			vector_push(sub_tokens, (t_token[1]){{STRING, content}});
			start = end;
		}
	}
	return (sub_tokens);
}

static void		expand_var_to_tokens(t_vector *tokens, size_t var_index)
{
	t_token		*var_token;
	char		*value;
	t_vector	*sub_tokens;

	var_token = ((t_token*)tokens->array) + var_index;
	value = get_env_value(var_token->content);
	sub_tokens = get_sub_tokens(value ? value : "");
	vector_remove(tokens, var_index);
	vector_insert_all(tokens, sub_tokens, var_index);
	vector_free(sub_tokens);
	free(value);
}

void			expand_variables(t_vector *tokens)
{
	size_t	i;
	t_token	*tokens_array;
	int		is_in_double_quote;

	i = 0;
	tokens_array = (t_token*)tokens->array;
	is_in_double_quote = 0;
	while (i < tokens->length)
	{
		if (tokens_array[i].type == DBL_QT_START)
			is_in_double_quote = 1;
		else if (tokens_array[i].type == DBL_QT_END)
			is_in_double_quote = 0;
		else if (tokens_array[i].type == VARIABLE)
		{
			if (is_in_double_quote)
				expand_var_to_str(tokens_array + i);
			else
				expand_var_to_tokens(tokens, i);
		}
		i++;
	}
}