/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 14:25:34 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/27 18:42:07 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_command(char *cache, int is_eof, char *newline)
{
	char	*ret;

	ret = NULL;
	if (newline)
		ret = ft_strsub(cache, 0, newline - cache);
	else if (is_eof && cache && *cache)
		ret = ft_strdup(cache);
	return (ret);
}

static void	update_cache(char **cache, int is_eof, char *newline)
{
	char	*tmp;

	if (newline)
	{
		tmp = *cache;
		if (newline[1] == 0)
			*cache = NULL;
		else
			*cache = ft_strdup(newline + 1);
		free(tmp);
	}
	else if (is_eof && *cache && **cache)
		ft_strdel(cache);
}

char		*read_command(int *ret)
{
	static char	*cache;
	char		buf[BUFF_SIZE + 1];
	ssize_t		read_size;
	char		*newline;
	char		*command;

	read_size = 0;
	*ret = 0;
	while (!(newline = ft_strchr(cache, '\n')) &&
		(read_size = read(0, buf, BUFF_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		cache = ft_strjoin_free(cache ? cache : ft_strdup(""), buf, 1, 0);
	}
	if (read_size == -1)
	{
		*ret = -1;
		print_error("minishell: read_command", NULL, E_STDIN_ERROR);
		return (NULL);
	}
	command = get_command(cache, read_size == 0, newline);
	update_cache(&cache, read_size == 0, newline);
	if (g_is_interrupted)
		ft_strdel(&command);
	return (command);
}
