/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_arg_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 03:53:28 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/09 16:08:28 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_allocate_execve_argv(t_pipex **pipex);
void	ft_allocate_execve_arg(t_pipex **pipex, char *str, int start_i,
			int nb_chars);

/**
 * Function is a parser of the second argument of the program. It split this
 * argument by space character and allocates command members in a list
 * in pipex structure
 *
 */
void	ft_allocate_execve_argv(t_pipex **pipex)
{
	int		i;
	int		start;
	int		word;
	int		len;
	t_pipex	*child;

	i = 0;
	start = 0;
	word = 0;
	child = *pipex;
	len = ft_strlen(child->args[1]);
	while (i <= len)
	{
		if (child->args[1][i] == ' ')
		{
			ft_allocate_execve_arg(&child, child->args[1], start, i - start);
			start = start + (i - start) + 1;
		}
		i++;
	}
	ft_allocate_execve_arg(&child, child->args[1], start, i - start);
}

/**
 * Function allocates memory for each of the execve arguments t_list
 * and copies the correct part of the program second argument
 * there.
 *
 */
void	ft_allocate_execve_arg(t_pipex **pipex, char *str, int start_i,
			int nb_chars)
{
	int		i;
	int		j;
	char	*tmp;
	t_list	*argv;
	t_pipex	*child;

	i = start_i;
	j = 0;
	child = *pipex;
	argv = malloc(sizeof(t_list *));
	if (!argv)
		ft_error(&pipex, NULL);
	argv->content = malloc(sizeof(char) * (nb_chars + 1));
	if (!(argv->content))
		ft_error(&pipex, NULL);
	tmp = argv->content;
	while (nb_chars > 0)
	{
		tmp[j] = str[i];
		i++;
		j++;
		nb_chars--;
	}
	tmp[j] = '\0';
	ft_lstadd_back(&(child->execve_argv), argv);
}
