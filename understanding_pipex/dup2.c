/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 06:28:46 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/08 06:31:33 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> // open
#include <unistd.h> // dup2, close
#include <stdio.h> //printf

int	main(void)
{
	int	fd;

	fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	printf("This is printed in example.txt\n");
	return (0);
}
