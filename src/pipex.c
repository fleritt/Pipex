/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:16:54 by rfleritt          #+#    #+#             */
/*   Updated: 2025/02/15 23:23:21 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	p_child(char **argv, char **env, int *pipe_fd)
{
	
}
void	p_parent(char **argv, char **env, int *pipe_fd)
{
	
}

int main(int argc, char **argv, char **env) 
{
    pid_t	pid;
	int		pipe_fd[2];

	if (argc == 5)
	{
		if (pipe(pipe_fd) == -1)
			error("error pipe");
		pid = fork();
		if (pid == -1)
			error("error pid");
		if (pid == 0)
			p_child(argv, env, pipe_fd);
		p_parent(argv, env, pipe_fd);
	}
	else
		error("The format is: ./pipex infile cmd cmd outfile\n");
	return(0);
}
