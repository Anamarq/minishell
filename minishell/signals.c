/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:35:41 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:37:15 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_control_c(int sig)
{
	g_data.ctrl_c = 1;
	if (sig == SIGINT)
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
}

int	ft_control_d(void)
{
	if (!g_data.str_order)
		exit(0);
	return (0);
}

void	ft_init_signals(void)
{
	signal(SIGINT, ft_control_c);
	signal(SIGQUIT, SIG_IGN);
}
