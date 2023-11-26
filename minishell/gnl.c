/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:45:03 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:46:03 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_conect(char *buffer, char *tab)
{
	char	*buff_aux;

	buff_aux = ft_strjoin(buffer, tab);
	free(buffer);
	return (buff_aux);
}

char	*ft_readline(char *buffer, int fd)
{
	char	*buff_aux;
	int		br;

	buff_aux = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	br = 1;
	while (ft_ind(buffer, '\n') == -1 && br > 0)
	{
		br = read(fd, buff_aux, BUFFER_SIZE);
		if (br == -1)
		{
			free(buffer);
			free(buff_aux);
			return (NULL);
		}
		buff_aux[br] = '\0';
		buffer = ft_conect(buffer, buff_aux);
	}
	if (ft_strlen(buffer) == 0)
	{
		free(buff_aux);
		free(buffer);
		return (NULL);
	}
	free(buff_aux);
	return (buffer);
}

char	*ft_next_buffer(char *buffer)
{
	char	*buff;

	buff = ft_substr(buffer, ft_ind(buffer, '\n') + 1,
			ft_strlen(&buffer[ft_ind(buffer, '\n') + 1]) + 1);
	free(buffer);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*buff_aux;

	if (!buffer)
		buffer = ft_strdup("");
	buffer = ft_readline(buffer, fd);
	if (!buffer || fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	if (buffer != NULL && ft_ind(buffer, '\n') != -1)
	{
		buff_aux = ft_substr(buffer, 0, ft_ind(buffer, '\n') + 1);
		buffer = ft_next_buffer(buffer);
		return (buff_aux);
	}
	buff_aux = buffer;
	buffer = NULL;
	return (buff_aux);
}
