/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 22:08:29 by mel-idri          #+#    #+#             */
/*   Updated: 2020/07/24 23:47:32 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenize_string(char **cmd, t_vector *tokens)
{
	char	*start;
	char	*end;
	t_token	str_token;

	start = *cmd;
	while (1)
	{
		end = skip_until_chars(start, "~$\" \t");
		start = end + 1;
		if ((*end == '$' && !is_var(end)) || (*end == '~' &&
				!is_tilde(end, tokens)))
			continue ;
		break ;
	}
	str_token.content = ft_strndup(*cmd, end - *cmd);
	str_token.type = STRING;
	vector_push(tokens, &str_token);
	*cmd = end;
}