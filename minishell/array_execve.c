/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_execve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:52:18 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:52:28 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**malloc_array(int dim)
{
	char	**array;

	array = malloc(dim * sizeof(char *));
	if (!array)
	{
		perror("malloc");
		free(array);
		return (NULL);
	}
	return (array);
}

char	**create_array_execve(int i)
{
	char	**array;

	if (g_data.nodes[i].num_cmds == 1)
	{
		array = malloc_array(2);
		array[0] = ft_strdup(g_data.nodes[i].cmd_path);
		array[1] = NULL;
	}
	else
	{
		array = malloc_array(3);
		array[0] = ft_strdup(g_data.nodes[i].cmd_path);
		array[1] = ft_strdup(g_data.nodes[i].cmds[1]);
		array[2] = NULL;
	}
	return (array);
}
