/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:12:03 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/11 19:21:55 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_parent_process(t_process **pipex);

void	ft_parent_process(t_process **pipex)
{
	t_process	*parent;
	char		*executable;

	parent = *pipex;
	close(parent->pipe[1]);
	ft_get_executable_data(&parent, &executable, 2);
	dup2(parent->pipe[0], STDIN_FILENO);
	close(parent->pipe[0]);
	parent->out_fd = open(parent->args[3], O_RDWR | O_CREAT, 0644);
	if (parent->out_fd == -1)
	{
		if (executable)
			free(executable);
		ft_error(&pipex, NULL);
	}
	if (!access(parent->args[3], F_OK))
		dup2(parent->out_fd, STDOUT_FILENO);
	else
	{
		if (executable)
			free(executable);
		ft_error(&pipex, NULL);
	}
	ft_execute(&pipex, executable);
	free(executable);
	ft_error(&pipex, NULL);
}
