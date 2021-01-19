/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 13:06:16 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/19 12:33:46 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_args(t_token *tokens, size_t tokens_count, t_vector *args)
{
	size_t	i;
	char	*arg;

	i = 0;
	arg = NULL;
	while (i < tokens_count)
	{
		if (tokens[i].type == DBL_QT_START ||
					(tokens[i].type == STRING && tokens[i].content[0] != 0))
		{
			arg = arg == NULL ? ft_strdup("") : arg;
			if (tokens[i].type == STRING)
				arg = ft_strjoin_free(arg, tokens[i].content, 1, 0);
		}
		else if ((tokens[i].type == SEPARATOR || tokens[i].type == CMD_END) &&
					arg)
		{
			vector_push(args, &arg);
			arg = NULL;
		}
		i++;
	}
}

char		**extract_args(t_vector *tokens)
{
	t_vector	*args;
	char		**args_array;
	t_token		*tokens_array;

	args = vector_init(sizeof(char*), NULL);
	tokens_array = (t_token*)tokens->array;
	get_args(tokens_array, tokens->length, args);
	vector_push(args, (char*[1]){NULL});
	args_array = (char**)args->array;
	free(args);
	return (args_array);
}
