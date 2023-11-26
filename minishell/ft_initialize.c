/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:55:59 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:56:04 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	initialize(void)
{
	int	i;

	i = 0;
	while (i < g_data.npipes + 1)
	{
		g_data.nodes[i].fd_in = 0;
		g_data.nodes[i].fd_out = 1;
		g_data.nodes[i].num_cmds = 0;
		g_data.nodes[i].is_here_doc = 0;
		++i;
	}
}
