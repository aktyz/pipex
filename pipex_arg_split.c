/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_arg_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 03:53:28 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/14 15:21:49 by zslowian         ###   ########.fr       */
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
	process->executable->execve_argc = 0;
	len = ft_strlen(process->args[cmd]);
	while (i <= len)
	{
		if (process->args[cmd][i] == ' ')
		{
			ft_allocate_execve_arg(&pipex, process->args[cmd], start,
				i - start);
			start = start + (i - start) + 1;
			(process->executable->execve_argc)++;
		}
		i++;
	}
	ft_allocate_execve_arg(&pipex, process->args[cmd], start, i - start);
	(process->executable->execve_argc)++;
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
	t_process	*process;
	t_list		*node;

	process = **pipex;
	node = malloc(sizeof(t_list));
	node->content = malloc(sizeof(char) * (nb_chars + 1));
	ft_strlcpy(node->content, &str[start_i], nb_chars);
	node->next = 0;
	node->lst_size = 1;
	ft_lstadd_back(&(process->executable->execve_argv), node);
}
