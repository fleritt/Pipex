/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:16:54 by rfleritt          #+#    #+#             */
/*   Updated: 2025/04/08 23:31:54 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	first_child(t_pipex *data, char **argv, char **env)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening input file \n");
		exit(EXIT_FAILURE);
	}
	ft_cmd(data, argv, env);
	dup2(fd, STDIN_FILENO);
	dup2(data->pipe_fd[1], STDOUT_FILENO);
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	execve(data->path1, data->cmd1, env);
	error("execve", data);
	exit(EXIT_FAILURE);
}
static void	second_child(t_pipex *data, char **argv, char **env)
{
	int fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Error opening output file \n");
		exit(EXIT_FAILURE);
	}
	ft_cmd(data, argv, env);
	dup2(fd, STDOUT_FILENO);
	dup2(data->pipe_fd[0], STDIN_FILENO);
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	execve(data->path2, data->cmd2, env);
	perror("execve");
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv, char **env) 
{
	t_pipex data;

	if (argc == 5)
	{
		if (pipe(data.pipe_fd) == -1)
			perror("error pipe");
		check_files(argv);
		data.pid1 = fork();
		if (data.pid1 == -1)
			perror("error pid");
		if (data.pid1 == 0)
			first_child(&data, argv, env);
		data.pid2 = fork();
		if (data.pid2 == -1)
			perror("error pid");
		if (data.pid2 == 0)
			second_child(&data, argv, env);
		close(data.pipe_fd[0]);
		close(data.pipe_fd[1]);
		waitpid(data.pid1, NULL, 0);
		waitpid(data.pid2, NULL, 0);
	}
	else
		perror("The format is: ./pipex infile cmd cmd outfile\n");
}
