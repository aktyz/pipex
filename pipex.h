/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:15:23 by zslowian          #+#    #+#             */
/*   Updated: 2024/12/14 15:43:36 by zslowian         ###   ########.fr       */
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

typedef struct s_executable
{
	char	*path;
	int		execve_argc;
	t_list	*execve_argv;
}	t_executable;

typedef struct s_process
{
	char			*args[4];
	int				pipe_parent[2];
	int				pipe_send; // bool
	int				pipe_receive; // bool
	int				in_file_fd;
	char			*input_data;
	int				out_file_fd;
	char			*output_data;
	int				child_pid;
	t_executable	*executable;
}	t_process;



void	ft_process(t_process **pipex, int cmd);

void	ft_error(t_process ***pipex, char **string);
void	ft_clean_up(t_process **pipex);

void	ft_get_input_from_fd(t_process **pipex, int fd);

void	ft_get_executable_data(t_process **pipex, int cmd);
void	ft_allocate_execve_argv(t_process **pipex, int cmd);
void	ft_allocate_execve_arg(t_process ***pipex, char *str, int start_i,
			int nb_chars);
void	ft_execute(t_process ***pipex);

char	**ft_lst_to_arr(t_list *argv);
void	ft_delete_lst_node(t_list *node);
void	ft_delete_lst(t_list **node, int size);

#endif