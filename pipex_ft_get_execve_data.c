/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_ft_get_execve_data.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 05:58:59 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/09 20:48:57 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * Function parses second argument of the program into separate execve
 * arguments put in an array.
 * 
 * The same array have two additional fields: input data & NULL.
 * Input data is a try.
 * NULL is required in order to execve run smoothly.
 * 
 * This function also tries executable paths to find the right binary.
 *  
 */
void	ft_get_executable_data(t_pipex **pipex, char **executable, int cmd)
{
	t_pipex	*child;

	child = *pipex;
	ft_allocate_execve_argv(&child, cmd);
	*executable = ft_strjoin(PATH_1, child->execve_argv->content);
	if (access(*executable, X_OK) == -1)
	{
		free(*executable);
		*executable = ft_strjoin(PATH_2, child->execve_argv->content);
		if (access(*executable, X_OK) == -1)
		{
			free(*executable);
			ft_error(&pipex, NULL);
		}
	}
}
