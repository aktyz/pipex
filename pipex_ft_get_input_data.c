/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_ft_get_input_data.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 05:53:41 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/09 20:03:14 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * Function reads data from provided input source and stores it
 * in input_data.
 *
 */
void	ft_get_input_data(t_pipex **pipex)
{
	int		fd;
	char	*tmp;
	char	*line;
	char	*input;
	t_pipex	*child;

	child = *pipex;
	if (access(child->args[0], F_OK))
		return ;
	fd = open(child->args[0], O_RDONLY);
	if (fd == -1)
		ft_error(&pipex, NULL);
	tmp = NULL;
	input = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp = input;
		input = ft_strreplace(tmp, line);
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	write(child->pipe_incoming[1], input, ft_strlen(input));
	if (line)
		free(line);
	close(child->pipe_incoming[1]);
	close(child->pipe_incoming[0]);
	close(fd);
}
