/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:57:33 by pespinos          #+#    #+#             */
/*   Updated: 2023/10/10 19:08:46 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirection2(int *i, int *n)
{
	if ((ft_strncmp(g_data.cmds_separate[*i], ">", 1) == 0)
		&& g_data.cmds_separate[*i + 1] == NULL)
		return (print_error(2));
	if ((ft_strncmp(g_data.cmds_separate[*i], "<", 1) == 0)
		&& (g_data.cmds_separate[*i + 1] == NULL
			|| g_data.cmds_separate[*i + 2] == NULL))
		return (print_error(2));
	if (ft_strncmp(g_data.cmds_separate[*i], "<<", 2) == 0)
	{
		g_data.nodes[*n].is_here_doc = 1;
		++*i;
		g_data.nodes[*n].hd_delim = ft_strdup(g_data.cmds_separate[*i]);
		g_data.nodes[*n].hd_delim = ft_conect(g_data.nodes[*n].hd_delim, "\n");
		++*i;
	}
	else if (ft_strncmp(g_data.cmds_separate[*i], ">>", 2) == 0)
	{
		++*i;
		g_data.nodes[*n].fd_out = open(g_data.cmds_separate[*i],
				O_RDWR | O_CREAT | O_APPEND, 0000644);
		if (g_data.nodes[*n].fd_out < 0)
			return (print_error(1));
		++*i;
	}
	return (1);
}

int	redirection(int *i, int *n)
{
	if ((ft_strncmp(g_data.cmds_separate[*i], ">", 1) == 0)
		&& g_data.cmds_separate[*i + 1] == NULL)
		return (print_error(2));
	if ((ft_strncmp(g_data.cmds_separate[*i], ">", 1) == 0))
	{
		++*i;
		g_data.nodes[*n].fd_out = open(g_data.cmds_separate[*i],
				O_RDWR | O_CREAT | O_TRUNC, 0000644);
		if (g_data.nodes[*n].fd_out < 0)
			return (print_error(1));
	}
	else if (ft_strncmp(g_data.cmds_separate[*i], "<", 1) == 0)
	{
		++*i;
		g_data.nodes[*n].fd_in = open(g_data.cmds_separate[*i], O_RDONLY);
		if (g_data.nodes[*n].fd_in < 0)
			return (print_error(1));
	}
	return (1);
}

int	is_redir(char *str)
{
	if (ft_strncmp(str, ">", 1) == 0 || ft_strncmp(str, "<", 1) == 0)
		return (1);
	return (0);
}

int	is_redir2(char *str)
{
	if (ft_strncmp(str, ">>", 2) == 0 || ft_strncmp(str, "<<", 2) == 0)
		return (1);
	return (0);
}

int	cmd_pipes_or_redir(int *i, int *n, int *icmd, int *ip)
{
	if (g_data.cmds_separate[*i][0] == '|' && g_data.comillas[*ip] == -1)
	{
		++*ip;
		is_pipe(i, n, icmd);
	}
	else if (g_data.cmds_separate[*i][0] == '|' && g_data.comillas[*ip] != -1)
		++*ip;
	if ((g_data.cmds_separate[*i][0] == '>')
		&& g_data.cmds_separate[*i + 1][0] == '<')
		return (print_error(6));
	if (is_redir2(g_data.cmds_separate[*i]) && (g_data.comillas[*ip] == -1))
	{
		if (redirection2(i, n) < 0)
			return (-1);
		return (0);
	}
	else if (is_redir(g_data.cmds_separate[*i]) && g_data.comillas[*ip] == -1)
	{
		if (redirection(i, n) < 0)
			return (-1);
		++*i;
		++*ip;
		return (0);
	}
	return (1);
}
