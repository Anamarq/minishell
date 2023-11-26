/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:32:51 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:32:59 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_initialize_separate_array_data(t_separate_array_data *d)
{
	d->i = 0;
	d->j = 0;
	d->k = 0;
	d->matrix = ft_allocate_matrix(g_data.dim_env, 2);
}

void	ft_increment_j_k_separate(t_separate_array_data *d)
{
	d->j = d->j + 1;
	d->k = d->k + 1;
}

char	***separate_array(char **array)
{
	t_separate_array_data	d;

	ft_initialize_separate_array_data(&d);
	while (d.i < g_data.dim_env)
	{
		d.j = 0;
		d.k = 0;
		while (array[d.i][d.k] != '=' && array[d.i][d.k] != '\0')
		{
			d.matrix[d.i][0][d.j] = array[d.i][d.k];
			ft_increment_j_k_separate(&d);
		}
		if (array[d.i][d.k] == '=')
			++d.k;
		d.matrix[d.i][0][d.j] = '\0';
		d.j = 0;
		while (array[d.i][d.k] != '\0')
		{
			d.matrix[d.i][1][d.j] = array[d.i][d.k];
			ft_increment_j_k_separate(&d);
		}
		d.matrix[d.i][1][d.j] = '\0';
		++d.i;
	}
	return (d.matrix);
}
