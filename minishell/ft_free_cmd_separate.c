/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cmd_separate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:59:31 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:59:39 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmd_separate(void)
{
	int	i;

	i = 0;
	while (g_data.cmds_separate[i] != NULL)
	{
		free(g_data.cmds_separate[i]);
		++i;
	}
	free(g_data.cmds_separate);
}
