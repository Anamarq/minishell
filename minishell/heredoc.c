/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:54:58 by pespinos          #+#    #+#             */
/*   Updated: 2023/10/10 19:10:22 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	read_files_heredoc2(void)
{
	g_data.nodes[0].fd_in = open("hdc_file", O_RDONLY);
	if (g_data.nodes[0].fd_in < 0)
	{
		perror("Error reading input file");
		exit(1);
	}
}

void	read_files_heredoc(int n)
{
	int		fdtmp;
	char	*line;

	fdtmp = open("hdc_file", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fdtmp < 0)
	{
		perror("Error creating temporary file");
		exit(1);
	}
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (ft_strcmp(g_data.nodes[n].hd_delim, line) == 1)
		{
			free(g_data.nodes[n].hd_delim);
			free(line);
			break ;
		}
		write(fdtmp, line, ft_strlen(line));
		write(fdtmp, "\n", 1);
		free(line);
	}
	close(fdtmp);
	read_files_heredoc2();
}
