/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:00:49 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 01:01:42 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_pipe(void)
{
	char	*str;

	str = NULL;
	g_data.length_order = ft_strlen(g_data.str_order);
	if (g_data.length_order - 1 != 0)
	{
		while ((g_data.str_order[g_data.length_order - 1]) == ' ')
			--g_data.length_order;
		while ((g_data.str_order[g_data.length_order - 1]) == '|')
		{
			str = ft_print_entry("pipe> ");
			g_data.str_order = ft_conect(g_data.str_order, str);
			free(str);
			g_data.length_order = ft_strlen(g_data.str_order);
		}
	}
}
