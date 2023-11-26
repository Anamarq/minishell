/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:39:39 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:39:49 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_len(int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	ft_loop_itoa(t_itoa_data *d, int n)
{
	while (n > 0)
	{
		d->result[d->len--] = (n % 10) + 48;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	t_itoa_data	d;

	d.sign = 0;
	d.len = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		d.sign++;
		n = -n;
	}
	d.len = ft_len(n) + d.sign;
	d.result = malloc((d.len + 1) * sizeof(*d.result));
	if (!d.result)
		return (NULL);
	if (d.sign)
		d.result[0] = '-';
	d.result[d.len] = '\0';
	d.len--;
	ft_loop_itoa(&d, n);
	return (d.result);
}
