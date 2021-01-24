/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 02:34:50 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/24 12:06:23 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_executable_dir(char *dir)
{
	struct stat st;

	if (stat(dir, &st) == -1)
	{
		print_error("minishell: cd", NULL, E_FILE_NOT_FOUND);
		return (0);
	}
	if (!S_ISDIR(st.st_mode))
	{
		print_error("minishell: cd", dir, E_NOT_A_DIR);
		return (0);
	}
	if (access(dir, X_OK) == -1)
	{
		print_error("minishell: cd", dir, E_PERM_DENIED);
		return (0);
	}
	return (1);
}

static void	change_directory(char *dir)
{
	char	*cwd;

	cwd = get_env_value(NULL, "PWD");
	if (cwd == NULL)
		cwd = getcwd(NULL, 0);
	if (chdir(dir) == -1)
	{
		print_error("minishell: cd", NULL, E_CANT_CHDIR);
		free(cwd);
		return ;
	}
	if (cwd)
		set_env_item(*env_vec(), "OLDPWD", cwd);
	else
		set_env_item(*env_vec(), "OLDPWD", "");
	set_env_item(*env_vec(), "PWD", dir);
	free(cwd);
}

void		builtin_cd(char **args)
{
	size_t	argc;
	char	*dir;

	argc = 0;
	dir = NULL;
	while (args[argc])
		argc++;
	if (argc > 1)
		return ((void)print_error("minishell: cd", NULL, E_TOO_MANY_ARGS));
	else if (argc == 0 && (dir = get_env_value(NULL, "HOME")) == NULL)
		return ((void)ft_putendl_fd("minishell: cd: HOME not set", 2));
	else if (argc == 1)
	{
		if (args[0][0] == '\0')
			return ;
		dir = ft_strequ(args[0], "-") ? get_env_value(NULL, "OLDPWD") :
			ft_strdup(args[0]);
		if (dir == NULL)
			return ((void)ft_putendl_fd("minishell: cd: OLDPWD not set", 2));
	}
	if (is_executable_dir(dir))
		change_directory(dir);
	free(dir);
}
