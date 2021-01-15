/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 14:25:34 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/14 19:55:53 by mel-idri         ###   ########.fr       */
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

static int	update_cache(char **cache, int is_eof, char *newline)
{
	char	*tmp;

	if (newline)
	{
		tmp = *cache;
		*cache = ft_strdup(newline + 1);
		free(tmp);
	}
	else if (is_eof && *cache && **cache)
		ft_strdel(cache);
	return (0);
}

char		*read_command(void)
{
	static char	*cache;
	char		buf[BUFF_SIZE + 1];
	ssize_t		read_size;
	char		*newline;
	char		*command;

	read_size = 0;
	while (!(newline = ft_strchr(cache, '\n')) &&
		(read_size = read(0, buf, BUFF_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		cache = ft_strjoin_free(cache ? cache : ft_strdup(""), buf, 1, 0);
	}
	if (read_size == -1
			|| (command = get_command(cache, read_size == 0, newline)) == NULL)
		return (NULL);
	if (update_cache(&cache, read_size == 0, newline) == -1)
	{
		free(command);
		return (NULL);
	}
	return (command);
}
