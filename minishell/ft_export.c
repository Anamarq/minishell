/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:48:14 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 13:12:43 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	***exec_export(char	***env_vars, char *name_var, char *value_var)
{
	char	***new_env_vars;
	int		row;

	row = 0;
	new_env_vars = ft_allocate_matrix(g_data.dim_env + 1, 2);
	while (row <= g_data.dim_env - 1)
	{
		free(new_env_vars[row][0]);
		free(new_env_vars[row][1]);
		new_env_vars[row][0] = ft_strdup(env_vars[row][0]);
		new_env_vars[row][1] = ft_strdup(env_vars[row][1]);
		row++;
	}
	free(new_env_vars[row][0]);
	free(new_env_vars[row][1]);
	new_env_vars[row][0] = ft_strdup(name_var);
	new_env_vars[row][1] = ft_strdup(value_var);
	ft_free_char_3d(env_vars);
	g_data.dim_env++;
	g_data.execution_estatus = 0;
	return (new_env_vars);
}

char	***ft_export(char ***env_vars, char *name_var, char *value_var)
{
	char	***new_env_vars;
	int		pos;

	pos = ft_check_exist_var(env_vars, name_var);
	if (pos != -1)
	{
		free(env_vars[pos][1]);
		env_vars[pos][1] = ft_strdup(value_var);
		return (env_vars);
	}
	new_env_vars = exec_export(env_vars, name_var, value_var);
	return (new_env_vars);
}
