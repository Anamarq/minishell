/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:43:09 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:43:18 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strcpy(char *dst, const char *src)
{
	size_t	p;

	p = 0;
	while (src[p] != '\0')
	{
		dst[p] = src[p];
		p++;
	}
	dst[p] = '\0';
	return (ft_strlen(src));
}
