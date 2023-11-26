/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamarqu <anamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:27:07 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 14:13:17 by anamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putstr(char *str, int fd)
{
	int	n;

	n = 0;
	while (str[n])
	{
		write(fd, &str[n], 1);
		n++;
	}
}

int	ft_strlen(char const *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		p;

	p = 0;
	str = malloc((ft_strlen(src) + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	while (src[p])
	{
		str[p] = src[p];
		p++;
	}
	str[p] = '\0';
	return (str);
}

char	*ft_substr(char const *s, int start, int len)
{
	int		p;
	char	*str;

	p = 0;
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	str = malloc((len + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	while (s[start + p] && p < len)
	{
		str[p] = s[start + p];
		p++;
	}
	str[p] = '\0';
	return (str);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*res;
	int		c1;
	int		c2;

	c1 = 0;
	c2 = 0;
	res = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(*res));
	if (!res)
		return (NULL);
	while (str1[c1])
	{
		res[c1] = str1[c1];
		c1++;
	}
	while (str2[c2])
	{
		res[c1 + c2] = str2[c2];
		c2++;
	}
	res[c1 + c2] = '\0';
	return (res);
}
