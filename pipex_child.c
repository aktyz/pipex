/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:11:29 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/08 04:47:20 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(t_pipex **pipex)
{
	t_pipex	*child;
	int		input_fd;
	char	*tmp;
	char	*input;
	char	*line;
	char	*executable;
	int		args_nb;

	child = *pipex;
	close(child->pipe_fd[0]);
	input_fd = open(child->args[0], O_RDONLY | O_CREAT);
	if (input_fd == -1)
		ft_error(&pipex, NULL);
	tmp = NULL;
	input = NULL;
	line = get_next_line(input_fd);
	while (line != NULL)
	{
		tmp = input;
		input = ft_strreplace(tmp, line);
		if (line)
			free(line);
		line = get_next_line(input_fd);
	}
	if (line)
		free(line);
	close(input_fd);
	args_nb = ft_strnchar(child->args[1], ' ') + 1;
	ft_allocate_execve_args(child->args[1], ' ', child->execve_args, args_nb);
	executable = ft_strjoin(PATH_1, child->execve_args[0]);
	if (access(executable, X_OK) == -1)
	{
		free(executable);
		executable = ft_strjoin(PATH_2, child->execve_args[0]);
		if (access(executable, X_OK) == -1)
		{
			free(executable);
			ft_error(&pipex, NULL);
		}
	}
	dup2(child->pipe_fd[1], STDOUT_FILENO);
	close(child->pipe_fd[1]);
	if (input)
		free(input);
	execve(executable, child->execve_args, NULL);
	free(executable);
	ft_error(&pipex, NULL);
}
