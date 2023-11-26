/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:40:39 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:40:50 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && i < len)
	{
		j = 0;
		while ((j + i < len)
			&& (*(haystack + j) == needle[j]) && *(haystack + j) != '\0')
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack);
			++j;
		}
		++haystack;
		++i;
	}
	return (0);
}
