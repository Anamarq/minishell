/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_characters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:38:50 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:38:56 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_number_characters(char *str)
{
	int	n;
	int	n_chars;

	n = 0;
	n_chars = 0;
	while (str[n])
	{
		if (ft_check_chars(str[n + 1], "<>|") && str[n] != ' '
			&& !(ft_check_chars(str[n], "<>")))
			n_chars++;
		else if (ft_check_chars(str[n], "<>|") && str[n + 1] != ' '
			&& !(ft_check_chars(str[n], "<>")))
			n_chars++;
		n_chars++;
		n++;
	}
	return (n_chars);
}
