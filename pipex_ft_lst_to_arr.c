/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_ft_lst_to_arr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:03:10 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/09 16:15:15 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_lst_to_arr(t_list *argv)
{
	int		size;
	char	**arr;
	char	**tmp;

	size = ft_lstsize(argv);
	arr = malloc(sizeof(char *) * size);
	if (!arr)
		return (NULL);
	tmp = arr;
	while (argv)
	{
		*tmp = argv->content;
		tmp++; //TODO: check if you iterate the write level of pointer
		argv = argv->next;
	}
	//TODO: add one more array cell with NULL in it
	return (arr);
}
