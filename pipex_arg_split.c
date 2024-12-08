/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_arg_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 03:53:28 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/08 06:09:44 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_allocate_execve_args(char *str, char c, char *result[], int args_nb);
void	ft_allocate_execve_arg(char *str, char **word, int start_i,
			int nb_chars);

void	ft_allocate_execve_args(char *str, char c, char *result[], int args_nb)
{
	int	i;
	int	start;
	int	word;

	i = 0;
	start = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			ft_allocate_execve_arg(str, &result[word], start, i - start);
			start = start + (i - start) + 1;
			word++;
		}
		i++;
	}
	ft_allocate_execve_arg(str, &result[word], start, i - start);
	result[args_nb - 1] = NULL;
}

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
