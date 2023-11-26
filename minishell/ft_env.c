/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:50:13 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:50:21 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(char **envp, int fd)
{
	int	i;

	i = 0;
	while (i < g_data.dim_env)
	{
		ft_put_str(envp[i], fd);
		ft_put_str("\n", fd);
		i++;
	}
	g_data.execution_estatus = 0;
	return (0);
}
