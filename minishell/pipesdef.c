/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipesdef.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:54:39 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:54:45 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_pipes_pids(int **pipes, pid_t *pids)
{
	int	i;

	i = 0;
	while (i < g_data.npipes)
	{
		free(pipes[i]);
		++i;
	}
	free(pipes);
	free(pids);
}

int	pipesdef(void)
{
	int		**pipes;
	pid_t	*pids;
	int		i;

	i = 0;
	pipes = reserve_memory_pipes();
	if (!pipes)
		return (-1);
	pids = reserve_memory_pids();
	if (!pids)
		return (-1);
	while (i < g_data.npipes + 1)
	{
		if (i < g_data.npipes)
		{
			if (pipe(pipes[i]) == -1)
				return (perror("pipe"), -1);
		}
		execute_pipes(pipes, pids, i);
		++i;
	}
	close_and_wait_pipes(pipes, pids);
	free_pipes_pids(pipes, pids);
	return (0);
}
