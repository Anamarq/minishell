/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:27:34 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:47:18 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_num_words(char const *s, char c)
{
	int	q;
	int	p;
	int	first;

	q = 0;
	p = 0;
	first = 1;
	while (s[p])
	{
		if (s[p] != c && s[p] != '\0' && first == 1)
		{
			q++;
			first = 0;
		}
		if (s[p] == c)
			first = 1;
		p++;
	}
	return (q);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		q;
	int		p;
	int		start;

	q = 0;
	p = 0;
	start = 0;
	result = malloc((ft_num_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (s[p] && q < ft_num_words(s, c))
	{
		while (s[p] && s[p] == c)
			p++;
		start = p;
		while (s[p] && s[p] != c)
			p++;
		if (start != p)
			result[q++] = ft_substr(s, start, p - start);
	}
	result[q] = NULL;
	return (result);
}

char	**ft_split2(char const *s, char c)
{
	char	**result;
	int		q;
	int		p;
	int		start;

	q = 0;
	p = 0;
	start = 0;
	result = malloc((ft_num_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (s[p] && q < ft_num_words(s, c))
	{
		while ((s[p] && s[p] == c))
			p++;
		start = p;
		while ((s[p] && s[p] != c) || (s[p] && g_data.map[p] != -1))
			p++;
		if (start != p)
			result[q++] = ft_substr(s, start, p - start);
	}
	result[q] = NULL;
	return (result);
}

void	ft_put_str(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}
