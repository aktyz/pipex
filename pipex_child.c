/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:11:29 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/09 16:19:07 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(t_pipex **pipex)
{
	t_pipex	*child;	
	char	*executable;
	int		nb;
	int		i;
	char	**argv;

	child = *pipex;
	close(child->pipe_outgoing[0]);
	child->execve_argc = ft_strnchar(child->args[1], ' ') + 1;
	ft_get_executable_data(&child, &executable);
	ft_get_input_data(&child);
	dup2(child->pipe_outgoing[1], STDOUT_FILENO);
	close(child->pipe_outgoing[1]);
	while (child->execve_argv) //TODO: still doen't print - do we pass the arguments correctly?
	{
		ft_printf("\"%s\"", child->execve_argv->content);
		child->execve_argv = child->execve_argv->next;
	}
	argv = ft_lst_to_arr(child->execve_argv);
	if (!argv)
	{
		free(executable);
		ft_error(&pipex, NULL);		
	}
	ft_clean_up(pipex);
	execve(executable, argv, NULL);
	free(executable);
	ft_error(&pipex, NULL);
}
