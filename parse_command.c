/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 18:06:35 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/14 19:57:33 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_all_double_quotes_matched(char *cmd)
{
	size_t count;

	count = 0;
	while (*cmd)
		if (*cmd++ == '"')
			count++;
	if (count % 2)
		return (0);
	else
		return (1);
}

char		**parse_command(char *cmd)
{
	t_vector	*tokens;
	char		**args;

	if (!is_all_double_quotes_matched(cmd))
	{
		print_error("minishell", NULL, E_UNMATCHED_DBL_QT);
		return (NULL);
	}
	tokens = tokenize_cmd(cmd);
	expand_variables(tokens);
	expand_tilde(tokens);
	args = extract_args(tokens);
	vector_free(tokens);
	if (args[0] == NULL)
		ft_memdel((void **)&args);
	return (args);
}
