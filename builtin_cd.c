/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 02:34:50 by mel-idri          #+#    #+#             */
/*   Updated: 2020/07/14 15:01:22 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
static int	is_executable_dir(char *dir)
{
	struct stat st;

	if (stat(dir, &st) == -1)
	{
		print_error("minishell: cd", NULL ,E_FILE_NOT_FOUND);
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
	char	cwd[MAXPATHLEN + 1];
	char	*oldpwd;

	if (chdir(dir) == -1)
	{
		print_error("minishell: cd", NULL, E_CANT_CHDIR);
		return ;
	}
	oldpwd = get_env_value("PWD");
	if (oldpwd)
		set_env_item(*env_vec(), "OLDPWD", oldpwd);
	else
		set_env_item(*env_vec(), "OLDPWD", "");
	if (getcwd(cwd, MAXPATHLEN + 1) == NULL)
		set_env_item(*env_vec() ,"PWD", "");
	else
		set_env_item(*env_vec() ,"PWD", cwd);		
}

void		builtin_cd(char **args)
{
	size_t	argc;
	char 	*dir;

	argc = 0;
	dir = NULL;
	while (args[argc])
		argc++;
	if (argc > 1)
		return ((void)print_error("minishell: cd", NULL, E_TOO_MANY_ARGS));
	else if (argc == 0 && (dir = get_env_value("HOME")) == NULL)
		return ((void)ft_putendl_fd("minishell: cd: HOME not set", 2));
	else if (argc == 1)
	{
		if (args[0][0] == '\0')
			return ;
		else if (ft_strequ(args[0], "-") &&
				(dir = get_env_value("OLDPWD")) == NULL)
			return ((void)ft_putendl_fd("minishell: cd: OLDPWD not set", 2));
		else
			dir = ft_strdup(args[0]);
	}
	if (!is_executable_dir(dir))
		return ;
	change_directory(dir);
	free(dir);
}