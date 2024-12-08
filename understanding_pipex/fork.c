/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 06:29:02 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/08 06:30:15 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h> // pid_t
#include <stdio.h> // perror() printf()
#include <stdlib.h> // exit()
#include <unistd.h> // fork()
#include <sys/wait.h> // wait()

int	main(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		printf("This is the child process, pid: %d\n", pid);
	else
	{
		wait(0);
		printf("This is the parent process, pid: %d\n", pid);
	}
	return (0);
}
