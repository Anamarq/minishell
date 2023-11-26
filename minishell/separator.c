/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:39:11 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:39:21 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_initialize_separator_data(t_separator_data *d)
{
	d->n = 0;
	d->p = 0;
	d->result = malloc((1024) * sizeof(*d->result));
}

void	ft_conditions_ft_separator(t_separator_data *d, char *str)
{
	if (ft_check_chars(str[d->n + 1], "<>|=") && str[d->n] != ' '
		&& !(ft_check_chars(str[d->n], "<>")) && g_data.map[d->n] == -1)
	{
		d->result[d->p] = str[d->n];
		d->p++;
		d->result[d->p] = ' ';
		d->p++;
	}
	else if (ft_check_chars(str[d->n], "<>|=") && str[d->n + 1] != ' '
		&& !(ft_check_chars(str[d->n + 1], "<>")) && g_data.map[d->n] == -1)
	{
		d->result[d->p] = str[d->n];
		d->p++;
		d->result[d->p] = ' ';
		d->p++;
	}
	else
	{
		d->result[d->p] = str[d->n];
		d->p++;
	}
}

char	*ft_separator(char *str)
{
	t_separator_data	d;

	ft_initialize_separator_data(&d);
	if (!d.result)
		return (NULL);
	while (str[d.n])
	{
		ft_conditions_ft_separator(&d, str);
		d.n++;
	}
	d.result[d.p] = '\0';
	return (d.result);
}
