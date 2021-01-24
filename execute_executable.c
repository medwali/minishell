/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_executable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 16:02:20 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/21 08:15:29 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_path_state	find_exe_path(char **path_array, char *exe_name,
	char **path)
{
	char			*tmp_path;
	size_t			i;
	t_path_state	path_state;

	i = 0;
	path_state = NO_PATH;
	while (path_array[i] && path_state != EXECUTABLE)
	{
		tmp_path = ft_strglue(path_array[i], '/', exe_name);
		if (access(tmp_path, X_OK) == 0)
		{
			path_state = EXECUTABLE;
			free(*path);
			*path = ft_strdup(tmp_path);
		}
		else if (path_state != NOT_EXECUTABLE && access(tmp_path, F_OK) == 0)
		{
			path_state = NOT_EXECUTABLE;
			*path = ft_strdup(tmp_path);
		}
		free(tmp_path);
		i++;
	}
	return (path_state);
}

static t_path_state	get_executable_path(char *exe_name, char **path,
		char **envp)
{
	char			*path_env_var;
	char			**path_array;
	t_path_state	path_state;

	if ((path_env_var = get_env_value(envp, "PATH")) == NULL)
		return (NO_PATH);
	path_array = ft_strsplit(path_env_var, ':', ALLOW_EMPTY_WORD);
	path_state = find_exe_path(path_array, exe_name, path);
	free(path_env_var);
	ft_free_2d_chr_array(path_array);
	return (path_state);
}

void				execute_executable(char **argv, char **envp)
{
	t_path_state	path_state;
	char			*exe_path;
	int				is_path;

	exe_path = NULL;
	path_state = 0;
	is_path = ft_strchr(argv[0], '/') != NULL;
	if (is_path)
		exe_path = argv[0];
	else
		path_state = get_executable_path(argv[0], &exe_path, envp);
	if (is_path && access(exe_path, F_OK) != 0)
		print_error("minishell", exe_path, E_FILE_NOT_FOUND);
	else if (!is_path && path_state == NO_PATH)
		print_error("minishell", argv[0], E_CMD_NOT_FOUND);
	else if ((is_path && access(exe_path, X_OK) != 0) ||
			path_state == NOT_EXECUTABLE)
		print_error("minishell", exe_path, E_PERM_DENIED);
	else
		create_child_process(exe_path, argv, envp);
	if (exe_path != argv[0])
		free(exe_path);
}
