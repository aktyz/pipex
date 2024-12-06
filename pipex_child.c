/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:11:29 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/06 19:38:49 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(t_pipex **pipex);

void	ft_child_process(t_pipex **pipex)
{
	t_pipex	*child;
	int		input_fd;
	char	*tmp;
	char	*input;
	char	*line;

	child = *pipex;
	input_fd = open(child->args[0], O_RDONLY | O_CREAT);
	if (input_fd == -1)
		ft_error(&pipex);
	tmp = NULL;
	input = NULL;
	line = get_next_line(input_fd);
	close(child->pipe_fd[0]);
	while (!(line == NULL))
	{
		ft_printf("%s\n", line);
		tmp = input;
		input = ft_strjoin(tmp, line);
		free(tmp);
		line = get_next_line(input_fd);
	}
	close(input_fd);
	// execute the first command on input data
	ft_printf("\"%s\"\n", input);
	// write to fd
	write(child->pipe_fd[1], "Hello parent!\n", 13);
	close(child->pipe_fd[1]);
	//if (input)
	//	free(input);
}
