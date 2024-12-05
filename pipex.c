/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:13:54 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/05 12:26:30 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_clean_up(t_pipex **pipex);
void	ft_destroy_string(char *str);

int	main(int argc, char *argv[])
{
	t_pipex	*pipex;
	int		c;

	
	if (argc != 5)
		exit(EXIT_FAILURE);
	c = 0;
	pipex = ft_calloc(1, sizeof(t_pipex));
	while(c < argc - 1)
	{
		ft_printf("\"%s\"\n", argv[c + 1]);
		pipex->args[c] = ft_strtrim(argv[c + 1], TRIM_SET); // malloc inside
		c++;
	}
	c = 0;
	while(c < argc - 1)
	{
		ft_printf("\"%s\"\n", pipex->args[c]);
		c++;
	}
	
	/*if (pid == 0)
	{
		ft_printf("I am child - executing first command on input file\n");
	}
	else
	{
		ft_printf("I am parent - executing second command, saving to output\n");
	}*/
	pipex_clean_up(&pipex);
	exit(EXIT_SUCCESS);
}

void	pipex_clean_up(t_pipex **pipex)
{
	int		i;
	char	*arg;

	if ((*pipex)->args[0])
	{
		i = 0;
		while (i < 4)
		{
			arg = (*pipex)->args[i];
			free(arg);
			(*pipex)->args[i] = NULL;
			i++;
		}
	}
	free(*pipex);
	/*if ((*pipex)->pipe[0])
	{
		close(*((*pipex)->pipe[0]));
		close(*((*pipex)->pipe[1]));
		free((*pipex)->pipe[0]);
		free((*pipex)->pipe[1]);
	}*/
}
