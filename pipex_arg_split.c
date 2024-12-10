/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_arg_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 03:53:28 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/10 16:47:47 by zslowian         ###   ########.fr       */
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
	int		i;
	int		start;
	int		word;
	int		len;
	t_process	*process;

	i = 0;
	start = 0;
	word = 0;
	process = *pipex;
	len = ft_strlen(process->args[cmd]);
	while (i <= len)
	{
		if (process->args[cmd][i] == ' ')
		{
			ft_allocate_execve_arg(&pipex, process->args[cmd], start, i - start);
			start = start + (i - start) + 1;
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
	int			j;
	char		*tmp;
	char		*trimmed;
	t_list		*argv;
	t_process	*process;

	j = 0;
	process = **pipex;
	argv = malloc(sizeof(t_list *));
	if (!argv)
		ft_error(pipex, NULL);
	tmp = malloc(sizeof(char) * nb_chars);
	while (nbclose(pipefd[1]);
	if (dup2(filein, 0) == -1)
		error("dup2");
	execute(av[2], envp);_chars > 0)
	{
		tmp[j] = str[start_i];
		start_i++;
		j++;
		nb_chars--;
	}
	tmp[j] = '\0';
	trimmed = ft_strtrim(tmp, TRIM_SET);
	free(tmp);
	argv->content = malloc(sizeof(char) * ft_strlen(trimmed));
	if (!(argv->content))
		ft_error(pipex, NULL);
	ft_strlcpy(argv->content, trimmed, ft_strlen(trimmed));
	free(trimmed);
	ft_lstadd_back(&(process->execve_argv), argv);
}
