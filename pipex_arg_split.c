/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_arg_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 03:53:28 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/08 09:55:31 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_allocate_execve_argv(t_pipex **pipex);
void	ft_allocate_execve_arg(char *str, char **word, int start_i,
			int nb_chars);

/**
 * Function is a parser of the second argument of the program. It split this
 * argument by space character and allocates a separate array place for each
 * of the bash cmd flags.
 * 
 * It also sets two last elements of execve_argv array to NULL.
 * 
 * At the exit of this function t_pipex structure in its execve_argv array should
 * have:
 * positions 0 to n - 3 - arguments of the execve program to triger
 * position n - 2 - NULL so that the subsequent function can place input data
 * 					there
 * position n - 1 - NULL so that the array is correct as per execve function
 * requirements
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
			ft_allocate_execve_arg(child->args[1], &child->execve_argv[word],
				start, i - start);
			start = start + (i - start) + 1;
			word++;
		}
		i++;
	}
	ft_allocate_execve_arg(child->args[1], &child->execve_argv[word],
		start, i - start);
	child->execve_argv[child->execve_argc - 2] = NULL; // input data field
	child->execve_argv[child->execve_argc - 1] = NULL; // requirement
}
// more than 25 lines

/**
 * Function allocates memory for each of the argv array and copies
 * the correct part of the program second argument there.
 * 
 */
void	ft_allocate_execve_arg(char *str, char **word, int start_i,
		int nb_chars)
{
	int		i;
	int		j;
	char	*my_word;

	i = start_i;
	j = 0;
	*word = malloc((nb_chars + 1) * sizeof(char));
	my_word = *word;
	while (nb_chars > 0)
	{
		my_word[j] = str[i];
		i++;
		j++;
		nb_chars--;
	}
	my_word[j] = '\0';
}
