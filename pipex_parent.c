/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:12:03 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/05 15:37:21 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_parent_process(t_pipex **pipex);

void	ft_parent_process(t_pipex **pipex)
{
	t_pipex	*parent;
	char	buf[13];

	parent = *pipex;
	wait(&parent->child_pid);
	close(parent->pipe_fd[1]);
	read(parent->pipe_fd[0], buf, 13);
	close(parent->pipe_fd[0]);
	ft_printf("I am parent - executing second command, saving to output\n");
	ft_printf("Message from my child: \"%s\"\n", buf);
}
