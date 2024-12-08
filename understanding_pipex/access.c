/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 06:28:36 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/08 06:30:15 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf
#include <unistd.h> //access

int	main(void)
{
	if (!access("example.txt", F_OK))
		printf("File exist\n");
	else
		printf("File doesn't exist\n");
	return (0);
}
