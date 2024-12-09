/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:12:03 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/09 21:49:16 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_parent_process(t_pipex **pipex);

void	ft_parent_process(t_pipex **pipex)
{
	t_pipex	*parent;
	int		c;
	char	*line;
	char	*tmp;
	char	*input;
	char	*output;
	char	*executable;
	char	**argv;
	pid_t	child_pid;

	parent = *pipex;
	close(parent->pipe_outgoing[1]);
	printf("Parent: Closed write end of the pipe coming from child\n");
	child_pid = waitpid(parent->child_pid, NULL, 0);// it hangs infinitelly here
	if (child_pid == -1)
		ft_error(&pipex, NULL);
	printf("Parent: Child process terminated\n");
	tmp = NULL;
	input = NULL;
	line = get_next_line(parent->pipe_outgoing[0]);// it hangs infinitelly here
	ft_printf("Input received in parent:\n"); //TODO: Make sure we receive right thing here
	while (line != NULL)
	{
		tmp = input;
		input = ft_strreplace(tmp, line);
		ft_printf("%s\n", input);
		if (line)
			free(line);
		line = get_next_line(parent->pipe_outgoing[0]);
	}
	close(parent->pipe_outgoing[0]); // outgoing array is free to use
	printf("Parent: Closed read end of the pipe coming from the child\n");
	c = pipe(parent->pipe_incoming); // to read from input and redirect to execve
	if (c == -1)
		ft_error(&pipex, NULL);
	dup2(parent->pipe_incoming[1], STDIN_FILENO); // zamiast stdin chcemy czytac z infile
	ft_printf("Input data: %s\n", input);
	write(parent->pipe_incoming[1], input, ft_strlen(input)); //read from input
	close(parent->pipe_incoming[1]);
	ft_get_executable_data(&parent, &executable, 2);
	argv = ft_lst_to_arr(parent->execve_argv);
	if (!argv)
	{
		free(executable);
		ft_error(&pipex, NULL);
	}
	c = open(parent->args[3], O_RDWR | O_CREAT, 0644);
	if (c == -1)
	{
		ft_clear_char_array(&argv);
		free(executable);
		ft_error(&pipex, NULL);
	}
	dup2(c, STDOUT_FILENO);
	ft_clean_up(pipex);
	execve(executable, argv, NULL);
	close(c);
	free(executable);
	ft_clear_char_array(&argv);
	ft_error(&pipex, NULL);
}
