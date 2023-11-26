/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:37:59 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:38:06 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_str_copy(char *str_origin, char *str_destiny)
{
	int	n;

	n = 0;
	while (str_origin[n])
	{
		str_destiny[n] = str_origin[n];
		n++;
	}
}
