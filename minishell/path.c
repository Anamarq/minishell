/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:46:24 by pespinos          #+#    #+#             */
/*   Updated: 2023/09/30 00:47:00 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_sunet(char *buffer, int start, int len)
{
	char	*buff_aux;

	buff_aux = ft_substr(buffer, start, len);
	free(buffer);
	return (buff_aux);
}

char	**look_4_paths(char **envp)
{
	int		i;
	char	*envp_path;
	char	**paths;

	i = 0;
	while (i < g_data.dim_env)
	{
		envp_path = ft_strnstr(envp[i], "PATH=", 5);
		if (envp_path)
		{
			envp_path = ft_substr(envp_path, 5, ft_strlen(envp_path));
			break ;
		}
		else
			free (envp_path);
		i++;
	}
	if (envp_path == NULL)
	{
		free(envp_path);
		return (NULL);
	}
	paths = ft_split(envp_path, ':');
	free(envp_path);
	return (paths);
}

void	add_bar(char **paths)
{
	int		i;

	i = 0;
	while (paths[i])
	{
		paths[i] = ft_conect(paths[i], "/");
		i++;
	}
}

char	*test_paths(char **paths, char *cmd)
{
	int		i;
	char	*cmd_path;

	if (access(cmd, F_OK | X_OK) == 0)
	{
		cmd_path = ft_strdup(cmd);
		return (cmd_path);
	}
	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	write(1, "zsh: command not found: ", 24);
	write(1, cmd, ft_strlen(cmd));
	write(1, "\n", 1);
	g_data.execution_estatus = 127;
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*str;
	int		i;

	paths = look_4_paths(envp);
	if (paths)
	{
		add_bar(paths);
		str = test_paths(paths, cmd);
		i = 0;
		while (paths[i])
		{
			free(paths[i]);
			++i;
		}
		free(paths);
		return (str);
	}
	else
	{
		free(paths);
		return (NULL);
	}
	return (NULL);
}
