/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:12:03 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/14 13:47:23 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_parent_process(t_process **pipex)
{
	t_process	*parent;

	parent = *pipex;
	// Closing pipes on ends we won't need
	close(parent->pipe[1]);
	// Fromatting executable data for execve function
	ft_get_executable_data(&parent, 2);
	// Setting up the STDIN
	dup2(parent->pipe[0], STDIN_FILENO);
	close(parent->pipe[0]);
	// Setting up the STDOUT
	parent->out_fd = open(parent->args[3], O_RDWR | O_CREAT, 0644);
	if (parent->out_fd == -1)
		ft_error(&pipex, NULL);
	if (!access(parent->args[3], F_OK))
		dup2(parent->out_fd, STDOUT_FILENO);
	else
		ft_error(&pipex, NULL);
	// Execution
	ft_execute(&pipex, parent->executable);
	// Error log in case of failure
	ft_error(&pipex, NULL);
}
