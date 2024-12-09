/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:11:29 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/09 21:46:11 by zslowian         ###   ########.fr       */
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
	printf("Child: Closed read end of the pipe\n");
	ft_get_executable_data(&child, &executable, 1);
	dup2(child->pipe_incoming[0], STDIN_FILENO);
	printf("Child: Redirected read end of the STDIN to infile\n");
	ft_get_input_data(&child);
	dup2(child->pipe_outgoing[1], STDOUT_FILENO);
	printf("Child: Redirected write end of the pipe to STDOUT\n");
	close(child->pipe_outgoing[1]);
	printf("Child: Closed write end of the pipe\n");
	argv = ft_lst_to_arr(child->execve_argv);
	if (!argv)
	{
		free(executable);
		ft_error(&pipex, NULL);
	}
	printf("About to execve: %s\n", executable);
	execve(executable, argv, NULL); //TODO: Find the infinite loop in the beggining of the parent process
	perror("execve failed");
	free(executable);
	ft_clear_char_array(&argv);
	ft_error(&pipex, NULL);
}
//TODO: function has more than 25 lines