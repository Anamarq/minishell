/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:00:28 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 01:00:35 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_separar(char *buffer)
{
	char	*buff_aux;

	buff_aux = ft_separator(buffer);
	free(buffer);
	return (buff_aux);
}
