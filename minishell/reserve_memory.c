/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reserve_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:53:40 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:53:46 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	**reserve_memory_pipes(void)
{
	int		**pipes;
	int		i;

	pipes = malloc((g_data.npipes) * sizeof(int *));
	if (!pipes)
	{
		perror("malloc");
		free(pipes);
		return (NULL);
	}
	i = 0;
	while (i < g_data.npipes)
	{
		pipes[i] = malloc(2 * sizeof(int));
		if (!pipes[i])
		{
			perror("malloc");
			free(pipes[i]);
			return (NULL);
		}
		++i;
	}
	return (pipes);
}

pid_t	*reserve_memory_pids(void)
{
	pid_t	*pids;

	pids = malloc((g_data.npipes + 1) * sizeof(*pids));
	if (!pids)
	{
		perror("malloc");
		return (NULL);
	}
	return (pids);
}
