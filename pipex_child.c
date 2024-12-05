/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:11:29 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/05 17:01:21 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(t_pipex **pipex);

void	ft_child_process(t_pipex **pipex)
{
	t_pipex	*child;
	int		input_fd;
	char	*input;
	char	*output;
	char	*line;

	child = *pipex;
	close(child->pipe_fd[0]);
	ft_printf("I am child - executing first command on input file\n");
	input_fd = open(child->args[0], O_RDONLY | O_CREAT);
	if (input_fd == -1)
		ft_error(&pipex);
	line = get_next_line(input_fd);
	while (!(line == NULL))
	{
		ft_printf("%s\n", line);
		output = ft_strjoin(output, line);
		line = get_next_line(input_fd);
	}
	close(input_fd);
	// execute the first command on input data
	
	// write to fd
	write(child->pipe_fd[1], "Hello parent!\n", 13);
	close(child->pipe_fd[1]);
	if (input)
		free(input);
}
