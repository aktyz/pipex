/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:11:29 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/08 06:08:38 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(t_pipex **pipex)
{
	t_pipex	*child;	
	char	*input;
	char	*executable;

	child = *pipex;
	close(child->pipe_fd[0]);
	ft_get_input_data(&child);
	ft_get_executable_data(&child, &executable);
	dup2(child->pipe_fd[1], STDOUT_FILENO);
	close(child->pipe_fd[1]);
	if (input)
		free(input);
	execve(executable, child->execve_args, NULL);
	free(executable);
	ft_error(&pipex, NULL);
}
