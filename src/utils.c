/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:44:24 by rfleritt          #+#    #+#             */
/*   Updated: 2025/02/15 21:08:29 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void check_files(char **doc)
{
	if (access(doc[1], R_OK) == -1)
	{
		error("Error opening input file \n");
		exit(EXIT_FAILURE);
	}
	if (access(doc[4], W_OK) == -1 && access(doc[4], F_OK) == 0)
	{
		error("Error opening output file \n");
		exit(EXIT_FAILURE);
	}
}
static char	*find_path(char *f_path, char **env)
{
	int	i;

	i = 0;
	while(env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			{
				f_path = env[i] + 5;
				return (f_path);
			}
		i++;
	}
	error("the path was not found");
	exit(EXIT_FAILURE);
}

static char	*get_path(char **cmd, char **env)
{
	int		i;
	char	*path;
	char	*f_path;
	char	**s_path;
	char	*temp;

	i = 0;
	f_path = NULL;
	f_path = find_path(f_path, env);
	s_path = ft_split(f_path, ':');
	while (s_path[i])
	{
		temp = ft_strjoin(s_path[i], "/");
		path = ft_strjoin(temp, cmd[0]);
		free(temp);
		if (access(path, X_OK) == 0)
			return (path);
		i++;
	}
	error("the command was not found on the path");
	exit(EXIT_FAILURE);
}

void	ft_cmd(t_pipex *data, char **argv, char **env)
{
	data->cmd1 = ft_split(argv[2], ' ');
	data->cmd2 = ft_split(argv[3], ' ');
	data->path1 = get_path(data->cmd1, env);
	data->path2 = get_path(data->cmd2, env);
}

void	error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}