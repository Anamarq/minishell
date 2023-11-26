/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_exist_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:34:08 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 13:10:57 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_exist_var(char ***env_vars, char *name_var)
{
	int	find;
	int	row;

	find = 0;
	row = 0;
	while (row < g_data.dim_env && find == 0)
	{
		if (ft_strcmp(env_vars[row][0], name_var))
			find = 1;
		row++;
	}
	if (find == 1)
		return (row - 1);
	return (-1);
}
