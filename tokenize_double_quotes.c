/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_double_quotes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 19:49:43 by mel-idri          #+#    #+#             */
/*   Updated: 2020/06/18 01:04:33 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenize_double_quotes(char **cmd, t_vector *tokens)
{
	char	*start;
	char	*end;
	char	*content;

	vector_push(tokens, (t_token[1]){{DBL_QT_START, NULL}});
	(*cmd)++;
	while (1)
	{
		start = *cmd;
		while ((end = skip_until_chars(start, "\"$")) && *end == '$' &&
				!is_var(end))
			start = end + 1;
		if (*cmd != end)
		{
			content = ft_strndup(*cmd, end - *cmd);
			vector_push(tokens, (t_token[1]){{STRING, content}});
		}
		*cmd = end;
		if (**cmd == '$')
			tokenize_variable(cmd, tokens);
		else if (**cmd == '"')
			break ;
	}
	vector_push(tokens, (t_token[1]){{DBL_QT_END, NULL}});
	(*cmd)++;
}