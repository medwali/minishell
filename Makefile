# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/28 10:25:34 by mel-idri          #+#    #+#              #
#    Updated: 2020/07/25 00:09:42 by mel-idri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFT = libft/libft.a
MAKEFLAGS += --no-print-directory
CFLAGS = -Wall -Wextra -Werror
CC = gcc
SRCS = builtin_cd.c builtin_echo.c builtin_env.c builtin_exit.c \
	builtin_setenv.c builtin_unsetenv.c create_child_process.c env_item.c \
	env_util.c execute_builtin.c execute_executable.c expand_tilde.c \
	expand_variables.c extract_args.c main.c parse_command.c print_error.c \
	read_command.c tokenize_cmd.c tokenize_double_quotes.c tokenize_string.c \
	tokenize_variable.c
OBJS = $(addprefix  objs/, $(SRCS:.c=.o))
INCLUDES = minishell.h minishell_typedefs.h


all:
	$(MAKE) libft
	$(MAKE) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(MAKE) libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

objs/%.o : %.c | objs
	$(CC) $(CFLAGS) -c $< -o $@ 

$(SRCS) : $(INCLUDES)

libft:
	$(MAKE) -C libft/

objs:
	mkdir objs

clean:
	$(MAKE) -C libft/ clean
	rm -rf objs

fclean: clean
	$(MAKE) -C libft/ fclean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all fclean re clean libft
