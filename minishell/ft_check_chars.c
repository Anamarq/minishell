/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:38:23 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:38:30 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_chars(char letter, char *str)
{
	int	found;
	int	n;

	found = 0;
	n = 0;
	while (str[n] && found == 0)
	{
		if (str[n] == letter)
			found = 1;
		n++;
	}
	return (found);
}
