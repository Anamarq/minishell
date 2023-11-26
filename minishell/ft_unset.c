/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:47:54 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:48:06 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	***exec_unset(char	***env_vars, int isvar)
{
	char	***new_env_vars;
	int		row_old;
	int		row_new;

	new_env_vars = ft_allocate_matrix(g_data.dim_env - 1, 2);
	row_old = 0;
	row_new = 0;
	while (row_old < g_data.dim_env)
	{
		if (row_old == isvar)
			++row_old;
		else
		{
			free(new_env_vars[row_new][0]);
			free(new_env_vars[row_new][1]);
			new_env_vars[row_new][0] = ft_strdup(env_vars[row_old][0]);
			new_env_vars[row_new][1] = ft_strdup(env_vars[row_old][1]);
			row_new++;
			row_old++;
		}
	}
	ft_free_char_3d(env_vars);
	g_data.dim_env--;
	g_data.execution_estatus = 0;
	return (new_env_vars);
}

char	***ft_unset(char ***env_vars, char *name_var)
{
	char	***new_env_vars;
	int		row_old;
	int		isvar;

	row_old = 0;
	isvar = -1;
	while (row_old < g_data.dim_env)
	{
		if (ft_strcmp(env_vars[row_old][0], name_var))
		{
			isvar = row_old;
			break ;
		}
		row_old++;
	}
	if (isvar < 0)
		return (env_vars);
	new_env_vars = exec_unset(env_vars, isvar);
	return (new_env_vars);
}

// char	***ft_unset(char ***env_vars, char *name_var)
// {
// 	char	***new_env_vars;
// 	int		row_new;
// 	int		row_old;
// 	int		isvar;

// 	row_new = 0;
// 	row_old = 0;
// 	isvar = -1;
// 	while (row_old < g_data.dim_env)
// 	{
// 		if (ft_strcmp(env_vars[row_old][0], name_var))
// 		{
// 			isvar = row_old;
// 			break ;
// 		}
// 		row_old++;
// 	}
// 	if (isvar < 0)
// 		return (env_vars);
// 	new_env_vars = ft_allocate_matrix(g_data.dim_env - 1, 2);
// 	row_old = 0;
// 	while (row_old < g_data.dim_env)
// 	{
// 		if (row_old == isvar)
// 			++row_old;
// 		else
// 		{
// 			free(new_env_vars[row_new][0]);
// 			free(new_env_vars[row_new][1]);
// 			new_env_vars[row_new][0] = ft_strdup(env_vars[row_old][0]);
// 			new_env_vars[row_new][1] = ft_strdup(env_vars[row_old][1]);
// 			row_new++;
// 			row_old++;
// 		}
// 	}
// 	ft_free_char_3d(env_vars);
// 	g_data.dim_env--;
// 	g_data.execution_estatus = 0;
// 	return (new_env_vars);
// }
