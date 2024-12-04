/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:13:54 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/04 17:53:20 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	exit(EXIT_SUCCESS);
}
