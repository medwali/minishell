/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 18:34:54 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/14 20:21:34 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenize_variable(char **cmd, t_vector *tokens)
{
	char	*end;
	t_token	var_token;

	(*cmd)++;
	end = skip_chars(*cmd, DIGITS"_"ALPHA);
	var_token.content = ft_strndup(*cmd, end - *cmd);
	var_token.type = VARIABLE;
	vector_push(tokens, &var_token);
	*cmd = end;
}
