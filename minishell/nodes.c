/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:59:00 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 16:18:55 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	reserve_nodes_memory(void)
{
	int	i;

	g_data.nodes = malloc((g_data.npipes + 1) * sizeof(t_node));
	if (!g_data.nodes)
	{
		perror("malloc");
		free(g_data.nodes);
		return (-1);
	}
	i = 0;
	while (i < g_data.npipes + 1)
	{
		g_data.nodes[i].cmds = malloc(1024 * sizeof(char *));
		if (!g_data.nodes[i].cmds)
		{
			perror("malloc");
			free(g_data.nodes[i].cmds);
			return (-1);
		}
		++i;
	}
	return (0);
}

void	free_nodes(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < g_data.npipes + 1)
	{
		while (j < g_data.nodes[i].num_cmds)
		{
			free(g_data.nodes[i].cmds[j]);
			++j;
		}
		free(g_data.nodes[i].cmds);
		++i;
		j = 0;
	}
	free(g_data.nodes);
}
