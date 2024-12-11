/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_ft_lst_to_arr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:03:10 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/11 14:17:22 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_lst_to_arr(t_list *argv)
{
	int		size;
	char	**arr;
	char	**tmp;

	size = ft_lstsize(argv) + 1;
	arr = malloc(sizeof(char *) * size);
	if (!arr)
		return (NULL);
	tmp = arr;
	while (size > 1)
	{
		*tmp = argv->content;
		argv = argv->next;
		tmp++;
		size--;
	}
	*tmp = NULL;
	return (arr);
}
