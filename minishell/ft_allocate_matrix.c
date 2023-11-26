/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:32:21 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:32:31 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	***ft_allocate_matrix(int number_rows, int number_columns)
{
	char	***new_matrix;
	int		fila;
	int		columna;

	fila = 0;
	columna = 0;
	new_matrix = malloc((number_rows + 1) * sizeof(*new_matrix));
	if (!new_matrix)
		return (NULL);
	while (fila < number_rows)
	{
		new_matrix[fila] = malloc((number_columns + 1) * sizeof(**new_matrix));
		if (!new_matrix[fila])
			return (NULL);
		while (columna < number_columns)
		{
			new_matrix[fila][columna] = malloc(1000 * sizeof(***new_matrix));
			if (!new_matrix[fila][columna])
				return (NULL);
			columna++;
		}
		columna = 0;
		fila++;
	}
	return (new_matrix);
}
