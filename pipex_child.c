/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:11:29 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/05 15:37:04 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(t_pipex **pipex);

void	ft_child_process(t_pipex **pipex)
{
	t_pipex	*child;

	child = *pipex;
	ft_printf("I am child - executing first command on input file\n");
	close(child->pipe_fd[0]);
	write(child->pipe_fd[1], "Hello parent!\n", 13);
	close(child->pipe_fd[1]);
}
