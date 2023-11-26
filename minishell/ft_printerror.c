/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:57:08 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:57:14 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_error(int type)
{
	if (type == 1)
		perror("zsh");
	else if (type == 2)
		write(1, "zsh: parse error near \\n \n", 27);
	else if (type == 3)
		write(1, "zsh: parse error near `|'\n", 26);
	else if (type == 4)
		write(1, "unset: not enough arguments\n", 28);
	else if (type == 6)
		write(1, "zsh: parse error near `<'\n", 26);
	else if (type == 7)
	{
		write(1, "zsh: command not found: ", 25);
		write(1, g_data.cmds_separate[0], ft_strlen(g_data.cmds_separate[0]));
		write(1, "\n", 1);
	}
	g_data.execution_estatus = 1;
	if (type == 5)
	{
		write(1, "dquote: open quotes\n", 20);
		g_data.execution_estatus = 130;
	}
	return (-1);
}
