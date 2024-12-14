/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:11:29 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/14 13:46:38 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(t_process **pipex)
{
	t_process	*child;	

	child = *pipex;
	// Closing pipes on ends we won't need
	close(child->pipe[0]);
	// Fromatting executable data for execve function
	ft_get_executable_data(&child, 1);
	// Setting up the STDIN
	if (!access(child->args[0], F_OK))
	{
		child->in_fd = open(child->args[0], O_RDONLY);
		if (child->in_fd == -1)
			ft_error(&pipex, NULL);
		dup2(child->in_fd, STDIN_FILENO);
		close(child->in_fd);
	}
	else
		ft_error(&pipex, NULL);
	// Setting up the STDOUT
	dup2(child->pipe[1], STDOUT_FILENO);
	close(child->pipe[1]);
	// Execution
	ft_execute(&pipex, child->executable);
	// Error log in case of failure
	ft_error(&pipex, NULL);
}
