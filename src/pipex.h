/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:59:06 by rfleritt          #+#    #+#             */
/*   Updated: 2025/02/15 23:23:57 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
    int		pipe_fd[2];
    pid_t	pid1;
    pid_t	pid2;
    char	**cmd1;
	char	**cmd2;
	char	*path1;
	char	*path2;
}	t_pipex;

void	error(char *str);
void	check_files(char **doc);
void	ft_cmd(t_pipex *pipex, char **argv, char **env);

#endif