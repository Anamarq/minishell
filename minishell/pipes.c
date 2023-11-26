/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:54:16 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:54:23 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_close_pipes(int i, int **pipes)
{
	if (g_data.nodes[i].fd_in == 20)
	{
		dup2(pipes[i - 1][0], STDIN_FILENO);
		close(pipes[i - 1][0]);
	}
	else if (g_data.nodes[i].fd_in != 0 && g_data.nodes[i].fd_in != 20)
	{
		dup2(g_data.nodes[i].fd_in, STDIN_FILENO);
		close(g_data.nodes[i].fd_in);
	}
	if (g_data.nodes[i].fd_out == 20)
	{
		dup2(pipes[i][1], STDOUT_FILENO);
		close(pipes[i][1]);
	}
	else if (g_data.nodes[i].fd_out != 1 && g_data.nodes[i].fd_out != 20)
	{
		dup2(g_data.nodes[i].fd_out, STDOUT_FILENO);
		close(g_data.nodes[i].fd_out);
	}
}

void	execve_pipes(int i, int **pipes)
{
	char	**array;

	open_close_pipes(i, pipes);
	array = create_array_execve(i);
	if (!array)
		exit(1);
	if (execve(g_data.nodes[i].cmd_path, array, g_data.envp) == -1)
		exit(1);
	perror("execve");
	exit(1);
}

void	pipes_buildin(int i, int **pipes)
{
	if (g_data.nodes[i].fd_out == 20)
	{
		buildin(g_data.nodes[i].cmds[0], i, pipes[i][1]);
		close(pipes[i][1]);
	}
	else
	{
		buildin(g_data.nodes[i].cmds[0], i, g_data.nodes[i].fd_out);
		if (g_data.nodes[0].fd_out != 1 && g_data.nodes[0].fd_out != 20)
			close(g_data.nodes[i].fd_out);
	}
}

int	execute_pipes(int **pipes, pid_t *pids, int i)
{
	if (g_data.nodes[i].cmds[0] != NULL && is_buildin(g_data.nodes[i].cmds[0]))
		pipes_buildin(i, pipes);
	else
	{
		pids[i] = fork();
		if (pids[i] < 0)
		{
			perror("fork");
			return (0);
		}
		else if (pids[i] == 0)
			execve_pipes(i, pipes);
		else
		{
			if (i > 0)
				close(pipes[i - 1][0]);
			if (i < g_data.npipes)
				close(pipes[i][1]);
		}
	}
	return (1);
}

void	close_and_wait_pipes(int **pipes, pid_t *pids)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < g_data.npipes)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		++i;
	}
	i = 0;
	while (i < g_data.npipes + 1)
	{
		WEXITSTATUS(status);
		waitpid(pids[i], &status, 0);
		g_data.execution_estatus = status / 256;
		++i;
	}
}
