/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:31:59 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:32:06 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_count_rows(char ***str)
{
	int	n_rows;

	n_rows = 0;
	while (str[n_rows])
		n_rows++;
	return (n_rows);
}

int	ft_count_rows_2d(char **str)
{
	int	dim;

	dim = 0;
	while (str[dim] != NULL)
	{
		++dim;
	}
	return (dim);
}
