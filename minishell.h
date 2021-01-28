/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 09:56:25 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/28 09:59:10 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include "libft/libft.h"
# include "minishell_typedefs.h"
# define BUILTIN_EXECUTED 0
# define BUILTIN_NOT_FOUND 1
# define ALPHA "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define DIGITS "0123456789"
# define E_TOO_MANY_ARGS 0
# define E_FILE_NOT_FOUND 1
# define E_NOT_A_DIR 2
# define E_PERM_DENIED 3
# define E_CANT_GETCWD 4
# define E_CANT_CHDIR 5
# define E_CMD_NOT_FOUND 6
# define E_EXECVE_FAILED 7
# define E_FORK_FAILED 8
# define E_UNMATCHED_DBL_QT 9
# define E_STDIN_ERROR 10
# define E_INVALID_ARG 11
# define E_VAR_ALNUM 12

extern int	g_is_interrupted;
char		*read_command(int *ret);
int			is_var(char *str);
int			is_tilde(char *cmd, t_vector *tokens);
void		expand_variables(t_vector *tokens);
void		expand_tilde(t_vector *tokens);
t_vector	*tokenize_cmd(char *cmd);
void		tokenize_variable(char **cmd, t_vector *tokens);
void		tokenize_string(char **cmd, t_vector *tokens);
void		tokenize_double_quotes(char **cmd, t_vector *tokens);
char		**parse_command(char *cmd);
char		**extract_args(t_vector *tokens);
t_vector	**env_vec(void);
t_vector	*create_env_vector(char **envp);
char		**find_env_item(char **envp, char *env_var);
int			is_env_var_matched(char *env_var, char *env_item);
void		print_all_env_items(t_vector *env_vec);
void		unset_env_item(char *env_var);
void		set_env_item(t_vector *env_vec, char *env_var, char *env_value);
char		*get_env_value(char **envp, char *env_var);
int			execute_builtin(char **args);
void		execute_executable(char **args, char **envp);
void		builtin_cd(char **argv);
void		builtin_echo(char **argv);
void		builtin_exit(char **argv);
void		builtin_env(char **argv);
void		builtin_setenv(char **argv);
void		builtin_unsetenv(char **argv);
void		builtin_pwd(void);
void		create_child_process(char *exe_path, char **argv, char **envp);
void		print_error(char *prefix, char *var, int error_num);
void		sigint_handler(int signum);

#endif
