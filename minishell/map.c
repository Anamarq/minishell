/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:29:58 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:30:09 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*ft_create_map(int n_elements)
{
	int	*map;
	int	n;

	n = 0;
	g_data.map_elements = n_elements;
	map = malloc ((n_elements + 100) * sizeof (*g_data.map));
	if (!map)
		return (NULL);
	while (n < g_data.map_elements + 100)
		map[n++] = -1;
	map[n] = '\0';
	return (map);
}

void	ft_fill_map(int start_position, int end_position, int value)
{
	int	n;

	n = start_position;
	while (n <= end_position)
	{
		g_data.map[n] = value;
		n++;
	}
}
