/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:49:12 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:49:19 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(int fd)
{
	char	*cwd;
	size_t	buffer_size;

	cwd = NULL;
	buffer_size = 4096;
	while (cwd == NULL)
	{
		cwd = (char *)malloc(buffer_size);
		if (cwd == NULL)
		{
			perror("malloc() error");
			exit(EXIT_FAILURE);
		}
		if (getcwd(cwd, buffer_size) == NULL)
		{
			free(cwd);
			buffer_size *= 2;
		}
	}
	ft_put_str(cwd, fd);
	ft_put_str("\n", fd);
	free(cwd);
	g_data.execution_estatus = 0;
}
