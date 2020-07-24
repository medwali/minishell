/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 09:22:35 by mel-idri          #+#    #+#             */
/*   Updated: 2020/06/18 02:47:10 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void free_token(void *ptr)
{
	t_token *t;

	t = (t_token *)ptr;
	free(t->content);
}

int			is_var(char *str)
{
	return (ft_isalpha(str[1]) || str[1] == '_');
}

int 		is_tilde(char *cmd, t_vector *tokens)
{
	return ((cmd[1] == '/' || cmd[1] == ' ' || cmd[1] == '\t' || cmd[1] == 0) &&
			(((t_token *)tokens->array)[tokens->length - 1].type == SEPARATOR ||
			 ((t_token *)tokens->array)[tokens->length - 1].type == CMD_START));
}

t_vector *tokenize_cmd(char *cmd)
{
	t_vector *tokens;

	tokens = vector_init(sizeof(t_token), free_token);
	vector_push(tokens, (t_token[1]){{CMD_START, NULL}});
	while (*cmd)
	{
		if (*cmd == '"')
			tokenize_double_quotes(&cmd, tokens);
		else if (*cmd == ' ' || *cmd == '\t')
		{
			cmd = skip_chars(cmd, " \t");
			vector_push(tokens, (t_token[1]){{SEPARATOR, NULL}});
		}
		else if (*cmd == '~' && is_tilde(cmd, tokens))
		{
			cmd++;
			vector_push(tokens, (t_token[1]){{TILDE, NULL}});
		}
		else if (*cmd == '$' && is_var(cmd))
			tokenize_variable(&cmd, tokens);
		else
			tokenize_string(&cmd, tokens);
	}
	vector_push(tokens, (t_token[1]){{CMD_END, NULL}});
	return (tokens);
}
