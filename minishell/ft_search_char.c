/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:31:34 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:31:43 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_search_char(char letter)
{
	int	n;

	n = 0;
	while (g_data.str_order[n])
	{
		if (g_data.str_order[n] == letter)
			return (1);
		n++;
	}
	return (0);
}
