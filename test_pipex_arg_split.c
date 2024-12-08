/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pipex_arg_split.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 03:53:17 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/08 04:02:16 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <string.h>

void	test_ft_allocate_execve_arg(void)
{
	char	*str;
	char	**ptr;
	char	**tmp;
	int		i;

	ptr = NULL;
	ptr = malloc(4 * sizeof(char *));
	i = 0;
	tmp = ptr;
	str = malloc(14 * sizeof(char));
	strncpy(str, "ls -la file A", 13);
	ft_allocate_execve_arg(str, tmp, 0, 2);
	tmp++;
	ft_allocate_execve_arg(str, tmp, 3, 3);
	tmp++;
	ft_allocate_execve_arg(str, tmp, 7, 4);
	tmp++;
	ft_allocate_execve_arg(str, tmp, 12, 1);
	tmp = ptr;
	while (ptr[i]) //Invalid read of size 8
	{
		if (ptr[i])
			free(ptr[i]);
		i++;
	}
	if (ptr)
		free(ptr);
	if (str)
		free(str);
}
