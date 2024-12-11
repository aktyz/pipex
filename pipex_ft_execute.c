/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_ft_execute.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:26:04 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/11 13:33:47 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execute(t_process ***pipex, char	*executable)
{
	t_process	*process;
	char		**argv;

	process = **pipex;
	argv = ft_lst_to_arr(process->execve_argv);
	if (!argv)
	{
		free(executable);
		ft_error(pipex, NULL);
	}
	execve(executable, argv, NULL);
	ft_clear_char_array(&argv);
}
