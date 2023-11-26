/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:57:52 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 14:12:53 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_error(int *i)
{
	if (*i > 0 && (g_data.cmds_separate[*i - 1][0] == '|') &&
		(g_data.cmds_separate[*i][0] == '|'))
		return (print_error(3));
	if (*i > 1 && (g_data.cmds_separate[*i - 2][0] == '|') &&
		(g_data.cmds_separate[*i - 1][0] == '<') &&
			(g_data.cmds_separate[*i][0] == '|'))
		return (print_error(3));
	if (*i > 1 && (g_data.cmds_separate[*i - 2][0] == '|') &&
		(g_data.cmds_separate[*i - 1][0] == '>') &&
			(g_data.cmds_separate[*i][0] == '|'))
		return (print_error(3));
	if (*i == 1 && (g_data.cmds_separate[0][0] == '<') &&
		((g_data.cmds_separate[1][0] == '<') ||
			(g_data.cmds_separate[1][0] == '>')))
		return (print_error(6));
	if (g_data.cmds_separate[0][0] == '>')
		return (print_error(6));
	if (g_data.cmds_separate[0][0] == '|')
		return (print_error(7));
	if (*i > 0 && (g_data.cmds_separate[*i - 1][0] == '|') &&
		(g_data.cmds_separate[*i][0] == '>'))
		return (print_error(6));
	return (1);
}

int	get_cmds2(int *i, int *n, int *icmd, int *is)
{
	int	ip;
	int	np;

	ip = 0;
	np = 0;
	if (parse_error(is) == -1)
		return (-1);
	np = cmd_pipes_or_redir(i, n, icmd, &ip);
	if (np == 1)
	{
		if (is_redir(g_data.cmds_separate[*i]) && g_data.comillas[ip] != -1)
			++ip;
		if (g_data.cmds_separate[*i] != NULL)
		{
			g_data.nodes[*n].cmds[*icmd] = ft_strdup(g_data.cmds_separate[*i]);
			++ *icmd;
		}
		++*i;
	}
	else if (np == -1)
		return (-1);
	return (1);
}

int	get_cmds1(void)
{
	int	i;
	int	n ;
	int	icmd;
	int	is;

	n = 0;
	icmd = 0;
	is = 0;
	i = 0;
	while (g_data.cmds_separate[i] != NULL)
	{
		if (get_cmds2(&i, &n, &icmd, &is) < 0)
		{
			g_data.nodes[n].cmds[icmd] = NULL;
			g_data.nodes[n].num_cmds = icmd;
			return (-1);
		}
		++is;
	}
	g_data.nodes[n].cmds[icmd] = NULL;
	g_data.nodes[n].num_cmds = icmd;
	return (1);
}

int	get_cmds(void)
{
	int	i;

	if (g_data.cmds_separate[0] == NULL)
		return (0);
	if (g_data.cmds_separate[0][0] == '|' && g_data.map[0] == -1)
		return (print_error(3));
	i = 0;
	while (g_data.cmds_separate[i] != NULL)
	{
		if (parse_error(&i) == -1)
			return (-1);
		++i;
	}
	if (get_cmds1() < 0)
		return (-1);
	return (1);
}
