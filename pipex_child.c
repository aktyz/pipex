/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:11:29 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/11 13:30:01 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(t_process **pipex)
{
	t_process	*child;	
	char		*executable;

	child = *pipex;
	close(child->pipe[0]);
	ft_get_executable_data(&child, &executable, 1);
	if (!access(child->args[0], F_OK))
	{
		child->in_fd = open(child->args[0], O_RDONLY);
		if (child->in_fd == -1)
			ft_error(&pipex, NULL);
		if (child->in_fd == -1)
			ft_error(&pipex, NULL);
		dup2(child->in_fd, STDIN_FILENO);
		close(child->in_fd);
	}
	else
		ft_error(&pipex, NULL);
	dup2(child->pipe[1], STDOUT_FILENO);
	close(child->pipe[1]);
	ft_execute(&pipex, executable);
	free(executable);
	ft_error(&pipex, NULL);
}
