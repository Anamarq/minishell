# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anamarqu <anamarqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 13:07:02 by anamarqu          #+#    #+#              #
#    Updated: 2023/09/30 13:24:27 by anamarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SOURCES = ./array_execve.c\
./ft_check_env_vars.c\
./ft_number_characters.c\
./ft_strnstr.c\
./buildin.c\
./ft_check_exist_var.c\
./ft_open_pipe.c\
./ft_unset.c\
./nodes.c\
./check.c\
./ft_copy_2d.c\
./ft_paths_and_heredoc.c\
./get_cmd.c\
./num_pipes.c\
./convert_colons.c\
./ft_env.c\
./ft_pipe_next_to_redirection.c\
./gnl.c\
./path.c\
./count_rows.c\
./ft_exit.c\
./ft_print_entry.c\
./heredoc.c\
./pipes.c\
./echo.c\
./ft_export.c\
./ft_printerror.c\
./itoa.c\
./pipesdef.c\
./expand_var.c\
./ft_free_char_3d.c\
./ft_pwd.c\
./join_array.c\
./redirection.c\
./ft_add_history.c\
./ft_free_cmd_separate.c\
./ft_search_char.c\
./libft1.c\
./reserve_memory.c\
./ft_allocate_array.c\
./ft_ind.c\
./ft_separate.c\
./libft2.c\
./separate_array.c\
./ft_allocate_matrix.c\
./ft_initialize.c\
./ft_str_copy.c\
./map.c\
./separator.c\
./ft_cd.c\
./ft_is_pipe.c\
./ft_straddchar.c\
./signals.c\
./ft_check_chars.c\
./ft_nopip_nobuildin.c\
./ft_strcpy.c\
./minishell.c\
./strcmp.c\


CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SOURCES:.c=.o)

RM = rm -f

READLINE = -lreadline

all: $(NAME)

$(NAME): $(OBJECTS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(READLINE)
clean:
		$(RM) $(OBJECTS)
fclean:	clean
		$(RM) $(NAME)
re:		fclean all

.PHONY: all, clean, fclean, re
