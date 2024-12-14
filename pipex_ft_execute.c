/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_ft_execute.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:26:04 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/14 15:20:18 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execute(t_process ***pipex)
{
	t_process	*process;
	char		**argv;

	process = **pipex;
	argv = ft_lst_to_arr(process->executable->execve_argv);
	if (!argv)
	{
		free(process->executable->path);
		ft_error(pipex, NULL);
	}
	execve(process->executable->path, argv, NULL);
	ft_clear_char_array(&argv, process->executable->execve_argc);
}
