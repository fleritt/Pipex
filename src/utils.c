/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:44:24 by rfleritt          #+#    #+#             */
/*   Updated: 2025/04/22 20:42:59 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void check_files(char **argv)
{
	if (ft_strlen(argv[2]) == 0 || ft_strlen(argv[3]) == 0)
	{
		perror("Error empty cmd \n");
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) == -1)
	{
		perror("Error opening input file \n");
		exit(EXIT_FAILURE);
	}
	if (access(argv[4], W_OK) == -1 && access(argv[4], F_OK) == 0)
	{
		perror("Error opening output file \n");
		exit(EXIT_FAILURE);
	}
}
static char	**find_path(char **s_path, char **env, t_pipex *data)
{
	int	i;

	i = 0;
	while(env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (env[i])
	{
		s_path = ft_split(env[i] + 5, ':');
		return (s_path);
	}
	i = 0;
	while(s_path[i])
		free(s_path[i++]);
	free(s_path);
	error("the path was not found", data);
	exit(EXIT_FAILURE);
}

static char	*get_path(char **cmd, char **env, t_pipex *data)
{
	int		i;
	char	*path;
	char	**s_path;
	char	*temp;

	i = 0;
	s_path = NULL;
	s_path = find_path(s_path, env, data);
	while (s_path[i])
	{
		temp = ft_strjoin(s_path[i], "/");
		path = ft_strjoin(temp, cmd[0]);
		free(temp);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = 0;
	while(s_path[i])
		free(s_path[i++]);
	free(s_path);
	error("the command was not found on the path\n", data);
	exit(EXIT_FAILURE);
}

void	ft_cmd(t_pipex *data, char **argv, char **env, int p)
{
	data->cmd1 = NULL;
	data->cmd2 = NULL;
	data->path1 = NULL;
	data->path2 = NULL;
	if(p == 1)
	{
		data->cmd1 = ft_split(argv[2], ' ');
		if (access(data->cmd1[0], X_OK) == 0)
			data->path1 = data->cmd1[0];
		else
			data->path1 = get_path(data->cmd1, env, data);
	}
	else if (p == 2)
	{
		data->cmd2 = ft_split(argv[3], ' ');
		if (access(data->cmd2[0], X_OK) == 0)
			data->path2 = data->cmd2[0];	
		else
			data->path2 = get_path(data->cmd2, env, data);
	}
}

void	error(char *str, t_pipex *data)
{
	int i;

	i = 0;
	if (data->cmd1)
	{
		while(data->cmd1[i])
			free(data->cmd1[i++]);
		free(data->cmd1);
	}
	i = 0;
	if (data->cmd2)
	{
		while(data->cmd2[i])
			free(data->cmd2[i++]);
		free(data->cmd2);
	}
	if (data->path1)
		free(data->path1);
	if (data->path2)
		free(data->path2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
