/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nopip_nobuildin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:52:56 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:53:22 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	nopip_nobuildin(void)
{
	char	**array;

	if (g_data.nodes[0].fd_in != 0 && g_data.nodes[0].fd_in != 20)
	{
		dup2(g_data.nodes[0].fd_in, STDIN_FILENO);
		close(g_data.nodes[0].fd_in);
	}
	if (g_data.nodes[0].fd_out != 1 && g_data.nodes[0].fd_out != 20)
	{
		dup2(g_data.nodes[0].fd_out, STDOUT_FILENO);
		close(g_data.nodes[0].fd_out);
	}
	array = create_array_execve(0);
	if (!array)
	{
		free(array);
		exit(1);
	}
	if (execve(g_data.nodes[0].cmd_path, array, g_data.envp) == -1)
		exit(1);
	perror("execve");
	free(array);
	exit(1);
}

void	ft_check_pid(pid_t pid1)
{
	if (pid1 == -1)
	{
		perror("Error al crear pid");
		exit(1);
	}
}

void	nopip(void)
{
	pid_t	pid1;
	int		status;

	if (g_data.nodes[0].cmds[0] != NULL
		&& is_buildin(g_data.nodes[0].cmds[0]))
	{
		buildin(g_data.nodes[0].cmds[0], 0, g_data.nodes[0].fd_out);
		if (g_data.nodes[0].fd_out != 1 && g_data.nodes[0].fd_out != 20)
			close(g_data.nodes[0].fd_out);
	}
	else
	{
		status = 0;
		pid1 = fork();
		ft_check_pid(pid1);
		if (pid1 == 0)
			nopip_nobuildin();
		else if (pid1 > 0)
		{
			WEXITSTATUS(status);
			waitpid(pid1, &status, 0);
			g_data.execution_estatus = status / 256;
		}
	}
}
