/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_ft_get_input_data.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 05:53:41 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/08 09:41:51 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * Function reads data from provided input source and stores it
 * in before last place in execve_argv array.
 *
 */
void	ft_get_input_data(t_pipex **pipex)
{
	int		fd;
	char	*tmp;
	char	*line;
	t_pipex	*child;

	child = *pipex;
	fd = open(child->args[0], O_RDONLY | O_CREAT);
	if (fd == -1)
		ft_error(&pipex, NULL);
	tmp = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp = child->execve_argv[child->execve_argc - 2];
		child->execve_argv[child->execve_argc - 2] = ft_strreplace(tmp, line);
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
}
