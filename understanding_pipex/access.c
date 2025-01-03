/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 06:28:36 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/09 16:17:43 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf
#include <unistd.h> //access

int	main(void)
{
	if (!access("example.txt", F_OK))
		ft_printf("File exist\n");
	else
		ft_printf("File doesn't exist\n");
	return (0);
}
