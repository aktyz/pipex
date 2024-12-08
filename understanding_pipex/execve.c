/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 06:28:54 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/08 06:30:48 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // execve
#include <stdio.h> // printf
#include <errno.h> // errno
#include <string.h> // strerror()

int	main(void)
{
	char	*args[3];
	int		result;

	args[0] = "ls";
	args[1] = "-la";
	args[2] = (char *) NULL;
	result = execve("/bin/ls", args, NULL);
	if (result == -1)
	{
		result = execve("/usr/bin/ls", args, NULL);
		if (result == -1)
			printf("execve failed: %s\n", strerror(errno));
	}
	printf("This will not be executed\n");
	return (0);
}
