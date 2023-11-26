/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:30:33 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:30:50 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_straddchar(char *str, char letter)
{
	char	*s;
	int		c1;

	c1 = 0;
	s = malloc((ft_strlen(str) + 2) * sizeof(*s));
	if (!s)
		return (NULL);
	while (str[c1])
	{
		s[c1] = str[c1];
		c1++;
	}
	s[c1] = letter;
	s[c1 + 1] = '\0';
	free (str);
	return (s);
}
