/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_ft_lst_to_arr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:03:10 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/09 19:55:50 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_lst_to_arr(t_list *argv)
{
	int		size;
	char	**arr;
	char	**tmp;

	size = ft_lstsize(argv);
	arr = malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (NULL);
	tmp = arr;
	while (argv)
	{
		*tmp = argv->content;
		tmp++;
		argv = argv->next;
	}
	*tmp = NULL;
	return (arr);
}
