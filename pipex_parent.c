/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:12:03 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/10 16:42:39 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_parent_process(t_process **pipex);

void	ft_parent_process(t_process **pipex)
{
	t_process	*parent;
	char	*executable;
	char	**argv;
	char	**print;
	pid_t	child_pid;
	int		loc;

	parent = *pipex;
	ft_get_executable_data(&parent, &executable, 2);
	wait(NULL);
	//child_pid = waitpid(parent->child_pid, NULL, 0);
	//if (child_pid == -1)
	//	ft_error(&pipex, NULL);
	ft_printf("Parent: Child process terminated\n");
	close(parent->pipe[1]);
	ft_printf("Parent: Closed write end of the pipe\n");
	ft_get_input_from_fd(&parent, parent->pipe[0]);
	ft_printf("Input received in parent:\n");
	close(parent->pipe[0]);
	ft_printf("Parent: Closed read end of the pipe\n");
	//parent->out_fd = open(parent->args[3], O_RDWR | O_CREAT, 0644);
	//if (parent->out_fd == -1)
		//ft_error(&pipex, NULL);
		//ft_printf("Parent: Opened outfile fd\n");
	//if (!access(parent->args[3], F_OK))
	//{
		//ft_printf("Parent: About to redirect STDOUT to outfile\n");
		//dup2(parent->out_fd, STDOUT_FILENO); // DEBUGGING: switch off
	//}
	argv = ft_lst_to_arr(parent->execve_argv);
	if (!argv)
	{
		free(executable);
		ft_error(&pipex, NULL);
	}

	ft_printf("Parent: About to execve: %s\n", executable);
	ft_printf("Parent: Argv table:\n");
	print = argv;
	while (*print)
	{
		ft_printf("%s\n", *print);
		*print++;
	}
	ft_printf("Parent: input data:\n");
	ft_printf("%s\n", parent->input_data);
	execve(executable, argv, NULL);


	perror("Parent: Execve failed");
	free(executable);
	ft_clear_char_array(&argv);
	ft_error(&pipex, NULL);
}
