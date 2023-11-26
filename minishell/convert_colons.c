/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_colons.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:40:17 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:40:25 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_find_ignore_limit(char *str, int start_position)
{
	char	letter_to_find;
	int		n;
	int		limit;

	letter_to_find = str[start_position];
	n = start_position + 1;
	limit = -2;
	while (str[n] && limit == -2)
	{
		if (str[n] == letter_to_find)
			limit = n;
		n++;
	}
	return (limit);
}

int	ft_init_convert_colons_data(t_convert_colons_data *d)
{
	d->new_map = ft_create_map(ft_strlen(g_data.str_order));
	d->str_return = malloc (1000 * sizeof (*d->str_return));
	if (!d->str_return)
		return (-1);
	d->n = 0;
	d->i = 0;
	d->ignore_limit = -1;
	return (1);
}

void	ft_convert_colons_conditions(t_convert_colons_data *d)
{
	if (d->ignore_limit != -1)
	{
		if (d->n == d->ignore_limit)
			d->ignore_limit = -1;
		else
		{
			d->str_return[d->i] = g_data.str_order[d->n];
			d->new_map[d->i++] = g_data.map[d->n];
		}
	}
	else if (g_data.str_order[d->n] == '"' || g_data.str_order[d->n] == '\'')
		d->ignore_limit = ft_find_ignore_limit(g_data.str_order, d->n);
	else
	{
		d->str_return[d->i] = g_data.str_order[d->n];
		d->new_map[d->i++] = g_data.map[d->n];
	}
}

char	*ft_convert_colons(void)
{
	t_convert_colons_data	d;

	if (ft_init_convert_colons_data(&d) == -1)
		return (NULL);
	while (g_data.str_order[d.n])
	{
		ft_convert_colons_conditions(&d);
		d.n++;
	}
	d.str_return[d.i] = '\0';
	free(g_data.map);
	g_data.map = d.new_map;
	g_data.map_elements = d.i;
	return (d.str_return);
}
