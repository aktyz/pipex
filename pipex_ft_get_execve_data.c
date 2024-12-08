/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_ft_get_execve_data.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 05:58:59 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/08 06:05:13 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_get_executable_data(t_pipex **pipex, char **executable)
{
	t_pipex	*child;
	int		args_nb;

	child = *pipex;
	args_nb = ft_strnchar(child->args[1], ' ') + 1;
	ft_allocate_execve_args(child->args[1], ' ', child->execve_args, args_nb);
	*executable = ft_strjoin(PATH_1, child->execve_args[0]);
	if (access(*executable, X_OK) == -1)
	{
		free(*executable);
		*executable = ft_strjoin(PATH_2, child->execve_args[0]);
		if (access(*executable, X_OK) == -1)
		{
			free(*executable);
			ft_error(&pipex, NULL);
		}
	}
}
