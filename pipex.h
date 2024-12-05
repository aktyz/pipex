/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:15:23 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/05 15:29:58 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <errno.h>  // errno
# include <stdio.h>  // perror()
# include <stdlib.h> // exit()
# include <string.h> // strerror()
# include <unistd.h> // pipe() fork()
# include <sys/wait.h> //

# define TRIM_SET " \t\n"

# define PATH_1 "/bin/"
# define PATH_2 "/usr/bin/"

typedef struct s_pipex
{
	char	*args[4]; //we will store our trimmed args here
	int		pipe_fd[2]; //we will store our pipe here
	int		child_pid; //pid of the parent
}	t_pipex;

void	ft_child_process(t_pipex **pipex);
void	ft_parent_process(t_pipex **pipex);

#endif