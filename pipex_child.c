/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:11:29 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/10 18:02:06 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(t_process **pipex)
{
	t_process	*child;	
	char	*executable;
	char	**argv;
	char	**print;

	child = *pipex;
	close(child->pipe[0]);
	//ft_printf("Child: Closed read end of the pipe\n");
	ft_get_executable_data(&child, &executable, 1);
	if (!access(child->args[0], F_OK))
	{
		child->in_fd = open(child->args[0], O_RDONLY);
		if (child->in_fd == -1)
			ft_error(&pipex, NULL);
		//ft_printf("Child: Opened infile fd\n");
		if (child->in_fd == -1)
			ft_error(&pipex, NULL);
		dup2(child->in_fd, STDIN_FILENO);
		//ft_printf("Child: redirected infile to STDIN\n");
		close(child->in_fd);
		//ft_printf("Child: Closed infile fd\n");
	}
	else
		ft_error(&pipex, NULL);
	ft_get_input_from_fd(&child, child->in_fd);
	
	dup2(child->pipe[1], STDOUT_FILENO);
	//ft_printf("Child: redirected STDOUT to pipe\n");
	close(child->pipe[1]);
	//ft_printf("Child: Closed write end of the pipe\n");
	argv = ft_lst_to_arr(child->execve_argv);
	if (!argv)
	{
		free(executable);
		ft_error(&pipex, NULL);
	}
	//ft_printf("Child: Argv table:\n");
	print = argv;
	while (*print)
	{
		//ft_printf("%s\n", *print);
		*print++;
	}
	//ft_printf("Child: input data:\n");
	//ft_printf("%s\n", child->input_data);
	//ft_printf("Child: About to execve: %s\n", executable);
	execve(executable, argv, NULL);
	perror("Child: Execve failed");
	free(executable);
	ft_clear_char_array(&argv);
	ft_error(&pipex, NULL);
}
