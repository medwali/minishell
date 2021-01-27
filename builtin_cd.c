/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 02:34:50 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/27 18:32:23 by mel-idri         ###   ########.fr       */
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
		print_error("minishell: cd", ft_strdup(dir), E_NOT_A_DIR);
		return (0);
	}
	if (access(dir, X_OK) == -1)
	{
		print_error("minishell: cd", ft_strdup(dir), E_PERM_DENIED);
		return (0);
	}
	return (1);
}

static void	change_directory(char *dir, int is_oldpwd)
{
	char	*oldpwd;
	char	*cwd;

	cwd = NULL;
	oldpwd = getcwd(NULL, 0);
	if ((chdir(dir)) == -1)
	{
		print_error("minishell: cd", NULL, E_CANT_CHDIR);
		free(oldpwd);
		return ;
	}
	if (oldpwd)
		set_env_item(*env_vec(), "OLDPWD", oldpwd);
	if ((cwd = getcwd(NULL, 0)) != NULL)
	{
		set_env_item(*env_vec(), "PWD", cwd);
		if (is_oldpwd)
			ft_putendl(cwd);
	}
	else
		print_error("minishell: cd", NULL, E_CANT_GETCWD);
	free(cwd);
	free(oldpwd);
}

static char	*get_dir(char **args)
{
	size_t	argc;
	char	*dir;

	argc = 0;
	dir = NULL;
	while (argc < 2 && args[argc])
		argc++;
	if (argc > 1)
		print_error("minishell: cd", NULL, E_TOO_MANY_ARGS);
	else if (argc == 0 && (dir = get_env_value(NULL, "HOME")) == NULL)
		ft_putendl_fd("minishell: cd: HOME not set", 2);
	else if (argc == 1)
	{
		if (ft_strequ(args[0], "-") && 
				(dir = get_env_value(NULL, "OLDPWD")) == NULL)
			ft_putendl_fd("minishell: cd: OLDPWD not set", 2);
		else if (!ft_strequ(args[0], "") && dir == NULL)
			dir = ft_strdup(args[0]);
	}
	return (dir);
}

void		builtin_cd(char **args)
{
	char	*dir;

	if ((dir = get_dir(args)) != NULL && is_executable_dir(dir))
		change_directory(dir, ft_strequ(args[0], "-"));
	free(dir);
}
