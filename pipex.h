/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:15:23 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/09 20:19:45 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <errno.h>  // errno
# include <fcntl.h> // O_RDONLY, O_CREAT
# include <stdio.h>  // perror()
# include <stdlib.h> // exit()
# include <string.h> // strerror()
# include <unistd.h> // pipe() fork()
# include <sys/stat.h> // open()
# include <sys/wait.h> //

# define TRIM_SET " \t\n"

# ifndef PIPEX_BUFF
#  define PIPEX_BUFF 50
# endif

# define PATH_1 "/bin/"
# define PATH_2 "/usr/bin/"

typedef struct s_pipex
{
	char	*args[4];
	int		pipe_incoming[2];
	int		pipe_outgoing[2];
	int		child_pid;
	char	*output_data;
	t_list	*execve_argv;
}	t_pipex;

void	ft_child_process(t_pipex **pipex);
void	ft_parent_process(t_pipex **pipex);

void	ft_error(t_pipex ***pipex, char **string);
void	ft_clean_up(t_pipex **pipex);

void	ft_get_input_data(t_pipex **pipex);

void	ft_get_executable_data(t_pipex **pipex, char **executable, int cmd);
void	ft_allocate_execve_argv(t_pipex **pipex, int cmd);
void	ft_allocate_execve_arg(t_pipex ***pipex, char *str, int start_i,
			int nb_chars);

char	**ft_lst_to_arr(t_list *argv);

// TESTS
void	test_pipex(void);
void	test_ft_allocate_execve_arg(void);

#endif