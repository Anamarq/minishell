/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_and_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:58:19 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:58:26 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	paths_and_heredoc(void)
{
	int	i;

	i = 0;
	while (i < g_data.npipes + 1)
	{
		if (g_data.nodes[i].cmds[0] != NULL
			&& !is_buildin(g_data.nodes[i].cmds[0]))
		{
			g_data.nodes[i].cmd_path = get_cmd_path(g_data.nodes[i].cmds[0],
					g_data.envp);
			if (!g_data.nodes[i].cmd_path)
				return (-1);
		}
		else
			g_data.nodes[i].cmd_path = NULL;
		if (g_data.nodes[i].is_here_doc == 1)
			read_files_heredoc(i);
		++i;
	}
	return (1);
}
