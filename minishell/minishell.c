/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:03:36 by pespinos          #+#    #+#             */
/*   Updated: 2023/10/14 18:49:36 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_commands2(void)
{
	char	*str_env;

	str_env = ft_check_env_vars();
	if (ft_strcmp2(str_env, "\n") == 0)
	{
		g_data.cmds_separate = ft_split2(str_env, ' ');
		if (get_cmds() > 0)
		{
			if (paths_and_heredoc() > 0)
			{
				if (g_data.npipes > 0)
					pipesdef();
				else
					nopip();
			}
			free_cmdpath();
		}
		free_cmd_separate();
	}
	free(str_env);
}

int	run_commands(void)
{
	char	*str;

	g_data.str_order = ft_separar(g_data.str_order);
	if (g_data.is_com == 0)
	{
		free(g_data.map);
		g_data.map = ft_create_map(ft_strlen(g_data.str_order));
	}
	g_data.length_order = ft_strlen(g_data.str_order);
	pipe_next_to_redirection();
	g_data.npipes = ft_number_pipes(g_data.str_order);
	if (reserve_nodes_memory() == -1)
		return (-1);
	str = ft_convert_colons();
	free(g_data.str_order);
	g_data.str_order = ft_strdup(str);
	free(str);
	initialize();
	run_commands2();
	free_nodes();
	free(g_data.comillas);
	return (1);
}

int	main_loop(void)
{
	open_pipe();
	if ((ft_strcmp2(g_data.str_order, "\n") == 0) && g_data.ctrl_c == 0)
	{
		if (ft_control_d())
			return (-1);
		if (ft_search_char(';') || ft_search_char('\\'))
			return (-1);
		free(g_data.map);
		g_data.map = ft_create_map(ft_strlen(g_data.str_order));
		ft_add_history(g_data.str_order);
		if (ft_check_str())
			print_error(5);
		else
		{
			if (run_commands() < 0)
				return (-1);
		}
	}		
	g_data.ctrl_c = 0;
	free(g_data.str_order);
	g_data.is_com = 0;
	g_data.str_order = ft_print_entry("minishell >> ");
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	g_data.envp = copy_2d(env);
	g_data.execution_estatus = 0;
	g_data.is_com = 0;
	g_data.dim_env = ft_count_rows_2d(g_data.envp);
	ft_init_signals();
	g_data.str_order = ft_print_entry("minishell >> ");
	while (g_data.str_order != NULL)
	{
		if (main_loop() < 0)
			return (-1);
	}
	free(g_data.map);
	free(g_data.str_order);
	free_2d(g_data.envp);
}
