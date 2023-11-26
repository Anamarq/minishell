/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:34:31 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 14:12:33 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_word(char *str, int position)
{
	int	start;
	int	len;

	start = position;
	len = 0;
	while (str[position] != ' ' && str[position] != '$' && str[position]
		&& str[position] != 34 && str[position] != 39)
	{
		len++;
		position++;
	}
	return (ft_substr(str, start, len));
}

char	*ft_expand_var(char ***env_vars, char *str)
{
	int		row;
	char	*streturn;

	if (ft_strcmp(str, "?"))
		return (ft_itoa(g_data.execution_estatus));
	row = -1;
	row = ft_check_exist_var(env_vars, str);
	if (row != -1)
	{
		streturn = ft_strdup(env_vars[row][1]);
		return (streturn);
	}
	return ("\n");
}
