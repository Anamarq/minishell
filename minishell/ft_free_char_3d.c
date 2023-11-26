/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_3d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:34:56 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:35:03 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmdpath(void)
{
	int	i;

	i = 0;
	while (i < g_data.npipes + 1)
	{
		free(g_data.nodes[i].cmd_path);
		++i;
	}
}

void	free_2d(char **to_free)
{
	int	i;

	i = 0;
	while (i < g_data.dim_env)
	{
		free(to_free[i]);
		++i;
	}
	free(to_free);
}

void	ft_free_char_3d(char ***to_free)
{
	int	n;

	n = 0;
	while (n < g_data.dim_env)
	{
		free (to_free[n][1]);
		free(to_free[n][0]);
		free(to_free[n]);
		n++;
	}
	free (to_free);
}
