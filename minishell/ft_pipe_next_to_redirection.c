/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_next_to_redirection.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:00:01 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 01:00:15 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_next_to_redirection(void)
{
	int	k;

	k = 2;
	while (k < g_data.length_order)
	{
		if (k >= 4 && g_data.str_order[k - 4] == '|'
			&& g_data.str_order[k - 2] == '|' && g_data.str_order[k] == '>')
		{
			g_data.str_order[k - 2] = ' ';
			g_data.str_order[k - 4] = ' ';
		}
		if (g_data.str_order[k - 2] == '|' && g_data.str_order[k] == '>')
		{
			g_data.str_order[k - 2] = ' ';
		}
		++k;
	}
}
