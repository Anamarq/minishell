/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:56:39 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:56:48 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_pipe(int *i, int *n, int *icmd)
{
	g_data.nodes[*n].num_cmds = *icmd;
	g_data.nodes[*n].fd_out = 20;
	++*n;
	g_data.nodes[*n].fd_in = 20;
	*icmd = 0;
	++*i;
}
