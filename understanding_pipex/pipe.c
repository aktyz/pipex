/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 06:29:09 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/09 16:18:35 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // printf perror
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> // pid_t

void	ft_child(int **a);
void	ft_parent(int **a);

int	main(void)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		ft_child(&fd);
	else
		ft_parent(&fd);
}

void	ft_child(int **a)
{
	int	*fd;

	fd = *a;
	close(fd[0]);
	write(fd[1], "Hello parent!", 13);
	close(fd[1]);
	exit(EXIT_SUCCESS);
}

void	ft_parent(int **a)
{
	int		*fd;
	char	buf[13];

	fd = *a;
	close(fd[1]);
	read(fd[0], buf, 13);
	close(fd[0]);
	ft_printf("Message from my child: \"%s\"\n", buf);
	exit(EXIT_SUCCESS);
}
