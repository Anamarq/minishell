/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:33:45 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:33:52 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_initialize_join_array_data(t_join_array_data *d)
{
	d->i = 0;
	d->j = 0;
	d->k = 0;
	d->array = ft_allocate_array(g_data.dim_env);
}

void	ft_increment_j_k_join(t_join_array_data *d)
{
	d->j = d->j + 1;
	d->k = d->k + 1;
}

char	**join_array(char ***matrix)
{
	t_join_array_data	d;

	ft_initialize_join_array_data(&d);
	while (d.i < g_data.dim_env)
	{
		d.j = 0;
		d.k = 0;
		while (matrix[d.i][0][d.k] != '\0')
		{
			d.array[d.i][d.j] = matrix[d.i][0][d.k];
			ft_increment_j_k_join(&d);
		}
		d.array[d.i][d.j] = '=';
		++d.j;
		d.k = 0;
		while (matrix[d.i][1][d.k] != '\0')
		{
			d.array[d.i][d.j] = matrix[d.i][1][d.k];
			ft_increment_j_k_join(&d);
		}
		d.array[d.i][d.j] = '\0';
		++d.i;
	}
	d.array[d.i] = NULL;
	return (d.array);
}
