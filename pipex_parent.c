/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:12:03 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/10 18:16:53 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_parent_process(t_process **pipex);

void	ft_parent_process(t_process **pipex)
{
	t_process	*parent;
	char		*executable;
	char		**argv;

	parent = *pipex;
	ft_get_executable_data(&parent, &executable, 2);
	wait(NULL);//TODO: check if it still works with this out?
	close(parent->pipe[1]);
	dup2(parent->pipe[0], STDIN_FILENO);
	close(parent->pipe[0]);
	parent->out_fd = open(parent->args[3], O_RDWR | O_CREAT, 0644);
	if (parent->out_fd == -1)
		ft_error(&pipex, NULL);
	if (!access(parent->args[3], F_OK))
		dup2(parent->out_fd, STDOUT_FILENO);
	argv = ft_lst_to_arr(parent->execve_argv);
	if (!argv)
	{
		free(executable);
		ft_error(&pipex, NULL);
	}
	execve(executable, argv, NULL);
	perror("Parent: Execve failed");
	free(executable);
	ft_clear_char_array(&argv);
	ft_error(&pipex, NULL);
}
//Function has more than 25 lines