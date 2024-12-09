/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 06:29:19 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/09 16:18:43 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // printf perror
#include <unistd.h> // unlink
#include <stdlib.h> // exit
#include <errno.h> // errno
#include <string.h> // library

int	main(void)
{
	int	result;

	result = unlink("example.txt");
	if (result == 0)
		ft_printf("File successfully deleted\n");
	else
		ft_printf("Error when deleting the file: %s\n", strerror(errno));
	exit(EXIT_SUCCESS);
}
