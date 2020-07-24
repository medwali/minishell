/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_typedefs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 16:17:45 by mel-idri          #+#    #+#             */
/*   Updated: 2020/07/08 13:37:16 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TYPEDEFS_H
# define MINISHELL_TYPEDEFS_H

typedef enum		e_token_type
{
					STRING,
					SEPARATOR,
					VARIABLE,
					CMD_START,
					CMD_END,
					DBL_QT_START,
					DBL_QT_END,
					TILDE
}					t_token_type;

typedef struct		s_token
{
	t_token_type	type;
	char 			*content;
}					t_token;
typedef enum		e_path_state
{
					NO_PATH,
					NOT_EXECUTABLE,
					EXECUTABLE
}					t_path_state;

#endif
