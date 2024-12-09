/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_ft_get_input_data.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 05:53:41 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/09 14:32:42 by zslowian         ###   ########.fr       */
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
	t_pipex	*child;

	child = *pipex;
	//TODO: check for the existance of the file
	fd = open(child->args[0], O_RDONLY | O_CREAT);
	if (fd == -1)
		ft_error(&pipex, NULL);
	tmp = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp = child->input_data;
		child->input_data = ft_strreplace(tmp, line);
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
}
