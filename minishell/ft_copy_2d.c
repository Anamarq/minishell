/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:56:21 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:56:27 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**copy_2d(char **envp)
{
	int		num_vars;
	int		i;
	char	**copy_envp;

	num_vars = 0;
	i = 0;
	while (envp[num_vars] != NULL)
		num_vars++;
	copy_envp = (char **)malloc((num_vars + 1) * sizeof(char *));
	if (copy_envp == NULL)
	{
		perror("Error al asignar memoria para la copia");
		exit(1);
	}
	while (i < num_vars)
	{
		copy_envp[i] = ft_strdup(envp[i]);
		++i;
	}
	copy_envp[num_vars] = NULL;
	return (copy_envp);
}
