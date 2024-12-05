/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:15:23 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/05 12:52:33 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "libft.h"
#include <stdlib.h> // exit()
#include <unistd.h> // pipe() fork()

# define TRIM_SET " \t\n"

typedef struct s_pipex
{
	char	*args[4]; //we will store our trimmed args here
	int		pipe_fd[2]; //we will store our pipe here
	long	child_pid; //pid of the parent
} t_pipex;


#endif