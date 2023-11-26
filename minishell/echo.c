/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:47:35 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:47:41 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char *str, int n, int fd)
{
	ft_put_str(str, fd);
	if (!n)
		ft_put_str("\n", fd);
}

void	is_echo(int n, int fd)
{
	int		en;
	char	*array;
	int		i;

	en = 0;
	array = malloc(1000);
	array[0] = '\0';
	i = 1;
	if (ft_strcmp(g_data.nodes[n].cmds[1], "-n"))
	{
		en = 1;
		i = 2;
	}
	while (i < g_data.nodes[n].num_cmds)
	{
		array = ft_conect(array, g_data.nodes[n].cmds[i]);
		++i;
		if (g_data.nodes[n].cmds[i] != NULL)
			array = ft_conect(array, " ");
	}
	ft_echo(array, en, fd);
	g_data.execution_estatus = 0;
	free(array);
}
