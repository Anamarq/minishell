/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:49:53 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:50:00 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(char *ruta)
{
	if (chdir(ruta) == -1)
	{
		perror("cd");
		g_data.execution_estatus = 1;
		return (1);
	}
	g_data.execution_estatus = 0;
	return (0);
}
