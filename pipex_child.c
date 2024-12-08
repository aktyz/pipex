/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:11:29 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/08 09:53:47 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(t_pipex **pipex)
{
	t_pipex	*child;	
	char	*executable;
	int		nb;
	int		i;

	child = *pipex;
	close(child->pipe_fd[0]);
	child->execve_argc = ft_strnchar(child->args[1], ' ') + 3;
	ft_get_executable_data(&child, &executable);
	ft_get_input_data(&child); // here we get with child->args[0] is NULL <- error we overwrote it somewhere
	dup2(child->pipe_fd[1], STDOUT_FILENO);
	close(child->pipe_fd[1]);
	i = 0;
	while (child->execve_argv[i])
	{
		ft_printf("\"%s\"", child->execve_argv[i]);
		i++;
	}
	execve(executable, child->execve_argv, NULL);
	free(executable);
	ft_error(&pipex, NULL);
}
