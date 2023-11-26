/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:31:09 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:31:19 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_open(char letter, int position)
{
	int	n;
	int	find;

	n = position + 1;
	find = 0;
	while (g_data.str_order[n] && find == 0)
	{
		if (g_data.str_order[n] == letter)
		{
			g_data.close_position = n;
			find = 1;
		}
		n++;
	}
	if (find == 1)
	{
		g_data.is_com = 1;
		if (letter == 34)
			ft_fill_map(position, g_data.close_position, 1);
		else if (letter == 39)
			ft_fill_map(position, g_data.close_position, 0);
		return (0);
	}
	else
		return (1);
}

int	ft_check_str(void)
{
	int	n;

	n = 0;
	while (g_data.str_order[n])
	{
		if (g_data.str_order[n] == 34)
		{
			if (ft_check_open(34, n) == 1)
				return (1);
			else
				n = g_data.close_position + 1;
		}
		else if (g_data.str_order[n] == 39)
		{
			if (ft_check_open(39, n) == 1)
				return (1);
			else
				n = g_data.close_position + 1;
		}
		else
			n++;
	}
	return (0);
}
