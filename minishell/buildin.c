/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:50:36 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:51:28 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset_condition(int n)
{
	char	***data_separate_array;
	char	**envaux;
	char	***separ;

	if (g_data.nodes[n].num_cmds > 1)
	{
		envaux = copy_2d(g_data.envp);
		free_2d(g_data.envp);
		separ = separate_array(envaux);
		free_2d(envaux);
		data_separate_array = ft_unset(separ,
				g_data.nodes[n].cmds[1]);
		g_data.envp = join_array(data_separate_array);
		ft_free_char_3d(data_separate_array);
	}
	else
		print_error(4);
}

void	ft_export_condition(int n)
{
	char	**envaux;
	char	***separ;
	char	***expar;

	envaux = copy_2d(g_data.envp);
	free_2d(g_data.envp);
	separ = separate_array(envaux);
	free_2d(envaux);
	expar = ft_export(separ, g_data.nodes[n].cmds[1], g_data.nodes[n].cmds[3]);
	g_data.envp = join_array(expar);
	ft_free_char_3d(expar);
}

void	buildin(char *cmd, int n, int fd)
{
	int		en;

	en = 0;
	if ((ft_strcmp(cmd, "echo") || ft_strcmp(cmd, "ECHO"))
		&& g_data.nodes[n].num_cmds > 1)
		is_echo(n, fd);
	else if (ft_strcmp(cmd, "exit"))
		ft_exit(en);
	else if (ft_strcmp(cmd, "pwd") || ft_strcmp(cmd, "PWD"))
		ft_pwd(fd);
	else if (ft_strcmp(cmd, "cd"))
		ft_cd(g_data.nodes[n].cmds[1]);
	else if (ft_strcmp(cmd, "unset"))
		ft_unset_condition(n);
	else if (ft_strcmp(cmd, "env") || ft_strcmp(cmd, "ENV"))
		ft_env(g_data.envp, fd);
	else if ((ft_strcmp(cmd, "export")) && g_data.nodes[n].num_cmds > 3)
	{
		ft_export_condition(n);
	}
}

int	is_buildin(char *cmd)
{
	if (ft_strcmp(cmd, "echo") || ft_strcmp(cmd, "cd") || ft_strcmp(cmd, "pwd")
		|| ft_strcmp(cmd, "export") || ft_strcmp(cmd, "unset")
		|| ft_strcmp(cmd, "env") || ft_strcmp(cmd, "exit"))
		return (1);
	return (0);
}
