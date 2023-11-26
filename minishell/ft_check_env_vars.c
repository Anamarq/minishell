/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_env_vars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:35:17 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:35:25 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_initialize_check_env_vars(t_data_check_env_vars *d)
{
	d->str = malloc (2000);
	if (!d->str)
		return ;
	d->n = 0;
}

void	ft_else_check_env_vars(t_data_check_env_vars *d)
{
	d->str = ft_straddchar(d->str, g_data.str_order[d->n]);
	d->n++;
}

char	*ft_check_env_vars(void)
{
	t_data_check_env_vars	d;

	ft_initialize_check_env_vars(&d);
	while (g_data.str_order[d.n])
	{
		if (g_data.str_order[d.n] == '$' && (g_data.map[d.n]
				|| g_data.map[d.n] == -1)
			&& g_data.str_order[d.n + 1] != 0 && g_data.str_order[d.n + 1] != 34
			&& g_data.str_order[d.n + 1] != 39)
		{
			d.strsep = separate_array(g_data.envp);
			d.word = ft_get_word(g_data.str_order, d.n + 1);
			d.var_expand = ft_expand_var(d.strsep, d.word);
			d.str = ft_conect(d.str, d.var_expand);
			if (d.var_expand[0] != '\n')
				free(d.var_expand);
			d.n = d.n + (ft_strlen(d.word) + 1);
			ft_free_char_3d(d.strsep);
			free(d.word);
		}
		else
			ft_else_check_env_vars(&d);
	}
	return (d.str);
}
