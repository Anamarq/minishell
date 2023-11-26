/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:33:18 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:33:28 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_allocate_array(int number_rows)
{
	char	**array;
	int		i;

	array = malloc((number_rows + 1) * sizeof(char *));
	if (!array)
	{
		perror("malloc");
		free(array);
		return (NULL);
	}
	i = 0;
	while (i < number_rows)
	{
		array[i] = malloc(1000 * sizeof(char *));
		if (!array[i])
		{
			perror("malloc");
			free(array[i]);
			return (NULL);
		}
		++i;
	}
	return (array);
}
