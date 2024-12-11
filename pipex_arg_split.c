/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_arg_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 03:53:28 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/11 18:53:08 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_allocate_execve_argv(t_process **pipex, int cmd);
void	ft_allocate_execve_arg(t_process ***pipex, char *str, int start_i,
			int nb_chars);

/**
 * Function is a parser of the second argument of the program. It split this
 * argument by space character and allocates command members in a list
 * in pipex structure
 *
 */
void	ft_allocate_execve_argv(t_process **pipex, int cmd)
{
	int			i;
	int			start;
	int			len;
	t_process	*process;

	i = 0;
	start = 0;
	process = *pipex;
	process->execve_argc = 0;
	len = ft_strlen(process->args[cmd]);
	while (i <= len)
	{
		if (process->args[cmd][i] == ' ')
		{
			ft_allocate_execve_arg(&pipex, process->args[cmd], start,
				i - start);
			start = start + (i - start) + 1;
			(process->execve_argc)++;
		}
		i++;
	}
	ft_allocate_execve_arg(&pipex, process->args[cmd], start, i - start);
}

/**
 * Function allocates memory for each of the execve arguments t_list
 * and copies the correct part of the program second argument
 * there.
 *
 */
void	ft_allocate_execve_arg(t_process ***pipex, char *str, int start_i,
			int nb_chars)
{
	char		*tmp;
	char		*trimmed;
	t_process	*process;

	process = **pipex;
	tmp = malloc(sizeof(char) * (nb_chars + 1));
	ft_strlcpy(tmp, &str[start_i], nb_chars);
	trimmed = ft_strtrim(tmp, TRIM_SET);
	ft_lstadd_back(&(process->execve_argv), ft_lstnew(trimmed));
	free(tmp);
}
