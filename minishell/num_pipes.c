/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_pipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:55:28 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:55:40 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	num_pipes2(char c, int *nc, int *n_pipes, int n)
{
	if (c == '|' && g_data.map[n] == -1)
	{
		g_data.comillas[*nc] = -1;
		++*nc;
		++*n_pipes;
	}
	else if (c == '|' && g_data.map[n] != -1)
	{
		g_data.comillas[*nc] = 1;
		++*nc;
	}
	else if ((c == '>' && g_data.map[n] == -1)
		|| (c == '<' && g_data.map[n] == -1))
	{
		g_data.comillas[*nc] = -1;
		++*nc;
	}
	else if ((c == '>' && g_data.map[n] != -1)
		|| (c == '<' && g_data.map[n] != -1))
	{
		g_data.comillas[*nc] = 1;
		++*nc;
	}
}

int	ft_number_pipes(char *str)
{
	int	n_pipes;
	int	n;
	int	nc;

	n_pipes = 0;
	n = 0;
	nc = 0;
	g_data.comillas = malloc (1000 * sizeof(int));
	while (str[n])
	{
		num_pipes2(str[n], &nc, &n_pipes, n);
		n++;
	}
	return (n_pipes);
}
